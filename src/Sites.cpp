#include <Sites.hpp>
#include <Templates.hpp>

static constexpr int body_div_id = 1;
static constexpr int swedish_body_div_id = 2;

bygg::HTML::Section Sites::get_about_me_site() {
    using namespace bygg::HTML;
    Section container = Templates::get_generic_base_body();
    Section& content = container.at_section(body_div_id);

    content += {
        Element{Tag::H1, Property{"id", "index-p-1"}, ""},
    };

    Section& swedish_content = container.at_section(swedish_body_div_id);

    swedish_content += {
        Element{Tag::H1, Property{"id", "sv-index-p-1"}, ""},
    };

    return container;
}


bygg::HTML::Section Sites::get_index_site() {
    using namespace bygg::HTML;
    Section container = Templates::get_generic_base_body();
    Section& content = container.at_section(body_div_id);

    content += Element{Tag::H1, Property{"id", "hello-world-h1"}, "Hello world!"};
    content += Element{Tag::P, Property{"id", "index-p-1"}, R"(
                Welcome to Jacob Nilsson's website! I'm an 19 year old from Sweden interested in
                computers, programming and whatever else I happen to find interest in.
                <a href="about.html">Read more about me.</a>
            )"};
    content += Element{Tag::H1, Property{"id", "projects-h1"}, "Projects"};
    content += Element{Tag::P, Property{"id", "my-projects-p"}, "Here are some of the projects I've worked on:"};
    content += Templates::get_grid({
        Templates::get_project_preview({
            .title = "netkit",
            .description = "C99 and C++23 cross-platform networking toolkit library providing safe Unix-style sockets and protocol abstractions.",
            .location = "https://github.com/jacnils/netkit",
        }),
        Templates::get_project_preview({
            .title = "bygg",
            .description = "A component-based HTML/CSS builder for C++. Powers this website.",
            .location = "/bygg.html",
        }),
    });
    content += Templates::get_grid({
        Templates::get_project_preview({
            .title = "pass2passwords",
            .description = "GNU Pass to macOS Passwords converter.",
            .location = "https://github.com/jacnils/pass2passwords",
        }),
        Templates::get_project_preview({
            .title = "AntiReceiverBuzz",
            .description = "Tiny app preventing unwanted noise on macOS with receivers & amplifiers.",
            .location = "https://github.com/jacnils/AntiReceiverBuzz",
        }),
    });
    content += Element{Tag::P, Property{"id", "more-projects-p"}, "<em>For more projects, see my GitHub.</em>"};
    content += Element{Tag::H1, Property{"id", "contact-h1"}, "Contact"};
    content += Element{Tag::P, Property{"id", "contact-p"}, "You can contact me using any of the following methods:"};
    content += Templates::get_image_link_preview({
        .mode = Templates::Mode::Any, .image_location = "/img/mail.svg", .text = "Email me",
        .location = "mailto:jacob@jacobnilsson.com", .alt = "Email Logo"
    });
    content += Templates::get_image_link_preview({
        .mode = Templates::Mode::Light, .image_location = "/img/github-black.svg", .text = "GitHub",
        .location = "https://github.com/jacnils", .alt = "GitHub Logo"
    });
    content += Templates::get_image_link_preview({
        .mode = Templates::Mode::Dark, .image_location = "/img/github-white.svg", .text = "GitHub",
        .location = "https://github.com/jacnils", .alt = "GitHub Logo"
    });
    content += Templates::get_image_link_preview({.mode = Templates::Mode::Any, .image_location = "/img/youtube.svg", .text = "YouTube", .location = "https://youtube.com/@jacobnilssoncom", .alt = "YouTube Logo"});
    content += Element{Tag::P, Property{"id", "contact-p-2"}, "<em>I also have a Discord. If you want to contact me on there, please email me first.</em>"};

    Section& swedish_content = container.at_section(swedish_body_div_id);

    swedish_content += Element{Tag::H1, Property{"id", "sv-hello-world-h1"}, "Hej!"};
    swedish_content += Element{Tag::P, Property{"id", "sv-index-p-1"}, R"(
                Välkommen till Jacob Nilssons webbplats! Jag är en 19-åring från Sverige intresserad av
                datorer, programmering och diverse andra saker.
                <a href="about.html">Läs mer om mig.</a>
            )"};
    swedish_content += Element{Tag::H1, Property{"id", "sv-projects-h1"}, "Projekt"};
    swedish_content += Element{Tag::P, Property{"id", "sv-my-projects-p"}, "Här är några av projekten jag har arbetat på:"};
    swedish_content += Templates::get_grid({
        Templates::get_project_preview({.title = "bygg", .description = "En komponentbaserad HTML/CSS-byggare för C++. Används till bland annat denna webbsidan.", .location = "/bygg.html"}),
        Templates::get_project_preview({.title = "biner", .description = "Verktyg för att kombinera och separera textfiler", .location = "https://github.com/jacnils/biner"}),
    });
    swedish_content += Templates::get_grid({
        Templates::get_project_preview({.title = "pass2passwords", .description = "GNU Pass till macOS Lösenord konverterare.", .location = "https://github.com/jacnils/pass2passwords"}),
        Templates::get_project_preview({.title = "AntiReceiverBuzz", .description = "Liten app som förhindrar oönskat ljud på macOS med mottagare och förstärkare.", .location = "https://github.com/jacnils/AntiReceiverBuzz"}),
    });
    swedish_content += Element{Tag::P, Property{"id", "sv-more-projects-p"}, "<em>För fler projekt, se min Git-server och GitHub.</em>"};
    swedish_content += Element{Tag::H1, Property{"id", "sv-contact-h1"}, "Kontakt"};
    swedish_content += Element{Tag::P, Property{"id", "sv-contact-p"}, "Du kan kontakta mig på följande sätt:"};
    swedish_content += Templates::get_image_link_preview({.mode = Templates::Mode::Any, .image_location = "/img/mail.svg", .text = "E-post", .location = "mailto:jacob@jacobnilsson.com", .alt = "Email Logo"});
    swedish_content += Templates::get_image_link_preview({.mode = Templates::Mode::Light, .image_location = "/img/github-black.svg", .text = "GitHub", .location = "https://github.com/jacnils", .alt = "GitHub Logo"});
    swedish_content += Templates::get_image_link_preview({.mode = Templates::Mode::Dark, .image_location = "/img/github-white.svg", .text = "GitHub", .location = "https://github.com/jacnils", .alt = "GitHub Logo"});
    swedish_content += Templates::get_image_link_preview({.mode = Templates::Mode::Any, .image_location = "/img/youtube.svg", .text = "YouTube", .location = "https://youtube.com/@jacobnilssoncom", .alt = "YouTube Logo"});
    swedish_content += Element{Tag::P, Property{"id", "sv-contact-p-2"}, "<em>Jag har också en Discord. Om du vill kontakta mig där, vänligen skicka ett e-postmeddelande först.</em>"};

    return container;
}

