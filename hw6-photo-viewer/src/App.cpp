#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode({1200, 600}), "Window");

    sf::Texture texture("shion_and_naruto_wallpaper.bmp");

    sf::Sprite sprite(texture);

    while (window.isOpen())
    {
       while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        window.clear(sf::Color::Black);

        window.draw(sprite);

        window.display();
    }

    return 0;
}
