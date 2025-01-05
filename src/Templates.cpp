#include <Templates.hpp>

bygg::HTML::Section Templates::get_generic_header(const std::string& title, const std::string& description, const std::string& image) {
    using namespace bygg::HTML;
    return Section{Tag::Empty_No_Formatting,
        Section{Tag::Head,
            Element{Tag::Title, title},
            Element{Tag::Meta, make_properties(Property{"charset", "utf-8"})},
            Element{Tag::Meta, make_properties(Property{"name", "description"}, Property{"content", description})},
            Element{Tag::Meta, make_properties(Property{"name", "viewport"}, Property{"content", "width=device-width, initial-scale=1"})},
            Element{Tag::Meta, make_properties(Property{"name", "author"}, Property{"content", "Jacob Nilsson"})},
            Element{Tag::Meta, make_properties(Property{"name", "keywords"}, Property{"content", "Jacob Nilsson, Blog, Programming, C++, Software Development, Politics, Technology, Privacy, Linux, macOS, Apple"})},
            Element{Tag::Meta, make_properties(Property{"property", "og:title"}, Property{"content", title})},
            Element{Tag::Meta, make_properties(Property{"property", "og:description"}, Property{"content", description})},
            Element{Tag::Meta, make_properties(Property{"property", "og:type"}, Property{"content", "website"})},
            Element{Tag::Meta, make_properties(Property{"property", "og:locale"}, Property{"content", "en_US"})},
            Element{Tag::Meta, make_properties(Property{"property", "og:site_name"}, Property{"content", "jacobnilsson.com"})},
            Element{Tag::Meta, make_properties(Property{"property", "og:url"}, Property{"content", "https://jacobnilsson.com"})},
            (image.empty() ? Element() : Element{Tag::Meta, make_properties(Property{"property", "og:image"}, Property{"content", image})}),
            Element{Tag::Link, make_properties(Property{"rel", "stylesheet"}, Property{"href", "https://cdnjs.cloudflare.com/ajax/libs/highlight.js/11.9.0/styles/default.min.css"})},
            Element{Tag::Script, make_properties(Property{"src", "https://cdnjs.cloudflare.com/ajax/libs/highlight.js/11.9.0/highlight.min.js"})},
            Element{Tag::Script, "hljs.highlightAll();"},
            Element{Tag::Link, make_properties(Property{"rel", "stylesheet"}, Property{"href", "/css/style.css"})},
        },
    };
}

bygg::HTML::Section Templates::get_generic_footer() {
    using namespace bygg::HTML;
    return Section{Tag::Empty_No_Formatting,
        Section{Tag::Footer, Property{"class", "footer"}, Property{"id", "footer"},
            Element{Tag::P, "&copy; 2024-2025 Jacob Nilsson"},
        },
        Element{Tag::Script, Property{"src", "/js/script.js"}},
    };
}

bygg::HTML::Section Templates::get_generic_base_body() {
    using namespace bygg::HTML;
    return Section{Tag::Body, Property{"class", "body"},
        Section{Tag::Div, make_properties(Property{"class", "top-bar"}, Property{"id", "topBar"}),
            Element{Tag::Div, Property{"class", "header"}, "<a href=\"/\">jacobnilsson.com</a>"},
            Section{Tag::Div, Property{"class", "nav-links"},
                Element{Tag::A, Property{"href", "/"}, "Home"},
                Element{Tag::A, Property{"href", "/about.html"}, "About me"},
                Element{Tag::A, Property{"href", "/#contact-h1"}, "Contact"},
                Element{Tag::A, Property{"href", "/blog.html"}, "Blog"},
                Element{Tag::A, Property{"href", "https://git.jacobnilsson.com/jacob"}, "Projects"},
            },
        },
        Section{Tag::Div, Property{"id", "content"}, Property{"class", "content"}},
        Templates::get_generic_footer(),
    };
}

bygg::HTML::Section Templates::get_blogpost_preview(const BlogPostPreview& bp) {
    using namespace bygg::HTML;
    return Section{Tag::Div, Property{"class", "preview"}, bp.location.empty() ? Property() : Property{"onclick", "location.href='" + bp.location + "';"},
        Element{Tag::H2, Property{"class", "preview_title"}, bp.title},
        Element{Tag::Small, Property{"class", "preview_author"}, "by " + bp.author + " • "},
        Element{Tag::Small, Property{"class", "preview_date"}, bp.date + " • "},
        Element{Tag::Small, Property{"class", "preview_tags"}, bp.tags},
        Element{Tag::P, Property{"class", "preview_description"}, bp.description},
    };
}