bygg::HTML::Section Sites::get_settings_site() {
    using namespace bygg::HTML;
    Section container = Templates::get_generic_base_body();
    Section& content = container.at_section(body_div_id);

    content += Element{Tag::H1, Property{"id", "settings-h1"}, "Settings"};
    content += Element{Tag::H2, Property{"id", "language-h2"}, "Language"};
    content += Section{Tag::Select, Property{"class", "language-select"},
        Element{Tag::Option, Property{"value", "en"}, "English"},
        Element{Tag::Option, Property{"value", "sv"}, "Svenska"},
    };
    content += Element{Tag::P, Property{"id", "settings-p"}, "If the specific page is unavailable in your preferred language, the website will default to English (or whichever language is available.)"};

    Section& swedish_content = container.at_section(swedish_body_div_id);

    swedish_content += Element{Tag::H1, Property{"id", "settings-h1"}, "Inställningar"};
    swedish_content += Element{Tag::H2, Property{"id", "language-h2"}, "Språk"};
    swedish_content += Section{Tag::Select, Property{"class", "language-select"},
        Element{Tag::Option, Property{"value", "en"}, "English"},
        Element{Tag::Option, Property{"value", "sv"}, "Svenska"},
    };
    swedish_content += Element{Tag::P, Property{"id", "settings-p"}, "Om den specifika sidan inte är tillgänglig på ditt föredragna språk, kommer webbplatsen att använda engelska (eller det språk som är tillgängligt.)"};

    return container;
}

