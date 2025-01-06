#pragma once

#include <bygg/bygg.hpp>

namespace Templates {
    static int codeblock_id = 0;
    static int spoiler_id = 0;
    enum class Mode {
        Light,
        Dark,
        Any,
    };
    enum class Pos {
        Left,
        Center,
        Right,
    };
    struct BlogPostPreview {
        std::string location{};
        std::string title{};
        std::string author{};
        std::string date{};
        std::string tags{};
        std::string description{};
    };
    struct BlogPostHeader {
        std::string title{};
        std::string author{};
        std::string date{};
        std::string tags{};
    };
    struct ProjectPreview {
        std::string location{};
        std::string title{};
        std::string description{};
    };
    struct ImageLink {
        std::string alt{};
        std::string location{};
        std::string text{};
        std::string image_location{};
        std::string id{};
        std::string classes{};
        Mode mode{Mode::Any};
    };
    struct ImageLinkPreview {
        std::string alt{};
        std::string location{};
        std::string text{};
        std::string image_location{};
        std::string id{};
        std::string classes{};
        Mode mode{Mode::Any};
        Pos image_pos{Pos::Center};
        Pos text_pos{Pos::Center};
    };
    struct Notice {
        std::string text{};
        std::string color{};
        std::string background{};
        std::string classes{};
        std::string button_onclick{};
    };
    bygg::HTML::Section get_generic_header(const std::string&, const std::string& = {}, const std::string& = {});
    bygg::HTML::Section get_generic_footer();
    bygg::HTML::Section get_generic_base_body();
    bygg::HTML::Section get_top_notice(const Notice&);
    bygg::HTML::Section get_blogpost_preview(const BlogPostPreview&);
    bygg::HTML::Section get_project_preview(const ProjectPreview&);
    bygg::HTML::Section get_grid(const std::vector<bygg::HTML::Section>&);
    bygg::HTML::Section get_image_link(const ImageLink&);
    bygg::HTML::Section get_image_link_preview(const ImageLinkPreview&);
    bygg::HTML::Section get_spoiler(const bygg::HTML::Section& content);
    bygg::HTML::Section get_codeblock(const std::string& code);
    bygg::HTML::Section get_bulletpoint_list(const std::vector<std::string>& list);
    bygg::HTML::Section get_numbered_list(const std::vector<std::string>& list);
    bygg::HTML::Section get_blogpost_header(const BlogPostHeader&);
}