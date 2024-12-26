#pragma once

#include <string>
#include <fstream>
#include <SFML/Graphics.hpp>
#include "../include/BaseWindows.hpp"

class App
{
public:
    App();
    ~App();

    void run();
    
private:
    void log(const std::string& message, std::ofstream& logFile);

private:
    std::ofstream logFile;
    std::unique_ptr<BaseWindow> window1;

    sf::RenderWindow window;
    sf::Texture texture;
    sf::Sprite sprite;
    // BaseWindow* window1;
};

