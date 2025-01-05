#include <Sites.hpp>
#include <Templates.hpp>

static constexpr int body_div_id = 1;

bygg::HTML::Section Sites::get_index_site() {
    using namespace bygg::HTML;
    Section container = Templates::get_generic_base_body();
    Section& content = container.at_section(body_div_id);

    content += Element{Tag::Img, make_properties(Property{"id", "index-img"}, Property{"src", "/img/picture.jpeg"}, Property{"alt", "Me"}, Property{"width", "60%"}, Property{"height", "60%"}, Property{"style", "border-radius: 10px; margin: 0 auto; display: block;"})};
    content += Element{Tag::H1, Property{"id", "hello-world-h1"}, "Hello world!"};
    content += Element{Tag::P, Property{"id", "index-p-1"}, R"(
                Welcome to Jacob Nilsson's website! I'm an 18 year old student from Sweden interested in
                computers, programming, politics and whatever else I happen to find interest in.
                <a href="about.html">Read more about me.</a>
            )"};
    content += Element{Tag::H1, Property{"id", "projects-h1"}, "Projects"};
    content += Element{Tag::P, Property{"id", "my-projects-p"}, "Here are some of the projects I've worked on:"};
    content += Templates::get_grid({
        Templates::get_project_preview({.title = "bygg", .description = "A component-based HTML/CSS builder for C++. Powers this website.", .location = "/bygg.html"}),
        Templates::get_project_preview({.title = "biner", .description = "Command-line utility for combining and separating text files", .location = "https://git.jacobnilsson.com/jacob/biner"}),
    });
    content += Templates::get_grid({
        Templates::get_project_preview({.title = "pass2passwords", .description = "GNU Pass to macOS Passwords converter.", .location = "https://git.jacobnilsson.com/jacob/pass2passwords"}),
        Templates::get_project_preview({.title = "AntiReceiverBuzz", .description = "Tiny app preventing unwanted noise on macOS with receivers & amplifiers.", .location = "https://git.jacobnilsson.com/jacob/AntiReceiverBuzz"}),
    });
    content += Element{Tag::P, Property{"id", "more-projects-p"}, "<em>For more projects, see my Git server and GitHub.</em>"};
    content += Element{Tag::H1, Property{"id", "contact-h1"}, "Contact"};
    content += Element{Tag::P, Property{"id", "contact-p"}, "You can contact me using any of the following methods:"};
    content += Templates::get_image_link({.mode = Templates::Mode::Any, .image_location = "/img/git.svg", .text = "Git server", .location = "https://git.jacobnilsson.com/jacob", .alt = "Git Logo"});
    content += Templates::get_image_link({.mode = Templates::Mode::Any, .image_location = "/img/mail.svg", .text = "Email me", .location = "mailto:jacob@jacobnilsson.com", .alt = "Email Logo"});
    content += Templates::get_image_link({.mode = Templates::Mode::Any, .image_location = "/img/bsky.svg", .text = "Bluesky", .location = "https://bsky.app/profile/jacobnilsson.com", .alt = "Bluesky Logo"});
    content += Templates::get_image_link({.mode = Templates::Mode::Light, .image_location = "/img/github-black.svg", .text = "GitHub", .location = "https://github.com/jcbnilsson", .alt = "GitHub Logo"});
    content += Templates::get_image_link({.mode = Templates::Mode::Dark, .image_location = "/img/github-white.svg", .text = "GitHub", .location = "https://github.com/jcbnilsson", .alt = "GitHub Logo"});
    content += Element{Tag::P, Property{"id", "contact-p-2"}, "<em>I also have a Discord. If you want to contact me on there, please email me first.</em>"};

    return container;
}

