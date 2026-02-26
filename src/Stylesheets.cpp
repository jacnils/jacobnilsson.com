#include <Stylesheets.hpp>

bygg::CSS::Stylesheet Stylesheets::get_style() {
    using namespace bygg::CSS;
    using Tag = bygg::HTML::Tag;

    struct Theme {
        std::string custom_font_name = "SiteFont";
        std::string custom_font_name_bold = "SiteFontBold";
        std::string font = "SiteFont, SiteFontBold, Arial, sans-serif";
        std::string top_background = "#fff";
        std::string top_color = "#000";
        std::string nav_background = "#f0f0f0";
        std::string nav_color = "#000";
        std::string nav_scroll_background = "#f0f0f080";
        std::string footer_background = "#fff";
        std::string footer_color = "#000";
        std::string content_background = "#f9f9f9";
        std::string content_color = "#000";
        std::string link_color = "#007bff";
        std::string preview_color = "#000";
        std::string preview_background = "#f0f0f0";
        std::string button_color = "#000";
        std::string button_background = "#f0f0f0";
        std::string codeblock_color = "#000";
        std::string codeblock_background = "#f0f0f0";
        std::string copybutton_color = "#000";
        std::string copybutton_background = "#ffffff";
        std::string copybutton_hover_color = "#ffffff";
    };

    Theme dark{
        .top_background = "#333",
        .top_color = "#eeeeee",
        .nav_background = "#444",
        .nav_color = "#eeeeee",
        .nav_scroll_background = "#44444480",
        .footer_background = "#333",
        .footer_color = "#eeeeee",
        .content_background = "#222",
        .content_color = "#eeeeee",
        .link_color = "#007bff",
        .preview_color = "#eeeeee",
        .preview_background = "#333",
        .button_color = "#eeeeee",
        .button_background = "#333",
        .codeblock_color = "#eeeeee",
        .codeblock_background = "#333",
        .copybutton_color = "#eeeeee",
        .copybutton_background = "#444",
        .copybutton_hover_color = "#444",
    };
    Theme light{};
    ElementList general{};
    ElementList dark_l{};
    ElementList light_l{};

    std::vector<std::pair<ElementList*, Theme*>> pair_vec{{&dark_l, &dark}, {&light_l, &light}};
    for (auto& it : pair_vec) {
        Theme& theme = *it.second;
        *it.first = ElementList{
            Element{"font-face", Type::Rule,
                Properties{
                    Property{"font-family", theme.custom_font_name},
                    Property{"src", Function("url", "/fonts/SiteFont.ttf")},
                },
            },
            Element{"font-face", Type::Rule,
                Properties{
                    Property{"font-family", theme.custom_font_name_bold},
                    Property{"src", Function("url", "/fonts/SiteFontBold.ttf")},
                    Property{"font-weight", "bold"},
                },
            },
            Element{"keyframes slide-up", Type::Rule,
                Element{"from", Type::Selector, Property{"transform", "translateY(20%)"}, Property{"opacity", "0"}},
                Element{"to", Type::Selector, Property{"transform", "translateY(0)"}, Property{"opacity", "1"}},
            },
            Element{"*", Property{"font-family", theme.font}, Property{"scroll-behavior", "smooth"}},
            Element{Tag::Body,
                Properties{
                    Property{"margin", "0"},
                    Property{"color", ColorFormatter(from_hex(theme.content_color)).get(bygg::CSS::ColorFormatting::Rgb)},
                    Property{"background-color", ColorFormatter(from_hex(theme.content_background)).get(bygg::CSS::ColorFormatting::Rgb)},
                },
            },
            Element{"top-bar", Type::Class,
                Properties{
                    Property{"position", "fixed"},
                    Property{"top", "0"},
                    Property{"width", "100%"},
                    Property{"background-color", ColorFormatter(from_hex(theme.top_background)).get(bygg::CSS::ColorFormatting::Rgb)},
                    Property{"color", ColorFormatter(from_hex(theme.top_color)).get(bygg::CSS::ColorFormatting::Rgb)},
                    Property{"display", "flex"},
                    Property{"flex-direction", "column"},
                    Property{"z-index", "9998"},
                    Property{"align-items", "center"},
                    Property{"transition", "top 0.3s"},
                },
            },
            Element{"top-bar.hidden", Type::Class, Property{"top", "-150px"}}, // TODO: Make this be dynamic
            Element{"header", Type::Class,
                Properties{
                    Property{"padding", "15px"},
                    Property{"font-size", "24px"},
                },
            },
            Element{"nav-links", Type::Class,
                Properties{
                    Property{"display", "flex"},
                    Property{"justify-content", "space-around"},
                    Property{"width", "100%"},
                    Property{"z-index", "9999"},
                    Property{"background-color", ColorFormatter(from_hex(theme.nav_background)).get(bygg::CSS::ColorFormatting::Rgb)},
                },
            },
            Element{"nav-links a, .header a", Type::Class,
                Properties{
                    Property{"padding", "15px"},
                    Property{"color", ColorFormatter(from_hex(theme.nav_color)).get(bygg::CSS::ColorFormatting::Rgb)},
                    Property{"text-decoration", "none"},
                },
            },
            Element{"nav-links a", Type::Class, "hover",
                Properties{
                    Property{"transform", "translateY(2px)"},
                    Property{"transition", "transform 0.3s ease"},
                },
            },
            Element{"content", Type::Class,
                Properties{
                    Property{"padding", "20px 50px"},
                    Property{"transition", "padding 0.3s"},
                    Property{"text-align", "center"},
                    Property{"max-width", "60%"},
                    Property{"margin", "0 auto"},
                    Property{"animation", "slide-up 0.5s ease-out forwards"},
                },
            },
            Element{"content a", Type::Class,
                Properties{
                    Property{"color", ColorFormatter(from_hex(theme.link_color)).get(bygg::CSS::ColorFormatting::Rgb)},
                    Property{"text-decoration", "none"},
                },
            },
            Element{"footer", Type::Class,
                Properties{
                    Property{"position", "fixed"},
                    Property{"bottom", "-100%"},
                    Property{"width", "100%"},
                    Property{"background-color", ColorFormatter(from_hex(theme.footer_background)).get(bygg::CSS::ColorFormatting::Rgb)},
                    Property{"color", ColorFormatter(from_hex(theme.footer_color)).get(bygg::CSS::ColorFormatting::Rgb)},
                    Property{"text-align", "center"},
                    Property{"padding", "10px"},
                    Property{"transition", "bottom 0.5s"},
                },
            },
            Element{"footer.visible", Type::Class, Property{"bottom", "0"}},
            Element{"preview", Type::Class,
                Properties{
                    Property{"color", ColorFormatter(from_hex(theme.preview_color)).get(bygg::CSS::ColorFormatting::Rgb)},
                    Property{"background-color", ColorFormatter(from_hex(theme.preview_background)).get(bygg::CSS::ColorFormatting::Rgb)},
                    Property{"border-radius", "10px"},
                    Property{"display", "inline-block"},
                    Property{"padding", "10px"},
                    Property{"margin-top", "10px"},
                    Property{"min-width", "300px"},
                    Property{"cursor", "pointer"},
                },
            },
            Element{"preview", Type::Class, "hover",
                Properties{
                    Property{"transform", "scale(1.05)"},
                    Property{"transition", "transform 0.3s ease"},
                },
            },
            Element{"preview_title", Type::Class,
                Properties{
                    Property{"font-size", "20px"},
                    Property{"margin", "0"},
                },
            },
            Element{"image-link-preview", Type::Class,
                Properties{
                    Property{"color", ColorFormatter(from_hex(theme.preview_color)).get(bygg::CSS::ColorFormatting::Rgb)},
                    Property{"background-color", ColorFormatter(from_hex(theme.preview_background)).get(bygg::CSS::ColorFormatting::Rgb)},
                    Property{"border-radius", "10px"},
                    Property{"padding", "10px"},
                    Property{"margin-top", "10px"},
                    Property{"margin-left", "auto"},
                    Property{"margin-right", "auto"},
                    Property{"min-width", "300px"},
                    Property{"max-width", "300px"},
                    Property{"cursor", "pointer"},
                },
            },
            Element{"image-link-preview a", Type::Class,
                Properties{
                    Property{"color", ColorFormatter(from_hex(theme.preview_color)).get(bygg::CSS::ColorFormatting::Rgb)},
                },
            },
            Element{"image-link-preview", Type::Class, "hover",
                Properties{
                    Property{"transform", "scale(1.05)"},
                    Property{"transition", "transform 0.3s ease"},
                },
            },
            Element{"grid", Type::Class,
                Properties{
                    Property{"display", "flex"},
                    Property{"flex-direction", "row"},
                    Property{"gap", "10px"},
                    Property{"padding-top", "10px"},
                    Property{"justify-content", "center"},
                },
            },
            Element{"grid-item", Type::Class,
                Properties{
                    Property{"padding", "10px"},
                },
            },
            Element{"no-select", Type::Class,
                Properties{
                    Property{"user-select", "none"},
                    Property{"-webkit-user-select", "none"},
                    Property{"-moz-user-select", "none"},
                    Property{"-ms-user-select", "none"},
                },
            },
            Element{"img", Type::Selector,
                Properties{
                    Property{"margin-left", "auto"},
                    Property{"margin-right", "auto"},
                    Property{"max-width", "90%"},
                    Property{"border-radius", "10px"},
                },
            },
            Element{"spoiler", Type::Class, Property{"opacity", "0.5"}, Property{"transition", "opacity 0.5s ease"}, Property{"filter", "blur(5px)"}},
            Element{"spoiler.show", Type::Class, Property{"opacity", "1"}, Property{"filter", "blur(0)"}},
            Element{"input, select, textarea, button", Type::Selector,
                Properties{
                    Property{"font-weight", "normal"},
                    Property{"border", "none"},
                    Property{"border-color", ColorFormatter(from_hex(theme.button_background)).get(bygg::CSS::ColorFormatting::Rgb)},
                    Property{"background-color", ColorFormatter(from_hex(theme.button_background)).get(bygg::CSS::ColorFormatting::Rgb)},
                    Property{"color", ColorFormatter(from_hex(theme.button_color)).get(bygg::CSS::ColorFormatting::Rgb)},
                    Property{"border-radius", "10px"},
                    Property{"padding", "5px"},
                    Property{"box-shadow", "none"},
                },
            },
            Element{"hljs", Type::Class,
                Properties{
                    Property{"color", ColorFormatter(from_hex(theme.codeblock_color)).get(bygg::CSS::ColorFormatting::Rgb)},
                    Property{"background", ColorFormatter(from_hex(theme.codeblock_background)).get(bygg::CSS::ColorFormatting::Rgb)},
                    Property{"border-radius", "10px"},
                },
            },
            Element{"copy-button", Type::Class,
                Properties{
                    Property{"margin-top", "1px"},
                    Property{"padding", "5px 10px"},
                    Property{"background-color", ColorFormatter(from_hex(theme.copybutton_background)).get(bygg::CSS::ColorFormatting::Rgb)},
                    Property{"color", ColorFormatter(from_hex(theme.copybutton_color)).get(bygg::CSS::ColorFormatting::Rgb)},
                    Property{"border", "none"},
                    Property{"border-radius", "10px"},
                    Property{"cursor", "pointer"},
                },
            },
            Element{"copy-button", Type::Class, "hover",
                Properties{
                    Property{"background-color", ColorFormatter(from_hex(theme.copybutton_hover_color)).get(bygg::CSS::ColorFormatting::Rgb)},
                },
            },
            Element{"ul, ol", Type::Selector,
                Properties{
                    Property{"display", "block"},
                    Property{"padding-left", "0"},
                    Property{"padding-right", "0"},
                    Property{"text-align", "center"},
                    Property{"list-style-position", "inside"},
                },
            },
            Element{"ul li, ol li", Type::Selector,
                Properties{
                    Property{"width", "100%"},
                    Property{"max-width", "40vw"},
                    Property{"padding-left", "20vw"},
                    Property{"padding-right", "20vw"},
                    Property{"text-align", "left"},
                },
            },
            Element{"top-notice", Type::Class,
                Properties{
                    Property{"width", "100%"},
                    Property{"text-align", "left"},
                    Property{"padding", "10px"},
                    Property{"margin-left", "auto"},
                    Property{"margin-right", "auto"},
                },
            },
            Element{"top-notice small", Type::Class,
                Properties{
                    Property{"margin-right", "10px"},
                },
            },
            Element{"top-notice button", Type::Class,
                Properties{
                    Property{"margin-right", "20px"},
                },
            },
            Element{"content, .swedish, .english, .eu", Type::Class,
                Properties{
                    {"display", "none"},
                },
            },
            /* For mobile */
            Element{"media (max-width: 600px)", Type::Rule,
                Element{
                    "preview, .image-link-preview", Type::Class,
                    Properties{
                        Property{"min-width", "100%"},
                        Property{"max-width", "100%"},
                        Property{"padding", "5px"},
                    },
                },
                Element{"preview_title", Type::Class,
                    Properties{
                        Property{"font-size", "16px"},
                    },
                },
                Element{"content", Type::Class,
                    Properties{
                        Property{"padding", "50px 10px 25px"},
                        Property{"max-width", "90%"},
                    },
                },
                Element{"ul li, ol li", Type::Selector,
                    Properties{
                        Property{"padding-left", "10vw"},
                        Property{"padding-right", "10vw"},
                    },
                },
                Element{"grid", Type::Class,
                    Properties{
                        Property{"flex-direction", "column"},
                        Property{"align-items", "center"},
                    },
                },
                Element{"grid-item", Type::Class,
                    Properties{
                        Property{"width", "100%"},
                        Property{"max-width", "100%"},
                    },
                },
            },
        };
    }

    Element dark_mode_element{"media (prefers-color-scheme: dark)", Type::Rule};
    dark_mode_element.push_back(Element{"dark", Type::Class, Property{"display", "block"}, Property{"background-color", "auto"}});
    dark_mode_element.push_back(Element{"light", Type::Class, Property{"display", "none"}, Property{"background-color", "none"}});
    for (const auto& it : dark_l) {
        dark_mode_element.push_back(it);
    }

    Stylesheet css{};
    css.push_back(Element{"light", Type::Class, Property{"display", "block"}, Property{"background-color", "auto"}});
    css.push_back(Element{"dark", Type::Class, Property{"display", "none"}, Property{"background-color", "none"}});
    for (const auto& it : light_l) {
        css.push_back(it);
    }

    css.push_back(dark_mode_element);

    return css;
}