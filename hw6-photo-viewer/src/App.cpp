#include "../include/App.hpp"

App::App()
{
    sf::VideoMode modeHd({1280, 720});
    sf::VideoMode modeSquare({500, 500});
    std::string imageContainerTitle = "Image Container";
    std::string baseContainerTitle = "Base Container";

    imageContainerMain = std::make_unique<ImageContainer>(modeHd, imageContainerTitle);
    baseContainerMain = std::make_unique<BaseContainer>(modeSquare, baseContainerTitle);
}

App::~App() {}

void App::run() {
    imageContainerMain->openWindow();
    baseContainerMain->openWindow();
}

// void App::run() { // костыльный метод
//     imageContainerMain->~ImageContainer();
//     baseContainerMain->openWindow();
// }
