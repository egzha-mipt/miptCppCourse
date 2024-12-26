#pragma once 

#include <SFML/Graphics.hpp>
#include <string>

class BaseWindow{
public:
    BaseWindow(sf::VideoMode& mode, std::string& windowName);
    ~BaseWindow();
    
    void openWindow();
    void clearWindow();
    void displayOnWindow();

protected:
    sf::RenderWindow window; 
};   