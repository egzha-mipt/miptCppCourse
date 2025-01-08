#include <SFML/Graphics.hpp>
#include <fstream>
#include <iostream>
#ifdef _DEBUG
  #define DEBUG_MODE
#endif


void log(const std::string& message, std::ofstream& logFile)
{
    logFile << message << std::endl;
}

void renderingThread(sf::RenderWindow* window)
{
    // activate the window's context
    window->setActive(true);

    // the rendering loop
    while (window->isOpen())
    {
        // draw...

        // end the current frame
        window->display();
    }
}

int main()
{
    //WINDOW & SPRITE
    std::ofstream logFile("log.txt", std::ios::out);
    sf::RenderWindow window(sf::VideoMode({1750, 600}), "Window");

    sf::Texture texture("shion_and_naruto_wallpaper.bmp");
    sf::Sprite sprite(texture);
    window.setPosition({120, 120}); 

    bool focus = window.hasFocus();

    // check whether the window has the focus

    sf::Vector2u size = window.getSize();
    float scaleX = static_cast<float>(size.x) / sprite.getTexture().getSize().x;
    float scaleY = static_cast<float>(size.y) / sprite.getTexture().getSize().y;

    // Выбираем максимальный масштаб, чтобы картинка заполнила всё окно
    float scale = std::max(scaleX, scaleY);

    sprite.setScale({scale, scale});

    //TEXT
    sf::Font font("tuffy.ttf");
    sf::Text text(font); // a font is required to make a text object
    // set the string to display
    text.setString("shion_and_naruto_wallpaper");
    // set the character size
    text.setCharacterSize(24); // in pixels, not points!
    // set the color
    text.setFillColor(sf::Color::Blue);
    text.setPosition({800, 10});
    // set the text style
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
                std::cout << "new width: " << resized->size.x << std::endl;
                std::cout << "new height: " << resized->size.y << std::endl;
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

        sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
        log("Позиция мыши: " + std::to_string(mousePosition.x) + ", " + std::to_string(mousePosition.y), logFile);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::N))
        {
            log("Клавиша N нажата", logFile);
        }


        window.clear(sf::Color::Black);
            // log("Черный фон", logFile); 

        window.draw(sprite); 

        // window.draw(text);
            
        window.display();
    }

    return 0;
}
