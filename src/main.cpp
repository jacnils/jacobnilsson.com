#include <iostream>
#include <utility>
#include <algorithm>
#include <functional>
#include <Endpoint.hpp>
#include <Sites.hpp>
#include <Stylesheets.hpp>
#include <Scripts.hpp>
#include <Templates.hpp>
#include <bygg/bygg.hpp>

static const std::vector<std::string> skip_list{
    {"/img/logo.png"},
};

// Files to copy from the source directory to the output directory
// Also works with files located in the parent directory
static const std::vector<std::pair<std::string, std::string>> copy_files{
    {"fonts/SiteFont.ttf", "out/fonts/SiteFont.ttf"},
    {"fonts/SiteFontBold.ttf", "out/fonts/SiteFontBold.ttf"},
    {"img/github-black.svg", "out/img/github-black.svg"},
    {"img/github-white.svg", "out/img/github-white.svg"},
    {"img/youtube.svg", "out/img/youtube.svg"},
    {"img/mail.svg", "out/img/mail.svg"},
    {"img/logo.png", "out/img/logo.png"},
    {"img/favicon.ico", "out/img/favicon.ico"},
};

// CSS files to generate from bygg::CSS::Stylesheet
static const std::vector<std::tuple<std::string, bygg::CSS::Stylesheet>> css_files{
    {"out/css/style.css", Stylesheets::get_style()},
};

// JavaScript files to generate
// Note: May also be used to write strings to files
static const std::vector<std::tuple<std::string, std::string>> js_files{
    {"out/js/script.js", Scripts::get_script()},
};

// Website tree to generate
// Tuple format: {output file, HTML section, page properties, generate header/footer}
static const std::vector<std::tuple<std::string, bygg::HTML::Section, PageProperties, bool>> website_tree{
    {"out/index.html", Sites::get_index_site(), PageProperties{.lang = "en"}, true},
    {"out/settings.html", Sites::get_settings_site(), PageProperties{.lang = "en"}, true},
    {"out/blog.html", Sites::get_blog_site(), PageProperties{.lang = "en"}, true},
    {"out/blog/macos-passwords-app-crash-bug.html", Sites::get_macos_passwords_app_crash_bug(), PageProperties{.lang = "en"}, true},
    {"out/blog/the-sad-state-of-music-hoarding-on-ios.html", Sites::get_the_sad_state_of_music_hoarding_on_ios(), PageProperties{.lang = "en"}, true},
    {"out/blog/reassigning-your-email-the-hidden-vulnerability.html", Sites::get_reassigning_your_email_the_hidden_vulnerability(), PageProperties{.lang = "en"}, true},
    {"out/bygg.html", Sites::get_bygg_site(), PageProperties{.lang = "en"}, true},
};

