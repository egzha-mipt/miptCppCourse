#include <SFML/Graphics.hpp>
#include "../include/BaseWindows.hpp"
#include "../include/BaseContainers.hpp"

BaseContainer::BaseContainer(sf::VideoMode& mode, std::string& containerName) 
    : BaseWindow(mode, containerName){
};

BaseContainer::~BaseContainer(){};

void BaseContainer::clearWindow(){
    window.clear(sf::Color::Black);
};

void BaseContainer::openWindow(){
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