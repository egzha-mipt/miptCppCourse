#pragma once 

#include <SFML/Graphics.hpp>
#include <string>

class BaseWindow {
public:
    BaseWindow(sf::VideoMode mode, std::string windowName);
    virtual ~BaseWindow();
    
    virtual void openWindow() = 0;  // Теперь это чисто виртуальный метод

protected:
    sf::VideoMode mode;            // Храним параметры для окна
    std::string windowName;        // Название окна
};
