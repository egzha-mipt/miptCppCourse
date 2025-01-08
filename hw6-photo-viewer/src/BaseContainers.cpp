#include "../include/BaseContainers.hpp"

BaseContainer::BaseContainer(sf::VideoMode mode, std::string containerName)
    : BaseWindow(std::move(mode), std::move(containerName)),
      window(this->mode, this->windowName) {}


BaseContainer::~BaseContainer() {}

void BaseContainer::openWindow() {
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

        // sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

        window.setFramerateLimit(10); //интуитивно надо 9-10 
        
        window.clear();

        // window.draw(sprite);
            
        window.display();
    }

}