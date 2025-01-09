#pragma once 

#include <SFML/Graphics.hpp>
#include <string>

class BaseWindow {
public:
    BaseWindow(sf::VideoMode mode, std::string windowName);
    virtual ~BaseWindow();
    
    virtual void openWindow() = 0;

protected:
    sf::VideoMode mode;
    std::string windowName;
};