bygg::HTML::Section Sites::get_blog_site() {
    using namespace bygg::HTML;
    Section container = Templates::get_generic_base_body();
    Section& content = container.at_section(body_div_id);

    content += Element{Tag::H1, Property{"id", "blog-h1"}, "Blog"};
    content += Element{Tag::P, "I like to write blog posts about things I find interesting sometimes."};
    content += Templates::get_blogpost_preview({
        .title = "Reassigning Your Email: The Hidden Vulnerability",
        .author = "Jacob Nilsson",
        .date = "2025-03-16",
        .tags = "Development,Authentication,Vulnerability,Security,Email,Services,Technology,Computers",
        .description = "I recently discovered a vulnerability...ish, in the way email addresses are handled by some services. It's a rather simple vulnerability, but it can have serious consequences.",
        .location = "/blog/reassigning-your-email-the-hidden-vulnerability.html",
    });
    content += Templates::get_blogpost_preview({
        .title = "Rant: The sad state of music hoarding on iOS",
        .author = "Jacob Nilsson",
        .date = "2024-11-25",
        .tags = "Music, Music players, macOS, iOS, Apple, Doppler, Rant, Technology, Computers",
        .description = "I'm the one weirdo who prefers digital music, but in the form of files, and not streaming. Asterisk, because I do stream music, it's just that it's from my own collection through SMB. This solution works great for me, especially since I'm almost always connected to a good internet connection and I have unlimited 5G data. Even the large FLAC files stream without a hitch. It works great on my Mac, or any device really. You can just open a file as if it's a local file and it will start playing.",
        .location = "/blog/the-sad-state-of-music-hoarding-on-ios.html",
    });
    content += Templates::get_blogpost_preview({
        .title = "macOS Passwords app crash bug",
        .author = "Jacob Nilsson",
        .date = "2024-11-09",
        .tags = "Technology, Computers, macOS, Mac, Bug, Apple",
        .description = "A while ago I discovered a pretty silly bug in macOS’s brand new Passwords app. If you’re not aware, it was introduced in the new macOS version - Sequoia. I’m rather surprised this one slipped through the cracks, because it really isn’t hard at all to find, and can be consistently replicated too.",
        .location = "/blog/macos-passwords-app-crash-bug.html",
    });

    return container;
}

