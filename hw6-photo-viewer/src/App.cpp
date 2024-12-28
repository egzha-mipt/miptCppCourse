#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <fstream>
#include "../include/App.hpp"
#include "../include/BaseWindows.hpp"
#include "../include/BaseContainers.hpp"
#include "../include/ImageContainer.hpp"

void log(const std::string& message, std::ofstream& logFile)
{
    logFile << message << std::endl;
}

App::App()
{
    sf::Texture texture("shion_and_naruto_wallpaper.bmp");
    sf::Sprite sprite(texture);
    sf::VideoMode mode({1200, 600});
    sf::VideoMode modeSquare({600, 600});
    std::string windowTitle = "1st Window";
    std::string containerTitle = "1st Container";
    std::string imageContainerTitle = "Image Container";

    window1 = std::make_unique<BaseWindow>(mode, windowTitle);
    container1 = std::make_unique<BaseContainer>(modeSquare, containerTitle);
    imageContainer = std::make_unique<ImageContainer>(mode, imageContainerTitle);
}

App::~App()
{
    logFile.close();
}

void App::run()
{
    window1->openWindow();
    container1->openWindow();
}