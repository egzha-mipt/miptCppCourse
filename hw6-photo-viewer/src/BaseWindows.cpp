#pragma once 

#include <SFML/Graphics.hpp>
#include <string>
#include "../include/BaseWindows.hpp"

BaseWindow::BaseWindow(sf::VideoMode& mode, std::string& windowName)
: window(mode, windowName){

};

BaseWindow::~BaseWindow(){};

void BaseWindow::clearWindow(){
    window.clear(sf::Color::Black);
};

void BaseWindow::displayOnWindow(){
    window.display();
};

void BaseWindow::openWindow(){
    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();       
        }
    }

    void clearWindow();

    void displayOnWindow();
}

