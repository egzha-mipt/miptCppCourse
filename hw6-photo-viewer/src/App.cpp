#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <fstream>
#include "../include/App.hpp"
#include "../include/BaseWindows.hpp"
#include "../include/BaseContainers.hpp"

void log(const std::string& message, std::ofstream& logFile)
{
    logFile << message << std::endl;
}

App::App()
    : sprite(texture)
{
    sf::VideoMode mode({1200, 600});
    std::string windowTitle = "1st Window";
    std::string containerTitle = "1st Container";

    window1 = std::make_unique<BaseWindow>(mode, windowTitle);
    container1 = std::make_unique<BaseContainer>(mode, containerTitle);
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