bygg::HTML::Section Sites::get_macos_passwords_app_crash_bug() {
    using namespace bygg::HTML;
    Section container = Templates::get_generic_base_body();
    Section& content = container.at_section(body_div_id);

    content += Templates::get_blogpost_header({
        .title = "macOS Passwords app crash bug",
        .author = "Jacob Nilsson",
        .date = "2024-11-09",
        .tags = "Technology, Computers, macOS, Mac, Bug, Apple",
    });

    content += Element{Tag::P, "A while ago I discovered a pretty silly bug in macOS’s brand new Passwords app. If you’re not aware, it was introduced in the new macOS version - Sequoia. I’m rather surprised this one slipped through the cracks, because it really isn’t hard at all to find, and can be consistently replicated too."},
    content += Element{Tag::H2, Property{"id", "otp"}, "OTP"},
    content += Element{Tag::P, "macOS’ Passwords app supports two-factor authentication through so-called OTP generated by the server based on time. The client can poll the server using a special URI that is to be kept secret. It may look something like <code>otpauth://totp/MyService:MyUsername?secret=OAMLLMXDAERTNACELPPANEVE&issuer=MyService</code>."},
    content += Element{Tag::A, Property{"href", "https://en.wikipedia.org/wiki/Time-based_one-time_password"}, "You can read more about TOTP here in case you’re nerdy like me."},
    content += Element{Tag::P, "This kind of two-factor authentication is often used with mobile phones, and mobile phones have cameras. Therefore, a lot of services make use of QR-codes to store the <code>otpauth://...</code> string. It’s more intuitive for the end-user, especially since the end-user often registers for an account on their computer. With this model, the camera takes a picture of the QR-code (which will then be in image format) and the reader attempts to retrieve the string from it."},
    content += Element{Tag::P, "Okay, where were we? Well, macOS' Passwords app allows you to specify an image file to read from when setting up an OTP entry. And, in this case, it would:"};
    content += Templates::get_numbered_list({
        "Open the file",
        "Attempt to read a QR-code contained within",
        "Validate the aforementioned data",
        "Perform all the OTP magic mentioned earlier",
    });
    content += Element{Tag::P, "The image format this QR-code image is in is up to the service responsible for generating the QR-code and can therefore vary greatly. Usually the format is a pretty standard and well-known one, such as PNG, JPG, GIF, etc."},
    content += Element{Tag::H2, Property{"id", "handling-images-programmatically"}, "Handling images programmatically"},
    content += Element{Tag::P, "There are many different image formats, and when you’re writing an app that takes in an image you probably want to provide support for many popular ones. After all, you don’t want the user to have to go out of their way to convert it into the obscure format your program expects. But, as you add support for more formats, the room for error grows significantly."},
    content += Element{Tag::P, "Of course, most of the time you’re not writing all of the code for interpreting the different image formats, that would be wasteful. It’s more likely you’d use a battle-tested library. In C++, you might use <em>libpng</em> to support PNG, <em>libjpeg</em> to support JPEG, <em>libsvg</em> to support SVG, and so on. It is also likely that you would write abstraction around all of this, that is more generalized code that hides all of the details and provides an interface that can be used for any format. In fact, it would surprise me if this is <em>not</em> what Apple does, anything else would be counter-intuitive, wasteful and bug-prone."},
    content += Element{Tag::H2, Property{"id", "the-problem-in-practice"}, "The problem in practice"},
    content += Element{Tag::P, "Creating a password entry in the Passwords app opens a file dialog allowing you to specify an image file. Afterwards, the file will be opened, read, processed and there are two expected outcomes."},
    content += Templates::get_numbered_list({
        "The data retrieved is valid and codes can be generated for the user.",
        "Invalid image. This is likely what will occur if you load a random JPEG or something.",
    });
    content += Element{Tag::P, "As I’ve found however, selecting an image of SVG format will cause the program to crash. It doesn’t matter if the SVG contains a valid QR-code or if it’s a zero-byte file. Because a zero-byte file in SVG format also crashes the app, we can more or less rule out the issue being related to the QR-code processing related functionality. The fact that reading the image yourself with <code>zbarimg</code> and manually specifying the data in the app works perfectly confirms this. That must mean something goes wrong opening and parsing the SVG. That is, of course, understandable if you’ve ever been unfortunate enough to have to bother parsing one of these things."},
    content += Element{Tag::P, "SVGs are interesting because they’re actually ASCII text and <strong>not</strong> binary data that you’d expect from most image formats. In particular, they’re made up of XML data, which can look something like this:"},
    content += Templates::get_codeblock(R"(
<svg xmlns="http://www.w3.org/2000/svg" viewBox="0 0 100 100">
    <path d="M90,18c-90-45-115,102,0,69v-21l4-3h-23l-8,4h16v19c-80,15-65-106,2-63l-4,5l4-1z" fill="#CCC" stroke="#DDD" stroke-width="2" stroke-linejoin="round"/>
    <path d="M87,15c-90-45-115,102,0,69v-21l4-3h-23l-8,4h16v19c-80,15-65-106,2-63l-4,5l4-1z" fill="#00F"/>
</svg>
       )");
    content += Element{Tag::H2, Property{"id", "why-does-it-matter"}, "Why does it matter?"},
    content += Element{Tag::P, "Well, first and foremost, your program crashing because you picked an invalid image is a little rough and not at all the Apple “just works” experience that customers expect, but aside from that there are most likely quite a few services that utilize SVG vectors for their generated QR-codes. In fact, programmatically, it might be the easiest way to generate a QR-code for a given string, and it should be the easiest to read because it can scale to any given size and still produce the same result."},
    content += Element{Tag::P, "GitHub is a notable service that utilizes vectors for their OTP codes, in fact that’s how I discovered this hilarious bug. It would not surprise me if there are many more services that use this format."},
    content += Element{Tag::H2, Property{"id", "closing"}, "Closing"},
    content += Element{Tag::P, "Pretty funny bug, and I’m surprised it slipped through. That definitely raises a question for me though which is, how many more formats are there that produce unexpected behavior like this."},
    content += Element{Tag::P, "If you want to reproduce this, you can repeat the following steps:"},
    content += Templates::get_numbered_list({
        "Obtain or create an SVG of some kind. <code>touch empty.svg</code> does the trick too",
        "Create an entry in the Passwords app",
        "Edit the entry and add an OTP entry",
        "Select the SVG file",
        "Observe the crash",
    });
    content += Element{Tag::P, "If you do try this yourself, please let me know about any interesting findings. If you know more about the topic than I do, feel free to send me an email, I’d love to learn more about it!"};

    return container;
}

