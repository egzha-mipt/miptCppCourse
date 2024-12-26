#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <fstream>
#include "../include/App.hpp"

void log(const std::string& message, std::ofstream& logFile)
{
    logFile << message << std::endl;
}

App::App()
    : window(sf::VideoMode({1200, 600}), "Window")
    , texture("shion_and_naruto_wallpaper.bmp")
    , sprite(texture) // Инициализация sprite текстурой
{
}

App::~App()
{
    logFile.close();
}

void App::run()
{
    while (window.isOpen())
    {
        // sf::Event event; //почему так нельзя?
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();       
        }

        sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
        // log("Позиция мыши: " + std::to_string(mousePosition.x) + ", " + std::to_string(mousePosition.y), logFile);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::N))
        {
            // log("Клавиша N нажата", logFile);
        }

        window.clear(sf::Color::Black);
            // log("Черный фон", logFile); 

        window.draw(sprite);
            // log("Спрайт выведен", logFile); 

        window.display();
    }
}