#pragma once

#include <string>
#include <fstream>
#include <SFML/Graphics.hpp>

// Функция для записи сообщений в лог


class App
{
public:
    App();
    ~App();

    void run();
    
private:
    void log(const std::string& message, std::ofstream& logFile);

private:
    struct Params
    {
    };
    std::ofstream logFile;
    sf::RenderWindow window;
    sf::Texture texture;
    sf::Sprite sprite;
};

