#include <SFML/Graphics.hpp>
#include <fstream>

void log(const std::string& message, std::ofstream& logFile)
{
    logFile << message << std::endl;
}

int main()
{
    std::ofstream logFile("log.txt", std::ios::out);

    sf::RenderWindow window(sf::VideoMode({1200, 600}), "Window");

    sf::Texture texture("shion_and_naruto_wallpaper.bmp");

    sf::Sprite sprite(texture);

    while (window.isOpen())
    {
        std::ofstream logFile("log.txt", std::ios::out);
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }
        
        window.clear(sf::Color::Black);
            log("Черный фон", logFile); 

        window.draw(sprite);
            log("Спрайт выведен", logFile); 

        window.display();
    }

    return 0;
}
