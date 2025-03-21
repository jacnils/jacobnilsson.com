cmake_minimum_required(VERSION 3.1...3.29)

project(jacobnilsson.com VERSION 0.0.1)

set_property(GLOBAL PROPERTY CXX_STANDARD 20)

if (NOT DEFINED INSTALL_HTML)
    set(INSTALL_HTML OFF)
endif()

if (NOT DEFINED IP_ADDRESS)
    set(INSTALL_HTML OFF)
endif()

if (NOT DEFINED LOCATION)
    set(LOCATION "/var/www/html/jacobnilsson.com")
endif()

if (NOT DEFINED USERNAME)
    set(USERNAME "")
endif()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(PROJECT_SOURCE_FILES
        include/Sites.hpp
        include/Stylesheets.hpp
        include/Scripts.hpp
        include/Templates.hpp
        src/Sites.cpp
        src/Templates.cpp
        src/Stylesheets.cpp
        src/Scripts.cpp
        src/main.cpp
)

include_directories(include)

find_package(bygg REQUIRED)

add_executable(${PROJECT_NAME} ${PROJECT_SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} PRIVATE
        bygg::bygg
)

if (INSTALL_HTML AND IP_ADDRESS AND LOCATION)
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E env
            "USERNAME=${USERNAME}"
            "IP_ADDRESS=${IP_ADDRESS}"
            "LOCATION=${LOCATION}"
            "BIN=${CMAKE_BINARY_DIR}/${PROJECT_NAME}"
            ${CMAKE_SOURCE_DIR}/sh/install.sh
            COMMENT "Running install script"
    )
endif()