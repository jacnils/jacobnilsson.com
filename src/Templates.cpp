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
            Element{Tag::Link, make_properties(Property{"rel", "icon"}, Property{"type", "image/x-icon"}, Property{"href", "/img/favicon.ico"})},
            Element{Tag::Script, make_properties(Property{"src", "https://cdnjs.cloudflare.com/ajax/libs/highlight.js/11.9.0/highlight.min.js"})},
            Element{Tag::Script, make_properties(Property{"src", "https://kit.fontawesome.com/aa55cd1c33.js"}, Property{"crossorigin", "anonymous"})},
            Element{Tag::Script, "hljs.highlightAll();"},
            Element{Tag::Link, make_properties(Property{"rel", "stylesheet"}, Property{"href", "/css/style.css"})},
        },
    };
}

bygg::HTML::Section Templates::get_generic_footer() {
    using namespace bygg::HTML;
    return Section{Tag::Empty_No_Formatting,
        Section{Tag::Footer, Property{"class", "footer"}, Property{"id", "footer"},
            Element{Tag::P, "&copy; 2024-2026 Jacob Nilsson"},
            Element{Tag::Button, Properties{Property{"class", "fa-solid fa-gear"}, Property{"onclick", "location.href='/settings.html'"}, Property{"style", "font-size: 20px; background: transparent; float: right; margin-right: 20px;"}}, ""}
        },
        Element{Tag::Script, Property{"src", "/js/script.js"}},
    };
}

bygg::HTML::Section Templates::get_generic_base_body() {
    using namespace bygg::HTML;
    return Section{Tag::Body, Property{"class", "body"},
        Section{Tag::Div, make_properties(Property{"class", "top-bar"}, Property{"id", "topBar"}),
            Section{Tag::Div, Property{"class", "header dark"},
                Section{Tag::A, Property{"href", "/"},
                    Element{Tag::Img, make_properties(Property{"id", "logo"}, Property{"src", "/img/logo.png"}, Property{"style", "height:100px;width:100px;filter:invert(1);vertical-align:middle;padding:10px;"})},
                    Element{Tag::Empty_No_Formatting, "jacobnilsson.com"},
                },
            },
            Section{Tag::Div, Property{"class", "header light"},
                Section{Tag::A, Property{"href", "/"},
                    Element{Tag::Img, make_properties(Property{"id", "logo"}, Property{"src", "/img/logo.png"}, Property{"style", "height:100px;width:100px;vertical-align:middle;padding:10px;"})},
                    Element{Tag::Empty_No_Formatting, "jacobnilsson.com"},
                },
            },
            Section{Tag::Div, Property{"class", "nav-links"},
                Element{Tag::A, make_properties(Property{"href", "/"}, Property{"class", "english"}), "Home"},
                Element{Tag::A, make_properties(Property{"href", "/about.html"}, Property{"class", "english"}), "About me"},
                Element{Tag::A, make_properties(Property{"href", "/#contact-h1"}, Property{"class", "english"}), "Contact"},
                Element{Tag::A, make_properties(Property{"href", "/blog.html"}, Property{"class", "english"}), "Blog"},
                Element{Tag::A, make_properties(Property{"href", "https://git.jacobnilsson.com/jacob"}, Property{"class", "english"}), "Projects"},
                Element{Tag::A, make_properties(Property{"href", "/"}, Property{"class", "swedish"}), "Hem"},
                Element{Tag::A, make_properties(Property{"href", "/about.html"}, Property{"class", "swedish"}), "Om mig"},
                Element{Tag::A, make_properties(Property{"href", "/#sv-contact-h1"}, Property{"class", "swedish"}), "Kontakt"},
                Element{Tag::A, make_properties(Property{"href", "/blog.html"}, Property{"class", "swedish"}), "Blogg"},
                Element{Tag::A, make_properties(Property{"href", "https://git.jacobnilsson.com/jacob"}, Property{"class", "swedish"}), "Projekt"},
            },
        },
        Section{Tag::Div, Property{"id", "content"}, Property{"class", "content"},
            Templates::get_top_notice({.background = "#feffd6", .color = "#721c24", .text = "🇸🇪 Webbsidan finns tillgänglig på svenska. <a href=\"/settings.html\">Ändra språk</a>.", .classes = "english no-lang", .button_onclick = "set_cookie('lang', 'en', 365);"}),
            Templates::get_top_notice({.background = "#feffd6", .color = "#721c24", .text = "🇺🇸 The website is also available in English <a href=\"/settings.html\">Change language</a>.", .classes = "swedish no-lang", .button_onclick = "set_cookie('lang', 'sv', 365);"}),
            Templates::get_top_notice({
                .background = "#003399",
                .color = "#FFCC00",
                .text = "The European Union might force me to tell you that I'm forcing cookies, a staple of the internet since the '90s, down your throat so that I can provide you with very basic features of my website such as language selection. That's your notice. And if you live in a sane country like Norway but happen to be a part of the same continent as morons, you may safely ignore this.",
                .classes = "eu english",
                .button_onclick = "set_cookie('eu', 'true', 365);",
            }),
            Templates::get_top_notice({
                .background = "#003399",
                .color = "#FFCC00",
                .text = "Europeiska unionen kan tvinga mig att berätta för dig att jag påtvingar kakor, en stapelvara på internet sedan 90-talet, ner i halsen på dig så att jag kan erbjuda dig grundläggande funktioner på min webbplats som språkval. Det är din notis. Och om du bor i ett sunt land som Norge och råkar befinna dig på samma kontinent som idioter, kan du ignorera detta meddelande.",
                .classes = "eu swedish",
                .button_onclick = "set_cookie('eu', 'true', 365);",
            }),
        },
        Section{Tag::Div, Property{"id", "swedish-content"}, Property{"class", "content swedish-content"}},
        Templates::get_generic_footer(),
    };
}

