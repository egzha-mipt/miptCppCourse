cmake_minimum_required(VERSION 3.30)

project(photo-viewer)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

FetchContent_Declare(
    SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.2
)

FetchContent_MakeAvailable(SFML)

add_executable(hw6-photo-viewer src/App.cpp)

target_link_libraries(hw6-photo-viewer sfml-graphics sfml-window sfml-system)

if (WIN32)
    set(SFML_DLL_DIR "${CMAKE_BINARY_DIR}/_deps/sfml-build/lib/Debug")
    add_custom_command(TARGET hw6-photo-viewer POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            "${SFML_DLL_DIR}/sfml-graphics-d-2.dll"
            "${SFML_DLL_DIR}/sfml-window-d-2.dll"
            "${SFML_DLL_DIR}/sfml-system-d-2.dll"
            $<TARGET_FILE_DIR:hw6-photo-viewer>
    )
endif()