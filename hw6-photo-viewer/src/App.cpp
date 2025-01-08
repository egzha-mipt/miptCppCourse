#include "../include/App.hpp"

App::App()
{
    sf::VideoMode modeStandart({1980, 1080});
    sf::VideoMode modeSquare({600, 600});
    std::string imageContainerTitle = "Image Container";

    imageContainerMain = std::make_unique<ImageContainer>(modeStandart, imageContainerTitle);
}

App::~App() {}

void App::run() {
    imageContainerMain->openWindow();
}