bygg::HTML::Section Sites::get_the_sad_state_of_music_hoarding_on_ios() {
    using namespace bygg::HTML;
    Section container = Templates::get_generic_base_body();
    Section& content = container.at_section(body_div_id);

    content += Templates::get_blogpost_header({
        .title = "Rant: The sad state of music hoarding on iOS",
        .author = "Jacob Nilsson",
        .date = "2024-11-25",
        .tags = "Music, Music players, macOS, iOS, Apple, Doppler, Rant, Technology, Computers",
    });

    content += Element{Tag::P, "I’m the one weirdo who prefers digital music, but in the form of files, and not streaming. Asterisk, because I do stream music, it’s just that it’s from my own collection through SMB. This solution works great for me, especially since I’m almost always connected to a good internet connection and I have unlimited 5G data. Even the large FLAC files stream without a hitch. It works great on my Mac, or any device really. You can just open a file as if it’s a local file and it will start playing."};

    content += Element{Tag::H2, Property{"id", "ios-cant-into-files"}, "iOS can’t into files"};

    content += Element{Tag::P, "A while ago I (unintentionally) switched to an iPhone. I was keenly aware of the limitations of iOS, but having used it years prior, and having been an Android user for a while, I wanted to try something new. Getting my phone stolen was a perfect excuse to do so."};
    content += Element{Tag::P, "I wasn’t expecting to say this, but I am pretty happy with this decision, and iOS works great alongside my MacBook. When Apple users talk about the ecosystem, they’re not kidding. It’s a great experience. But there’s one thing that’s been bugging me for YEARS now. iOS straight up doesn’t do files. The Files app, which they introduced several years after they should’ve is about as useful as a painting, because it’s not really even a file manager. It’s a glorified iCloud Drive viewer."};
    content += Element{Tag::P, "Fortunately, you can mount file shares, which seems to be a rather recent addition, but it can be done. There’s still a catch though and that is you cannot mount NFS file shares. This isn’t a huge deal, Android is equally annoying in this regard and some operating systems like Windows cannot do it without an additional program and even then from the command line. So I switched to Samba on my Linux server and that works okay. SMB’s sluggishness is not really all that problematic for me personally, because I have a nice connection most of the time."};

    content += Element{Tag::H2, Property{"id", "the-music-app-sucks"}, "The ‘Music’ app SUCKS"};

    content += Element{Tag::P, "The built in Music app is absolute garbage. It is essentially the reincarnation of iTunes, which was also garbage. But that’s on the Mac, to my knowledge it has always been ‘Music’ on iOS. The worst part is that it doesn’t support FLAC, which means I would be forced to convert my entire library to ALAC just because they couldn’t be bothered to add support for an ubiquitous format that all audiophiles are well aware of."};
    content += Element{Tag::P, "As if that wasn’t enough, the iOS version of the (now) Music app is even more limited than the Mac version. You can’t even play local files AT ALL, nor can you import them. Of course that also means you can’t play files from an SMB share either. That led me to look for other alternatives."};

    content += Element{Tag::H2, Property{"id", "the-hunt-for-a-good-music-player"}, "The hunt for a good music player"};

    content += Element{Tag::P, "After a while using Mac, I was pretty much using VLC. It’s a great <em>media</em> player, but it’s more or less useless for playing music. It’s not a great experience for music in particular."};
    content += Element{Tag::P, "The iOS version of Doppler was <em>so</em> close to perfection, but by missing a few tiny but crucial features, they effectively ruined the app for me. It doesn’t support file shares. Aside from that, the app is EXCELLENT, but instead of playing the files back from the share, it downloads them to the device. This is a huge dealbreaker for me, because I have a lot of music and it certainly wouldn’t fit on my phone. Because of this, I would have to copy the files I want to listen to to my phone, which is a massive undertaking that I don’t want to do every morning when I just want to catch the bus and go."};
    content += Element{Tag::P, "I sent an email to the developer suggesting that they add support for file shares, and I got an automated response that they will look into it. Unfortunately, it doesn’t seem like anything they’re going to do given that it has been requested in the past. They’re instead focusing on what they’re calling Doppler Transfer, which transfers music from your Mac. This is probably great for someone, but not really something that appeals to me. I want something that works great across all my (Apple) devices, and for that I think Doppler should avoid trying to create its own ecosystem. It should just play music, and integrate with Apple services like iCloud when applicable, even though I personally don’t use them."};
    content += Element{Tag::P, "You were so close, Doppler. You were this close to being the perfect music player for Apple users, and then you ruined it by missing the most important feature to music hoarders. And I’m sure music hoarders make up most of your user base anyway, because who else would want to use a music player that doesn’t support streaming services. It’s not even like SMB shares are some advanced feature that only the most advanced users would use, you can quite literally enable it in the settings on your Mac, and it’s not something that requires a proper server. It’s just a checkbox. And you can use it outside of your network too by setting up a VPN, which can even be user friendly if you use Tailscale. It’s quite literally as simple as installing it on both of your devices."};
    content += Element{Tag::P, "Please, add this one feature. I’m sure I can’t be the first person who’s unable to use your app because of this. I’m sure there’s plenty of people who would rather use something like this but instead have to resort to a solution like Plex or Jellyfin, which are great, but use a lot more resources and lock you into their ecosystem."};

    content += Element{Tag::H2, Property{"id", "alternatives"}, "Alternatives"};

    content += Element{Tag::P, "Naturally, I grudgingly started looking for alternatives when I realized that Doppler wasn't going to cut it. Unfortunately, it seems that these alternatives absolutely suck. There are a few contenders, but usually they have their own issues, such as format support, terrible UI, or they are subscription based. I’m happy to pay for a good piece of software, as a developer myself I realize that there’s love and effort put into it, but I don’t want a subscription for a product that, realistically, does not have a recurring cost. It is a piece of software which doesn’t connect to the internet, there is no reason for it to be subscription based."};
    content += Element{Tag::P, "I’m still looking for a good alternative, but it looks rather bleak. I’m mostly using my Mac for music at this point but it would be great to just be able to use my phone for such a simple task. If you know of any alternatives, please contact me. I’m not interested in streaming services, I want to play my own music. I’m not interested in converting my entire library, and I’m not interested in using some client/server based solution. I just want to play my music, using a standard SMB file share. I don’t mind paying for it either, as long as it’s a one time purchase."};

    content += Element{Tag::H2, Property{"id", "conclusion"}, "Conclusion"};

    content += Element{Tag::P, "I don’t know what the point of this was, I just really wanted to note down my thoughts on this. If you’ve had a similar experience to me, I’d love to hear about it."};
    content += Element{Tag::P, "Thank you for reading this pretty wordy rant. Have a great day!"};

    return container;
}