bygg::HTML::Section Templates::get_project_preview(const ProjectPreview& pp) {
    using namespace bygg::HTML;
    return Section{Tag::Div, Property{"class", "preview"}, pp.location.empty() ? Property() : Property{"onclick", "location.href='" + pp.location + "';"},
        Element{Tag::H2, Property{"class", "preview_title"}, pp.title},
        Element{Tag::P, Property{"class", "preview_description"}, pp.description},
    };
}

bygg::HTML::Section Templates::get_grid(const std::vector<bygg::HTML::Section>& sections) {
    using namespace bygg::HTML;
    Section grid{Tag::Div, Property{"class", "grid"}};

    for (const auto& it : sections) {
        Section s = it;
        auto properties = s.get_properties();
        if (properties.find("class") != Properties::npos) {
            properties.at(properties.find("class")) = Property{"class", "grid-item " + properties.at(properties.find("class")).get_value()};
        } else {
            properties += Property{"class", "grid-item"};
        }
        s.set_properties(properties);
        grid += s;
    }

    return grid;
}

bygg::HTML::Section Templates::get_image_link(const ImageLink& il) {
    using namespace bygg::HTML;
    return Section{Tag::Span, Property{"id", il.id}, Property{"class", il.classes + (il.mode == Mode::Dark ? (il.classes.empty() ? "dark" : " dark") : il.mode == Mode::Light ? (il.classes.empty() ? "light" : " light") : "")},
        Section{Tag::A, Property{"href", il.location},
            Element{Tag::Img, make_properties(Property{"src", il.image_location}, Property{"alt", il.alt}, Property{"width", "16"}, Property{"height", "16"}, Property{"style", "transform: translate(-10%, +20%);"})},
            Element{Tag::Empty, il.text + "<br>\n"},
        },
    };
}

bygg::HTML::Section Templates::get_spoiler(const bygg::HTML::Section& content) {
    using namespace bygg::HTML;
    return Section{Tag::Empty_No_Formatting,
            Section{Tag::Div, Property{"class", "spoiler no-select"}, Property{"id", "spoiler-" + std::to_string(spoiler_id)}, content},
            Element{Tag::Button, Properties(Property{"onclick", "toggle_spoiler('spoiler-" + std::to_string(spoiler_id) + "', 'spoiler-button-" + std::to_string(spoiler_id) + "')"}, Property{"class", "spoiler-button"}, Property{"id", "spoiler-button-" + std::to_string(spoiler_id++)}), "Show Content"},
    };
}

bygg::HTML::Section Templates::get_codeblock(const std::string& code) {
    using namespace bygg::HTML;
    std::string code_copy = code;
    // escape characters that would break the HTML
    for (size_t i = 0; i < code_copy.size(); ++i) {
        if (code_copy[i] == '<') {
            code_copy.replace(i, 1, "&lt;");
            i += 3;
        } else if (code_copy[i] == '>') {
            code_copy.replace(i, 1, "&gt;");
            i += 3;
        }
    }
    return Section{Tag::Div, Property{"class", "code-block"},
        Section{Tag::Pre, Property{"id", "code-block-" + std::to_string(codeblock_id)},
            Element{Tag::Code,
                Properties{
                    Property{"class", "hljs"},
                    Property{"style", "white-space: pre-wrap; text-align: left;"},
                }, code_copy,
            },
        },
        Section{Tag::Div, Property{"style", "text-align: right; margin-top: -100px; margin-right: 5px; z-index: 10; position: relative;"},
            Element{Tag::Button, Properties{Property{"class", "copy-button"}, Property{"onclick", "copy_to_clipboard(this, 'code-block-" + std::to_string(codeblock_id++) + "')"}}, "Copy"}
        }
    };
}

bygg::HTML::Section Templates::get_bulletpoint_list(const std::vector<std::string> &list) {
    using namespace bygg::HTML;
    Section ul{Tag::Ul};
    for (const auto& it : list) {
        ul += Element{Tag::Li, it};
    }
    return ul;
}

bygg::HTML::Section Templates::get_numbered_list(const std::vector<std::string> &list) {
    using namespace bygg::HTML;
    Section ol{Tag::Ol};
    for (const auto& it : list) {
        ol += Element{Tag::Li, it};
    }
    return ol;
}

bygg::HTML::Section Templates::get_blogpost_header(const BlogPostHeader& header) {
    using namespace bygg::HTML;
    return Section{Tag::Div, Property{"class", "blogpost-header"},
        Element{Tag::H1, header.title},
        Element{Tag::Small, Property{"class", "blogpost-author"}, "by " + header.author + " • "},
        Element{Tag::Small, Property{"class", "blogpost-date"}, header.date + " • "},
        Element{Tag::Small, Property{"class", "blogpost-tags"}, header.tags},
    };
}
