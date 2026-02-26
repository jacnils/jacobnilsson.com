#ifndef SITES_HPP
#define SITES_HPP

#include <bygg/bygg.hpp>

struct PageProperties {
    std::string name{};
    std::string description{};
    std::string lang{};
    std::string image{};
};

namespace Sites {
    bygg::HTML::Section get_index_site();
    bygg::HTML::Section get_settings_site();
    bygg::HTML::Section get_about_me_site();
    bygg::HTML::Section get_blog_site();
    bygg::HTML::Section get_macos_passwords_app_crash_bug();
    bygg::HTML::Section get_the_sad_state_of_music_hoarding_on_ios();
    bygg::HTML::Section get_reassigning_your_email_the_hidden_vulnerability();
    bygg::HTML::Section get_bygg_site();
}

#endif //SITES_HPP
