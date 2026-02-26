#include <string>
#include <Scripts.hpp>

std::string Scripts::get_script() {
    return R"(
function set_cookie(name, value, days) {
    let expires = '';
    if (days) {
        const date = new Date();
        date.setTime(date.getTime() + (days * 24 * 60 * 60 * 1000));
        expires = `; expires=${date.toUTCString()}`;
    }
    document.cookie = `${name}=${value || ''}${expires}; path=/`;
}

function get_cookie(name) {
    const name_eq = `${name}=`;
    const ca = document.cookie.split(';');
    for (let i = 0; i < ca.length; i++) {
        let c = ca[i];
        while (c.charAt(0) === ' ') {
            c = c.substring(1, c.length);
        }
        if (c.indexOf(name_eq) === 0) {
            return c.substring(name_eq.length, c.length);
        }
    }
    return null;
}

function cookie_exists(name) {
    return get_cookie(name) !== null;
}

function delete_cookie(name) {
    document.cookie = `${name}=; expires=Thu, 01 Jan 1970 00:00:00 UTC; path=/;`;
}

window.addEventListener('load', function() {
    const footer = document.querySelector('footer');
    const body = document.body;
    const nav_bar = document.querySelector('.top-bar');

    if (document.body.scrollHeight <= window.innerHeight) {
        footer.classList.add('visible');
    }

    let preferred_lang;
    if (cookie_exists('lang')) {
        preferred_lang = get_cookie('lang');
        if (preferred_lang !== "sv") {
            preferred_lang = "en";
        }
    } else {
        const timezone = Intl.DateTimeFormat().resolvedOptions().timeZone;
        if (timezone === 'Europe/Stockholm') {
            preferred_lang = "sv";
        } else {
            preferred_lang = "en";
        }
        preferred_lang = "en";
    }
    preferred_lang = preferred_lang === "sv" ? true : false;
    _preferred_lang = preferred_lang;

    const swedish_content = document.getElementById('swedish-content');
    const content = document.getElementById('content');
    const swedish = document.querySelectorAll('.swedish');
    const english = document.querySelectorAll('.english');

    if (swedish_content.childElementCount <= 0) {
        preferred_lang = false;
    } else if (content.childElementCount <= 0) {
        preferred_lang = true;
    }

    if (preferred_lang) {
        if (content) content.style.display = 'none';
        if (swedish_content) swedish_content.style.display = 'block';
    } else {
        if (swedish_content) swedish_content.style.display = 'none';
        if (content) content.style.display = 'block';
    }

    const links = document.getElementById('topBar');
    const notice = document.querySelectorAll('.top-notice');
    notice.forEach(element => {
        links.appendChild(element);
    });

    let lang = document.querySelectorAll('.language-select');
    lang.forEach(lang => {
        lang.addEventListener('change', function() {
            set_cookie('lang', lang.value, 365);
            location.reload();
        });
        lang.value = _preferred_lang ? 'sv' : 'en';
    });

    if (_preferred_lang) {
        swedish.forEach(element => {
            element.style.display = 'block';
        });
        english.forEach(element => {
            element.style.display = 'none';
        });
    } else {
        swedish.forEach(element => {
            element.style.display = 'none';
        });
        english.forEach(element => {
            element.style.display = 'block';
        });
    }

    const in_eu = Intl.DateTimeFormat().resolvedOptions().timeZone.startsWith("Europe");
    if (in_eu && !cookie_exists('eu')) {
        const eu = document.querySelectorAll('.eu');
        eu.forEach(element => {
            // check if its class matches the current language
            if (element.classList.contains('swedish') && _preferred_lang) {
                element.style.display = 'block';
            } else if (element.classList.contains('english') && !_preferred_lang) {
                element.style.display = 'block';
            } else {
                element.style.display = 'none';
            }
        });
    } else {
        const eu = document.querySelectorAll('.eu');
        eu.forEach(element => {
            element.style.display = 'none';
        });
    }

    if (cookie_exists('lang')) {
        const no_lang = document.querySelectorAll('.no-lang');
        no_lang.forEach(element => {
            element.style.display = 'none';
        });
    }

    function set_padding() {
        const fh = footer.offsetHeight;
        body.style.paddingBottom = `${fh}px`;
    }

    function set_nav_bar_padding() {
        const nh = nav_bar.offsetHeight;
        body.style.paddingTop = `${nh}px`;
    }

    set_padding();
    set_nav_bar_padding();
    window.addEventListener('resize', set_padding);
    window.addEventListener('resize', set_nav_bar_padding);
});

window.addEventListener('scroll', function() {
    const topBar = document.getElementById('topBar');
    const footer = document.getElementById('footer');

    if (window.scrollY > 50) {
        topBar.classList.add('hidden');
    } else {
        topBar.classList.remove('hidden');
    }

    if (window.scrollY + window.innerHeight >= document.body.scrollHeight - 50) {
        footer.classList.add('visible');
    } else {
        footer.classList.remove('visible');
    }
});

function toggle_spoiler(spoiler_id, spoiler_button_id) {
    const spoiler = document.getElementById(spoiler_id);
    const button = document.getElementById(spoiler_button_id);

    let visible = false;
    if (spoiler.classList.contains('show')) {
        spoiler.classList.remove('show');
    } else {
        spoiler.classList.add('show');
        visible = true;
    }

    if (visible && spoiler.classList.contains('no-select')) {
        spoiler.classList.remove('no-select');
    } else if (!visible && !spoiler.classList.contains('no-select')) {
        spoiler.classList.add('no-select');
    }

    if (visible) {
        button.textContent = 'Hide Content';
    } else {
        button.textContent = 'Show Content';
    }

    if (window.getSelection) {
        window.getSelection().removeAllRanges();
    } else if (document.selection) {
        document.selection.empty();
    }
}

function copy_to_clipboard(button, code_id) {
    const text_area = document.createElement('textarea');

    text_area.style.display = 'none';
    text_area.value = document.getElementById(code_id).innerText;

    document.body.appendChild(text_area);
    text_area.select();

    navigator.clipboard.writeText(text_area.value).then(() => {
        button.style.backgroundColor = '#28a745';
    }).catch(err => {
        console.error('Failed to copy text: ', err);
    }).finally(() => {
        document.body.removeChild(text_area);
    });

    setTimeout(() => {
        button.style.backgroundColor = '';
    }, 2000);
}
)";
}