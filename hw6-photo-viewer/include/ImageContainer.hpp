#pragma once 

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "../include/BaseContainers.hpp"

class ImageContainer : public BaseContainer
{
public:
    ImageContainer(sf::VideoMode& mode, std::string& ImageContainerName);
    virtual ~ImageContainer();

    void openWindow() override;
    void drawWindow();

private:
    sf::Texture texture;
};