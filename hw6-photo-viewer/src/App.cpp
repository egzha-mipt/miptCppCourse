#include <SFML/Graphics.hpp>
#include <fstream>
#include <iostream>
#include <thread>
#ifdef _DEBUG
  #define DEBUG_MODE
#endif


void log(const std::string& message, std::ofstream& logFile)
{
    logFile << message << std::endl;
}

void renderingThread(sf::RenderWindow* window)
{
    // Activate the OpenGL context for this thread
    window->setActive(true);

    // Создаем объект для отрисовки (пример: круг)
    sf::CircleShape shape(60);
    shape.setFillColor(sf::Color(100, 250, 50));
    shape.setPosition({200, 200});

    // Основной цикл рендера
    while (window->isOpen())
    {
        // Очищаем окно
        window->clear(sf::Color::Black);

        // Рисуем фигуру
        window->draw(shape);

        // Отображаем отрисованное
        window->display();
    }
}

int main()
{
    //WINDOW & SPRITE (TEXTURE)
    std::ofstream logFile("log.txt", std::ios::out);
    sf::RenderWindow window(sf::VideoMode({1750, 600}), "Window");

    sf::Texture texture("shion_and_naruto_wallpaper.bmp");
    sf::Sprite sprite(texture);
    window.setPosition({120, 120}); 
    // bool focus = window.hasFocus();


    //THREADS
    window.setActive(false);
    std::thread renderThread(renderingThread, &window);

    
    //BACKGROUND TEXTURE    
    sf::Vector2u size = window.getSize();
    auto [width, height] = size;
    std::cout << width << " " << height << std::endl;
    float scaleX = static_cast<float>(size.x) / sprite.getTexture().getSize().x;
    float scaleY = static_cast<float>(size.y) / sprite.getTexture().getSize().y;
    float scale = std::max(scaleX, scaleY);
    sprite.setScale({scale, scale});

    //TEXT 
    sf::Font font("tuffy.ttf");
    sf::Text text(font); // a font is required to make a text object
    text.setString("shion_and_naruto_wallpaper");
    text.setCharacterSize(24); // in pixels, not points!
    text.setFillColor(sf::Color(255,119,203)); //Neon pink
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


            if (const auto* mouseWheelScrolled = event->getIf<sf::Event::MouseWheelScrolled>())
            {
            switch (mouseWheelScrolled->wheel)
            {
                case sf::Mouse::Wheel::Vertical:
                    std::cout << "wheel type: vertical" << std::endl;
                    break;
                case sf::Mouse::Wheel::Horizontal:
                    std::cout << "wheel type: horizontal" << std::endl;
                    break;
            }
            std::cout << "wheel movement: " << mouseWheelScrolled->delta << std::endl;
            std::cout << "mouse x: " << mouseWheelScrolled->position.x << std::endl;
            std::cout << "mouse y: " << mouseWheelScrolled->position.y << std::endl;
            }
        }
        // renderThread.join();

        sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
        log("Позиция мыши: " + std::to_string(mousePosition.x) + ", " + std::to_string(mousePosition.y), logFile);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::N))
        {
            log("Клавиша N нажата", logFile);
        }


        window.clear(sf::Color::Black);
            log("Черный фон", logFile); 

        window.draw(sprite); 
        window.draw(text);
            
        window.display();
    }

    std::cout << "N-Window is closed" << std::endl;
    return 0;
}
