# jacobnilsson.com

This repository contains the source code that generates HTML
on jacobnilsson.com. It not only serves as the code that generates
the content you see on the website, but also as an example for how the
bygg library may be utilized to generate HTML content.

Please note that this is **not** a generalized website generator. It is
specifically tailored to my needs, and the functions and classes are filled
with my content. Feel free to use this repository as a reference, but it is
not intended to be a general-purpose website generator.

## Building

To build the website, you will need to have the bygg library installed.
You will also need a C++20 compiler and CMake. You will also need MinifyJS
installed, if you want minified JavaScript files. You can install MinifyJS
by running `npm install minify -g`.
Once you have these dependencies installed, you can build the website by running 
the following commands:

```bash
mkdir build
cd build
cmake ..
cmake --build .
```

Running the resulting `jacobnilsson.com` binary will generate the HTML files in 
the `build` directory. You can then copy these files to your web server to host 
the website. CMake can integrate this into the build process for you, if your 
server supports ssh. To do this, you will need to specify the following CMake variables:

- -DINSTALL_HTML=ON
- -DIP_ADDRESS=your.server.ip.address.or.hostname
- -DLOCATION=/path/to/html/directory
- -DUSERNAME=your-ssh-username

e.g. 

```bash
cmake -DINSTALL_HTML=ON -DIP_ADDRESS=example.com -DLOCATION=/var/www/html -DUSERNAME=jacob ..
```

I recommend using a VPN or Tailscale if you're not always on LAN, for convenience.

Of course, you will need to have ssh access to your server. Your server (naturally)
needs to have a web server running, and you need to have write access to the directory
where the HTML files will be installed.

Note that the program expects the `fonts/` directory to be in the same directory as the
executable, or the parent directory of the executable. This is because the program
will copy the fonts to the output directory. If not, the program will throw an exception.
Therefore, you must move the `fonts/` directory if you move the executable.

## My test environment

I develop mainly on a Mac running the latest macOS version. I use CLion as my IDE, and
of course CMake is the build system. I'm testing with the Clang compiler.

I like to set up a web server on my Mac to test the website locally. I use Homebrew
to do this, along with the included script.

```bash
brew install nginx
brew services start nginx
```

Then when I set up my CMake build, I call it with these parameters:

```bash
cmake -DINSTALL_HTML=ON -DIP_ADDRESS=localhost -DLOCATION=/usr/local/var/www -DUSERNAME=jacob ..
```

This will install the HTML files in the default nginx directory, and I can access the
website by going to `http://localhost:8080` in my web browser.

I've chosen to do it this way, because CLion's built in web server doesn't seem to provide a way
to change the virtual root directory. And if you don't change the virtual root directory, you
can't use relative paths in your HTML files, which is a pain, even with bygg which doesn't
provide any way to correct relative paths at compile time. (Maybe that's worth implementing?)

As for deploying, I do it in the exact same manner as shown above, except I use my server's IP
address instead.

## Contributions

Contributions to fix e.g. typos, or just general improvements to the code are welcome.
Please avoid submitting pull requests that attempt to generalize the code, unless
you have a good justification for doing so.

## License

The code in this repository is licensed under the MIT license. The bygg library utilized
in this library is also licensed under the MIT license. 

Fonts included (Open Sans) are  licensed under the SIL Open Font License.

Content on jacobnilsson.com is licensed under the Creative Commons Attribution 4.0 Share Alike license
unless otherwise noted or copyrighted by a third party.

Copyright (C) 2024-2025 Jacob Nilsson