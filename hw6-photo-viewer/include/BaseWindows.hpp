#pragma once 

#include <SFML/Graphics.hpp>
#include <string>

class BaseWindow{
public:
    BaseWindow(sf::VideoMode& mode, std::string& windowName);
    virtual ~BaseWindow();
    
    virtual void openWindow();
    virtual void clearWindow();
    void displayOnWindow();

protected:
    sf::RenderWindow window; 
};   