bygg::HTML::Section Sites::get_reassigning_your_email_the_hidden_vulnerability() {
    using namespace bygg::HTML;
    Section container = Templates::get_generic_base_body();
    Section& content = container.at_section(body_div_id);

    content += Templates::get_blogpost_header({
        .title = "Reassigning Your Email: The Hidden Vulnerability",
        .author = "Jacob Nilsson",
        .date = "2025-03-16",
        .tags = "Development,Authentication,Vulnerability,Security,Email,Services,Technology,Computers",
    });

    content += Element{Tag::P, "I highly doubt I'm the first one to discover this, in fact I know I'm not, because *some* services have implemented a very simple solution to this problem. But I think even a single service that doesn't implement this solution is one too many."};
    content += Element{Tag::H2, Property{"id", "the-problem"}, "The Problem"};
    content += Element{Tag::P, "When you sign up for a service, you often have to provide an email address. Sometimes, it's just for verification purposes, other times it's used as the sole means of identification. In the former case, it might not be *as* bad of a problem, but in the latter case, it could cause many issues, both for you but also in cases where the email address is someone else's."};
    content += Element{Tag::P, "Most of the time this isn't a problem. You enter an email address, and receive a verification email to confirm that you own the email address. What if you don't own the email address, or perhaps you made a typo? Fortunately, the service won't let you proceed without a valid, verified email address. Perfect, this solves the problem, right?"};
    content += Element{Tag::P, "But what if we wish to change our email address at a later point? Many services offer some kind of endpoint for changing your email address, and this works provided you still have access to your old email address. If you don't then you usually have to go through the process of proving your identity to the service's support team, which has varying results. If you *do* have access to your old email address, this is a very simple process."};
    content += Element{Tag::H2, Property{"id", "implications"}, "Implications"};
    content += Templates::get_numbered_list({
        "If you make a typo, you'll change your email address to a non-existent one. And then, you can't even change it back because you can't verify the new email address.",
        "If you don't own the email address, you could change it to someone else's. Then they'll be held responsible for **your** account. Further, they'll have substantial evidence that they're the rightful owner of **your** account.",
        "If you're a malicious actor, you could create an account with someone else's email, by creating one with your email and changing it to theirs afterwards.",
    });
    content += Element{Tag::P, "This is a pretty serious issue, but fortunately, it doesn't have all that much potential for harm for anyone else, only really for yourself. The worst you can really do is lock yourself out of your account, or unwillingly assign someone an account on your service, perhaps preventing them from creating an account. But, even if you were to do this, they could log in and delete the account, so it's not a huge issue."};
    content += Element{Tag::P, "Further, even if you changed the email address and don't have access to it, you can most likely still log in with your username and password, so it's not like you're completely locked out of your account. You just can't change your email address. But you're not going to get any verification emails, and for services where you receive an email verification code to log in, there's not much you can do. Fortunately, many services these days opt for other types of verification, such as SMS, TOTP, or even the new-fangled passwordless passkeys."};
    content += Element{Tag::H2, Property{"id", "the-solution"}, "The Solution"};
    content += Element{Tag::P, "The solution is simple. Just like when you sign up, you should have to verify your email address when you change it. This way, you can't change it to a non-existent email address and lose access to your account, or use up someone else's email address. It's a simple solution, and I'm sure it's something that has just been overlooked by the developers of these services. After all, changing your email is not something that happens often, so it's not something that I'd imagine has been tested thoroughly."};
    content += Element{Tag::H2, Property{"id", "help-i-changed-my-email-to-a-non-existent-one"}, "Help, I Changed My Email to a Non-Existent One!"};
    content += Element{Tag::P, "If this is you, there are potential solutions, but the results may certainly vary. If you're using your own domain (e.g. `john@doesoft.com`) you could just create an email address with the typo and change it to the intended address."};
    content += Element{Tag::P, "If you're using a public email service, such as Gmail, Hotmail or Yahoo, you could try to create an email address with the typo, but depending on whether the typo email address is already taken, this may not work for you. In case it doesn't, your best bet would probably be to contact the service in question and ask that they change it back for you. If they refuse, sorry, but you're probably out of luck."};
    content += Element{Tag::H2, Property{"id", "conclusion"}, "Conclusion"};
    content += Element{Tag::P, "Some services allow you to change your email to an unverified email address, which has several serious implications. I urge developers reading this to fix this in their services, if their services are susceptible to this issue."};
    content += Element{Tag::P, "Thank you for reading, have a good day!"};

    return container;
}


