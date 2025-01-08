#include "../include/ImageContainer.hpp"

ImageContainer::ImageContainer(sf::VideoMode mode, std::string imageContainerName)
    : BaseContainer(std::move(mode), std::move(imageContainerName)),
      window(this->mode, this->windowName) {}

ImageContainer::~ImageContainer() {}

void ImageContainer::openWindow() {
    sf::Texture texture("shion_and_naruto_wallpaper.bmp");

    sf::Sprite sprite(texture);

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
            else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
            {
                if (keyPressed->scancode == sf::Keyboard::Scancode::Escape)
                    window.close();
            }
        }

        window.setFramerateLimit(10);
        
        window.clear();

        window.draw(sprite);
            
        window.display();
    }

}