#include <iostream>
#include <Endpoint.hpp>
#include <Sites.hpp>
#include <Stylesheets.hpp>
#include <Scripts.hpp>
#include <Templates.hpp>
#include <bygg/bygg.hpp>

// Files to copy from the source directory to the output directory
// Also works with files located in the parent directory
static const std::vector<std::pair<std::string, std::string>> copy_files{
    {"fonts/SiteFont.ttf", "out/fonts/SiteFont.ttf"},
    {"fonts/SiteFontBold.ttf", "out/fonts/SiteFontBold.ttf"},
    {"img/github-black.svg", "out/img/github-black.svg"},
    {"img/github-white.svg", "out/img/github-white.svg"},
    {"img/bsky.svg", "out/img/bsky.svg"},
    {"img/mail.svg", "out/img/mail.svg"},
    {"img/git.svg", "out/img/git.svg"},
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
    {"out/index.html", Sites::get_index_site(), PageProperties{"Welcome to Jacob Nilsson's personal website", "Welcome to Jacob Nilsson's website! I'm an 18 year old student from Sweden interested in computers, programming, politics and whatever else I happen to find interest in.", "en"}, true},
    {"out/about.html", Sites::get_about_me_site(), PageProperties{"About Jacob Nilsson", "I’m Jacob Nilsson, an 18 year old student, programmer, whatever.", "en"}, true},
    {"out/blog.html", Sites::get_blog_site(), PageProperties{"Jacob Nilsson's blog", "I like to write blog posts about things I find interesting sometimes.", "en"}, true},
    {"out/blog/macos-passwords-app-crash-bug.html", Sites::get_macos_passwords_app_crash_bug(), PageProperties{"macOS Passwords App Crash Bug", "A while ago I discovered a pretty silly bug in macOS’s brand new Passwords app. If you’re not aware, it was introduced in the new macOS version - Sequoia. I’m rather surprised this one slipped through the cracks, because it really isn’t hard at all to find, and can be consistently replicated too.", "en"}, true},
    {"out/blog/the-sad-state-of-music-hoarding-on-ios.html", Sites::get_the_sad_state_of_music_hoarding_on_ios(), PageProperties{"Rant: The sad state of music hoarding on iOS", "I'm the one weirdo who prefers digital music, but in the form of files, and not streaming. Asterisk, because I do stream music, it's just that it's from my own collection through SMB. This solution works great for me, especially since I'm almost always connected to a good internet connection and I have unlimited 5G data. Even the large FLAC files stream without a hitch. It works great on my Mac, or any device really. You can just open a file as if it's a local file and it will start playing.", "en"}, true},
    {"out/bygg.html", Sites::get_bygg_site(), PageProperties{"bygg for modern C++", "bygg is a component-based HTML/CSS builder for C++", "en"}, true},
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
            throw std::runtime_error("Failed to copy file: " + first + " to " + second + " - " + ec.message());
        }
    }
    for (const auto& it : website_tree) {
        Endpoint endpoint(std::get<0>(it));

        bygg::HTML::Section root{bygg::HTML::Tag::Html, bygg::HTML::make_properties(bygg::HTML::Property{"lang", std::get<2>(it).lang})};

        if (!std::get<3>(it)) {
            endpoint.open();
            endpoint.append_string(bygg::HTML::Document(std::get<1>(it)).get<std::string>(bygg::HTML::Formatting::Pretty));
            endpoint.close();
            continue;
        }
        root += Templates::get_generic_header(std::get<2>(it).name, std::get<2>(it).description);
        root += std::get<1>(it);
        root += Templates::get_generic_footer();

        endpoint.open();
        endpoint.append_string(bygg::HTML::Document(root).get<std::string>(bygg::HTML::Formatting::Pretty));
        endpoint.close();
    }

    for (const auto& it : css_files) {
        Endpoint endpoint(std::get<0>(it));
        endpoint.open();
        endpoint.append_string(std::get<1>(it).get<std::string>(bygg::CSS::Formatting::Pretty));
        endpoint.close();
    }

    for (const auto& it : js_files) {
        Endpoint endpoint(std::get<0>(it));
        endpoint.open();
        endpoint.append_string(std::get<1>(it));
        endpoint.close();
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