bygg::HTML::Section Templates::get_blogpost_preview(const BlogPostPreview& bp) {
    using namespace bygg::HTML;
    std::string tags{};
    for (char ch : bp.tags) {
        tags += ch;
        if (ch == ',') {
            tags += ' ';
        }
    }

    return Section{Tag::Div, Property{"class", "preview"}, bp.location.empty() ? Property() : Property{"onclick", "location.href='" + bp.location + "';"},
        Element{Tag::H2, Property{"class", "preview_title"}, bp.title},
        Element{Tag::Small, Property{"class", "preview_author"}, "by " + bp.author + " • "},
        Element{Tag::Small, Property{"class", "preview_date"}, bp.date + " • "},
        Element{Tag::Small, Property{"class", "preview_tags"}, tags},
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

bygg::HTML::Section Templates::get_image_link_preview(const ImageLinkPreview& il) {
    using namespace bygg::HTML;
    return Section{Tag::Div, Property{"class", (il.mode == Mode::Dark ? "image-link-preview dark" : il.mode == Mode::Light ? "image-link-preview light" : "image-link-preview")}, Property{"style", il.text_pos == Pos::Left ? "text-align: left;" : il.text_pos == Pos::Right ? "text-align: right;" : "text-align: center;"},
        Section{Tag::Span, Property{"id", il.id}, Property{"class", il.classes + (il.mode == Mode::Dark ? (il.classes.empty() ? "dark" : " dark") : il.mode == Mode::Light ? (il.classes.empty() ? "light" : " light") : "")},
            Section{Tag::A, Property{"href", il.location},
                Element{Tag::Img, make_properties(Property{"src", il.image_location}, Property{"alt", il.alt}, Property{"width", "16"}, Property{"height", "16"}, Property{"style", (il.image_pos == Pos::Left ? "transform: translate(-10%, +20%); float: left; margin-right: 10px;" : il.image_pos == Pos::Right ? "transform: translate(-10%, +20%); float: right; margin-left: 10px;" : "transform: translate(-10%, +20%);")})},
                Element{Tag::Empty, il.text + "<br>\n"},
            },
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

    return Section{Tag::Div, Property{"class", "code-block"},
        Section{Tag::Pre, Property{"id", "code-block-" + std::to_string(codeblock_id)},
            Element{Tag::Code,
                Properties{
                    Property{"class", "hljs"},
                    Property{"style", "text-align:left;"},
                }, code,
                ElementParameters::Replace_All,
            },
        },
        Section{Tag::Div, Property{"style", "text-align:right;margin-top:-10px;margin-right:5px;z-index:10;position:relative;"},
            Element{Tag::Button, Properties{Property{"class", "copy-button fa-solid fa-clipboard"}, Property{"onclick", "copy_to_clipboard(this, 'code-block-" + std::to_string(codeblock_id++) + "')"}}, ""},
        },
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
    std::string tags{};
    for (char ch : header.tags) {
        tags += ch;
        if (ch == ',') {
            tags += ' ';
        }
    }

    return Section{Tag::Div, Property{"class", "blogpost-header"},
        Element{Tag::H1, header.title},
        Element{Tag::Small, Property{"class", "blogpost-author"}, "by " + header.author + " • "},
        Element{Tag::Small, Property{"class", "blogpost-date"}, header.date + " • "},
        Element{Tag::Small, Property{"class", "blogpost-tags"}, tags},
    };
}

bygg::HTML::Section Templates::get_top_notice(const Notice& notice) {
    using namespace bygg::HTML;

    Property property{"class", std::string(notice.classes.empty() ? "top-notice" : ("top-notice " + notice.classes))};
    return Section{Tag::Div, make_properties(property, Property{"style", "color:" + notice.color + ";background-color:" + notice.background + ";"}),
        Element{Tag::Small, notice.text},
        Element{Tag::Button, make_properties(Property{"onclick", "this.parentElement.style.display='none';" + notice.button_onclick}, Property{"style", "float:right;background-color:" + notice.background + ";color:" + notice.color + ";"}), "✕"},
    };
}