// Main function; calls the generation functions
int main(int argc, char** argv) {
    for (const auto& it : copy_files) {
        std::string first = it.first;
        std::string second = it.second;

        if (!std::filesystem::exists(first)) {
            // try ../
            first = "../" + first; // NOLINT

            if (!std::filesystem::exists(first)) {
                throw std::runtime_error("Failed to find file: " + first);
            }
        }

        if (!std::filesystem::exists(std::filesystem::path(second).parent_path())) {
            std::filesystem::create_directories(std::filesystem::path(second).parent_path());

            if (!std::filesystem::exists(std::filesystem::path(second).parent_path())) {
                throw std::runtime_error("Failed to create directory: " + std::filesystem::path(second).parent_path().string());
            }
        }

        std::error_code ec;
        std::filesystem::copy(first, second, std::filesystem::copy_options::overwrite_existing, ec);

        if (ec) {
            throw std::runtime_error("Failed to copy file: " + first + " to " + second + " - " + ec.message()); // NOLINT
        }
    }
    for (const auto& it : website_tree) {
        Endpoint endpoint(std::get<0>(it));

        bygg::HTML::Section root{bygg::HTML::Tag::Html, bygg::HTML::make_properties(bygg::HTML::Property{"lang", std::get<2>(it).lang})};

        if (!std::get<3>(it)) {
            endpoint.open();
            endpoint.append_string(bygg::HTML::Document(std::get<1>(it)).get<std::string>(bygg::HTML::Formatting::None));
            endpoint.close();
            continue;
        }

        const auto trim_n = [](const std::string& str, const size_t n) -> std::string {
            if (str.length() > n) {
                return str.substr(0, n - 3) + "...";
            }
            return str;
        };

        const auto cleanup_indentation = [](const std::string& str) -> std::string {
            std::string ret{str};

            // also remove tabs and newlines
            ret.erase(std::remove(ret.begin(), ret.end(), '\n'), ret.end());
            ret.erase(std::remove(ret.begin(), ret.end(), '\t'), ret.end());

            // remove multiple spaces and ensure the first element and last element are not spaces
            ret.erase(std::unique(ret.begin(), ret.end(), [](char a, char b) { return a == ' ' && b == ' '; }), ret.end());
            if (!ret.empty() && ret.front() == ' ') {
                ret.erase(ret.begin());
            }
            if (!ret.empty() && ret.back() == ' ') {
                ret.pop_back();
            }
            return ret;
        };

        const auto remove_tags = [](const std::string& str) -> std::string {
            std::string ret;
            bool in_tag{false};
            for (const auto& it : str) {
                if (it == '<') {
                    in_tag = true;
                } else if (it == '>') {
                    in_tag = false;
                } else if (!in_tag) {
                    ret += it;
                }
            }

            return ret;
        };

        const auto page = std::get<1>(it);

        std::string title{std::get<2>(it).name};
        std::string description{std::get<2>(it).description};
        std::string image{std::get<2>(it).image};

        std::function<void(const bygg::HTML::Section&, std::string&)> extract_description = [&cleanup_indentation, &trim_n, &extract_description](const auto& section, std::string& description) {
            for (const auto& _it : section) {
                if (std::holds_alternative<bygg::HTML::Element>(_it) && description.empty()) {
                    const auto& element = std::get<bygg::HTML::Element>(_it);
                    if (element.get_tag() == "p") {
                        description = trim_n(cleanup_indentation(element.get_data()), 300);
                        return;
                    }
                } else if (std::holds_alternative<bygg::HTML::Section>(_it) && description.empty()) {
                    extract_description(std::get<bygg::HTML::Section>(_it), description);
                }
            }
        };

        std::function<void(const bygg::HTML::Section&, std::string&)> extract_title = [&trim_n, &extract_title](const auto& section, std::string& title) {
            for (const auto& _it : section) {
                if (std::holds_alternative<bygg::HTML::Element>(_it) && title.empty()) {
                    const auto& element = std::get<bygg::HTML::Element>(_it);
                    if (element.get_tag() == "h1") {
                        title = trim_n(element.get_data(), 50);
                        return;
                    }
                } else if (std::holds_alternative<bygg::HTML::Section>(_it) && title.empty()) {
                    extract_title(std::get<bygg::HTML::Section>(_it), title);
                }
            }
        };

        std::function<void(const bygg::HTML::Section&, std::string&)> extract_image = [&extract_image](const auto& section, std::string& image) {
            for (const auto& _it : section) {
                if (std::holds_alternative<bygg::HTML::Element>(_it) && image.empty()) {
                    const auto& element = std::get<bygg::HTML::Element>(_it);
                    if (element.get_tag() == "img") {
                        for (const auto& it_deep : element.get_properties()) {
                            if (it_deep.get_key() == "src") {
                                image = it_deep.get_value();

                                bool skip{false};
                                for (const auto& it : skip_list) {
                                    if (image == it) {
                                        image.clear();
                                        skip = true;
                                    }
                                }
                                if (skip) {
                                    continue;
                                }
                                return;
                            }
                        }
                    }
                } else if (std::holds_alternative<bygg::HTML::Section>(_it) && image.empty()) {
                    extract_image(std::get<bygg::HTML::Section>(_it), image);
                }
            }
        };

        extract_description(page, description);
        extract_title(page, title);
        extract_image(page, image);

        root += Templates::get_generic_header(remove_tags(title), remove_tags(description), remove_tags(image));
        root += page;

        endpoint.open();
        endpoint.append_string(bygg::HTML::Document(root).get<std::string>(bygg::HTML::Formatting::None));
        endpoint.close();
    }

    for (const auto& it : css_files) {
        Endpoint endpoint(std::get<0>(it));
        endpoint.open();
        endpoint.append_string(std::get<1>(it).get<std::string>(bygg::CSS::Formatting::None));
        endpoint.close();
    }

    for (const auto& it : js_files) {
        Endpoint endpoint(std::get<0>(it));
        endpoint.open();
        endpoint.append_string(std::get<1>(it));
        endpoint.close();

        // try uglifyjs
        if (std::system("command -v npx > /dev/null") == 0) {
            std::system(std::string("npx uglifyjs " + std::get<0>(it) + " --output " + std::get<0>(it) + " --compress --mangle > /dev/null").c_str()); // NOLINT
        }
    }

    if (argc > 1 && std::string(argv[1]) == "no-open") {
        return 0;
    }

    std::cout << "Website generated successfully. See out/ for the generated files.\n";
    std::cout << "Press enter to open the website in your default browser...";
    if (std::cin.get() == '\n') {
#ifdef _WIN32
        std::system("start out/index.html");
#elif __APPLE__
        std::system("open $(pwd)/out/index.html");
#elif __linux__ || __unix__
        std::system("xdg-open out/index.html");
#else
        std::cerr << "Operating system not supported" << std::endl;
#endif
    }
}
