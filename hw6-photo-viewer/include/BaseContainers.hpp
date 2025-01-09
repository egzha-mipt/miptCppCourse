#pragma once 

#include <SFML/Graphics.hpp>
#include <string>
#include "../include/BaseWindows.hpp"

class BaseContainer : public BaseWindow {
public:
    BaseContainer(sf::VideoMode mode, std::string containerName);
    ~BaseContainer();
    void openWindow() override;

protected:
    sf::RenderWindow window;  
};
