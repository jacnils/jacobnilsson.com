#include <string>
#include <Scripts.hpp>

std::string Scripts::get_script() {
    return R"(
window.addEventListener('load', function() {
    const footer = document.querySelector('footer');
    const body = document.body;
    const nav_bar = document.querySelector('.nav-links');

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
    const code_block = document.getElementById(code_id);
    const text_area = document.createElement('textarea');

    text_area.value = code_block.textContent;

    document.body.appendChild(text_area);

    text_area.select();

    document.execCommand('copy');
    document.body.removeChild(text_area);

    button.textContent = 'Copied!';

    setTimeout(() => {
        button.textContent = 'Copy';
    }, 2000);
}
)";
}