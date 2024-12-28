#pragma once

#include <string>
#include <fstream>
#include <SFML/Graphics.hpp>
#include "../include/BaseWindows.hpp"
#include "../include/BaseContainers.hpp"   
#include "../include/ImageContainer.hpp"

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
    std::unique_ptr<BaseContainer> container1;
    std::unique_ptr<ImageContainer> imageContainer;

    sf::RenderWindow window;
    sf::Texture texture;
    // sf::Sprite sprite;
    // BaseWindow* window1;
};