bygg::HTML::Section Sites::get_bygg_site() {
    using namespace bygg::HTML;
    Section container = Templates::get_generic_base_body();
    Section& content = container.at_section(body_div_id);

    content += Element{Tag::H1, Property{"id", "bygg-h1"}, "bygg"};
    content += Element{Tag::P, "bygg is a component-based HTML/CSS builder for C++. The library is designed to make it easy to generate HTML and CSS documents in a programmatic way, using C++ code."};
    content += Element{Tag::P, "The library is designed to be easy to use, while being powerful, extensible and modern. Modern STL-style class design and iterators are used throughout the library."};
    content += Templates::get_bulletpoint_list({
        "HTML and CSS document generation and deserialization",
        "Component-based, modular design",
        "C++ pseudo-code generation",
        "Easy to use, with a modern C++ API",
        "Iterator- and reference-based design for easy manipulation and traversal",
        "Sensible indentation for pretty-formatting.",
        "HTML serialization*",
        "No dependencies, other than the standard library*",
        "Command-line tool for generating HTML or pseudocode from HTML or Markdown files*",
        "Windows, macOS, Linux and *BSD support**",
        "MIT License, allowing for commercial use and modification",
        "Tested on Windows, macOS and Linux through GitHub Actions, methods unit-tested before commit",
    });
    content += Element{Tag::P, "*Serialization and CLI requires the use of libxml2, which is not included in this repository. Tests require the use of Catch2, which is not included in this repository. Markdown support requires pandoc to be installed on the system. Pandoc is not included in this repository."};
    content += Element{Tag::P, "**Not tested on BSD. bygg is actively tested on Windows, macOS and Linux through GitHub Actions."},
    content += Element{Tag::H2, Property{"id", "why-bygg"}, "Why bygg?"};
    content += Element{Tag::P, "The goal of bygg was to bring more maintainability to the HTML and CSS writing process. By using a modular, iterative approach, it is possible to write more in less, and prevent code duplication."};
    content += Element{Tag::P, "The library is also very easy to use, and the API is designed to be as intuitive as possible. It is also designed to allow for many different code styles, from verbose to concise, and from object-oriented to functional."};
    content += Element{Tag::H2, Property{"id", "example"}, "Example"};
    content += Element{Tag::P, "In the Git repository, you can find several examples of how to use bygg, both simple and more complex. Here is a simple example of how to generate a simple HTML document:"};
    content += Templates::get_codeblock(R"(
// License: MIT
// Path: examples/hello-world/hello-world.cpp
#include <fstream>
#include <bygg/HTML/HTML.hpp>
#include <bygg/CSS/property.hpp>

int main() {
   using namespace bygg::HTML;
   using CSSProperty = bygg::CSS::Property;

   Section sect{Tag::Html, Properties{Property{"lang", "us"}},
      Section{Tag::Head,
         Element{Tag::Title, "Hello world!"},
         Element{Tag::Meta, Properties{Property{"name", "description"}, Property{"content", "Hello world description!"}}},
         Element{Tag::Meta, Properties{Property{"name", "viewport"}, Property{"content", "width=device-width, initial-scale=1.0"}}},
      },
      Section{Tag::Body,
         Section{Tag::Div, Properties{Property{"class", "content"}},
            Element{Tag::H1, "Hello world!"},
            Element{Tag::P, Properties{Property{"style", static_cast<std::string>(CSSProperty("color", "red"))}}, "This is a red string of text."},
         },
      },
      Section{Tag::Footer,
         Element{Tag::P, "This is a paragraph in a footer."},
      },
   };

   std::ofstream ofs("hello-world.html");

   ofs << sect.get<std::string>(Formatting::Pretty);

   ofs.close();
}
    )");
    content += Element{Tag::P, "In addition, the website you're currently on is generated using bygg. The source code for the website is available on my GitHub."};
    content += Element{Tag::H2, Property{"id", "learn-more"}, "Learn more"};
    content += Element{Tag::P, "You can learn more about bygg by visiting the <a href=\"https://github.com/jacnils/bygg\">Git repository</a>."};
    content += Element{Tag::P, "Tarball releases are also available, but may not be up-to-date."};
    content += Element{Tag::P, "Documentation may be generated using Doxygen by running <code>cd docs; doxygen</code> in the repository root."};

    return container;
}
