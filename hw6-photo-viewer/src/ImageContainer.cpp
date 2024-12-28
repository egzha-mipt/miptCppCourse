#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "../include/BaseContainers.hpp"
#include "../include/ImageContainer.hpp"
#include "../include/BaseWindows.hpp"

ImageContainer::ImageContainer(sf::VideoMode& mode, std::string& ImageContainerName) 
    : BaseContainer(mode, ImageContainerName){
};

ImageContainer::~ImageContainer(){};

sf::Texture texture("shion_and_naruto_wallpaper.bmp");
sf::Sprite sprite(texture);

void ImageContainer::drawWindow(){
    sf::Texture texture;
    if (!texture.loadFromFile("shion_and_naruto_wallpaper.bmp"))
        return;
    sf::Sprite sprite(texture);
    window.draw(sprite);
}

void ImageContainer::openWindow(){
    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();       
        }
    }

    clearWindow();
    window.draw(sprite);
    displayOnWindow();
}