bygg::HTML::Section Sites::get_about_me_site() {
    using namespace bygg::HTML;
    Section container = Templates::get_generic_base_body();
    Section& content = container.at_section(body_div_id);

    content += Element{Tag::H1, Property{"id", "about-me-h1"}, "About me"};
    content += Element{Tag::P, "I’m Jacob Nilsson, an 18 year old student, programmer, whatever. I was born in Gothenburg, Sweden on the 7th of September 2006 and lived there until 2016. Now I live in Skåne and study technology in Malmö."};
    content += Element{Tag::P, "I’m interested in computers, programming, politics and other nerdy things. I've also dabbled in system administration, but it's not something I enjoy very much."};
    content += Element{Tag::H2, Property{"id", "computers"}, "Computers"};
    content += Element{Tag::P, "I’ve enjoyed computers for as long as I can remember, they were always really fun to tinker with. My programming interest really peaked from hacking a little game known as Growtopia. I would use a program to modify memory addresses for the game, and eventually I started writing small programs."};
    content += Element{Tag::P, "Now, I mainly work with C and C++, but I’ve also worked with HTML/CSS, PHP, SQL, Python and Swift in the past. As of now, C++ is my favorite programming language, and I use it for most of my projects, including the website you’re currently on."};
    content += Element{Tag::H2, Property{"id", "games"}, "Video games"};
    content += Element{Tag::P, "I’ve played a (then) small video game called Geometry Dash since October of 2013. Although I’m not a professional by any means, I have thousands of hours on the game and hundreds of completed demons. Although I don't have that much time to play anymore, I still enjoy the game occasionally. I have a huge backlog of demon completions, mostly from the 1.9 era which I loved the most."};
    content += Element{Tag::P, "Aside from that, I'm a fan of Nintendo games and consoles, and I've been an active member of the Wii homebrew scene in the past."};
    content += Element{Tag::H2, Property{"id", "politics"}, "Politics"};
    content += Templates::get_spoiler(Section{Tag::Empty_No_Formatting,
        Element{Tag::P, "I’m slightly interested in politics, but mostly because of concern for my country. Although I'm not loyal to any party, I generally have nationalist views, and I believe in conserving the Swedish culture, traditions, language and system. I strongly believe in individual freedoms and rights, and I support lower taxes for all groups as well as spending cuts in the public sector, where I believe there is a lot of waste."},
        Element{Tag::P, "I'm in favor of the Swedish monarchy, but only because it's a part of our culture and history and only as a ceremonial role."},
        Element{Tag::P, "I'm strongly against the European Union, because I believe it's a threat to our sovereignty and democracy. I believe our own people through our own government should decide our laws and regulations and never some foreign entity whom we can't vote out."},
        Element{Tag::P, "On the other hand, I'm in favor of NATO, because it's a good way to keep peace in Europe, and the organization doesn't impose laws on us."},
    });
    content += Element{Tag::H2, Property{"id", "this-website"}, "This website"};
    content += Element{Tag::P, "This website is made up of standard HTML, CSS, and JavaScript. But the HTML and CSS are generated before deployment using C++ and the bygg library."};
    content += Element{Tag::P, "The source code for the website is all yours to mess around with, take inspiration from or contribute to (codebase cleanups and grammar fixes are always welcome). You can find the source code on my Git server <a href=\"https://git.jacobnilsson.com/jacob/jacobnilsson.com\">here</a>."};
    content += Element{Tag::P, "The website is currently self-hosted in Sweden on Debian with Apache2. Domain is provided by Namecheap. The TLS certificate is provided by Let's Encrypt/certbot."};
    content += Element{Tag::P, "Please see the README in the Git repository for copyright information."};

    return container;
}

bygg::HTML::Section Sites::get_blog_site() {
    using namespace bygg::HTML;
    Section container = Templates::get_generic_base_body();
    Section& content = container.at_section(body_div_id);

    content += Element{Tag::H1, Property{"id", "blog-h1"}, "Blog"};
    content += Element{Tag::P, "I like to write blog posts about things I find interesting sometimes."};
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

    content += Element{Tag::P, "Naturally, I grudglingly started looking for alternatives when I realized that Doppler wasn’t going to cut it. Unfortunately, it seems that these alternatives absolutely suck. There are a few contenders, but usually they have their own issues, such as format support, terrible UI, or they are subscription based. I’m happy to pay for a good piece of software, as a developer myself I realize that there’s love and effort put into it, but I don’t want a subscription for a product that, realistically, does not have a recurring cost. It is a piece of software which doesn’t connect to the internet, there is no reason for it to be subscription based."};
    content += Element{Tag::P, "I’m still looking for a good alternative, but it looks rather bleak. I’m mostly using my Mac for music at this point but it would be great to just be able to use my phone for such a simple task. If you know of any alternatives, please contact me. I’m not interested in streaming services, I want to play my own music. I’m not interested in converting my entire library, and I’m not interested in using some client/server based solution. I just want to play my music, using a standard SMB file share. I don’t mind paying for it either, as long as it’s a one time purchase."};

    content += Element{Tag::H2, Property{"id", "conclusion"}, "Conclusion"};

    content += Element{Tag::P, "I don’t know what the point of this was, I just really wanted to note down my thoughts on this. If you’ve had a similar experience to me, I’d love to hear about it."};
    content += Element{Tag::P, "Thank you for reading this pretty wordy rant. Have a great day!"};

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
    content += Element{Tag::P, "In addition, the website you're currently on is generated using bygg. The source code for the website is available on my Git server."};
    content += Element{Tag::H2, Property{"id", "learn-more"}, "Learn more"};
    content += Element{Tag::P, "You can learn more about bygg by visiting the <a href=\"https://git.jacobnilsson.com/jacob/bygg\">Git repository</a>."};
    content += Element{Tag::P, "Tarball releases are also available, but may not be up-to-date."};
    content += Element{Tag::P, "Documentation may be generated using Doxygen by running <code>cd docs; doxygen</code> in the repository root."};

    return container;
}
