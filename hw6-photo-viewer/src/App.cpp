#include <SFML/Graphics.hpp>
#include <fstream>

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
    std::ofstream logFile("log.txt", std::ios::out);

    sf::RenderWindow window(sf::VideoMode({1200, 600}), "Window");

    sf::Texture texture("shion_and_naruto_wallpaper.bmp");

    sf::Sprite sprite(texture);

    window.setPosition({120, 120}); 

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
        }

        sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
        log("Позиция мыши: " + std::to_string(mousePosition.x) + ", " + std::to_string(mousePosition.y), logFile);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::N))
        {
            log("Клавиша N нажата", logFile);
        }

        window.setFramerateLimit(10); //интуитивно надо 9-10 
        
        window.clear(sf::Color::Black);
            // log("Черный фон", logFile); 

        window.draw(sprite);
            // log("Спрайт выведен", logFile);     
            
        window.display();
    }

    return 0;
}
