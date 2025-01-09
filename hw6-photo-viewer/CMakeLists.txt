cmake_minimum_required(VERSION 3.30)

project(photo-viewer CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(RESOURCE_FILE "assets/shion_and_naruto_wallpaper.bmp")

include(FetchContent)

FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.0
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

add_executable(hw6-photo-viewer 
    src/main.cpp    
    src/App.cpp
    src/BaseWindows.cpp
    src/BaseContainers.cpp
    src/ImageContainer.cpp
)

add_custom_command(
    TARGET hw6-photo-viewer
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
        ${CMAKE_CURRENT_SOURCE_DIR}/${RESOURCE_FILE}
        ${CMAKE_BINARY_DIR}/bin/debug
    COMMENT "Copying resource file"
)

target_link_libraries(hw6-photo-viewer PRIVATE SFML::Graphics SFML::Window)