#include "../include/ImageContainer.hpp"
#include <iostream>
#ifdef _DEBUG
  #define DEBUG_MODE
#endif

ImageContainer::ImageContainer(sf::VideoMode mode, std::string imageContainerName)
    : BaseContainer(std::move(mode), std::move(imageContainerName)),
      window(this->mode, this->windowName) {}

ImageContainer::~ImageContainer() {
    if (window.isOpen()) {
        window.close();
        std::cout << "Window closed in destructor!" << std::endl;
    }
}

void ImageContainer::openWindow() {
    
    sf::Texture texture("shion_and_naruto_wallpaper.bmp");
    sf::Sprite sprite(texture);
    window.setPosition({120, 120}); 

    // bool focus = window.hasFocus();

    //скейлим на всё окно (при любом разрешении всё окно в наруто)
    sf::Vector2u size = window.getSize();
    float scaleX = static_cast<float>(size.x) / sprite.getTexture().getSize().x;
    float scaleY = static_cast<float>(size.y) / sprite.getTexture().getSize().y;
    float scale = std::max(scaleX, scaleY);
    sprite.setScale({scale, scale});

    //TEXT
    auto [width, height] = size;
    sf::Font font("tuffy.ttf");
    sf::Text text(font);
    text.setString("shion_and_naruto_wallpaper");
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::Blue);
    text.setPosition({static_cast<float>(width-325), static_cast<float>(height - height + 5)});
    text.setStyle(sf::Text::Bold | sf::Text::Underlined);


    while (window.isOpen())
    {
        // window.setVerticalSyncEnabled(true);

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
            if (const auto* resized = event->getIf<sf::Event::Resized>())
            {
#ifdef DEBUG_MODE
                std::cout << "new  width of image container: " << resized->size.x << std::endl;
                std::cout << "new height of image container: " << resized->size.y << std::endl;
#endif
            }

            if (event->is<sf::Event::FocusLost>()) window.setFramerateLimit(10);;

            if (event->is<sf::Event::FocusGained>()) window.setFramerateLimit(12);;  //интуитивно надо 9-20 
            
#ifdef DEBUG_MODE
            // if (focus){
            // std::cout << "focus on" << std::endl;}

            if (const auto* textEntered = event->getIf<sf::Event::TextEntered>())
            if (textEntered->unicode < 128)
                std::cout << "ASCII character typed: " << static_cast<char>(textEntered->unicode) << std::endl;
#endif
        }

        // sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

        window.clear(sf::Color::Black);

        window.draw(sprite); 
        window.draw(text);
            
        window.display();
    }
}