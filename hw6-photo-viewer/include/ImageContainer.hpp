#pragma once 

#include <SFML/Graphics.hpp>
#include <string>
#include "../include/BaseContainers.hpp"

class ImageContainer : public BaseContainer {
public:
    ImageContainer(sf::VideoMode mode, std::string imageContainerName);

    ~ImageContainer() override;

    void openWindow() override;

private:
    sf::RenderWindow window;
};
