#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <fstream>
#include "../include/App.hpp"
#include "../include/BaseWindows.hpp"

void log(const std::string& message, std::ofstream& logFile)
{
    logFile << message << std::endl;
}

App::App()
    : window(sf::VideoMode({1200, 600}), "Window")
    , texture("shion_and_naruto_wallpaper.bmp")
    , sprite(texture)
{
    sf::VideoMode mode({1200, 600});
    std::string windowTitle = "1st Window";
    window1 = std::make_unique<BaseWindow>(mode, windowTitle);
}

App::~App()
{
    logFile.close();
}

void App::run()
{
    window1->openWindow();
}