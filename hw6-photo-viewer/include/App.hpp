#pragma once 

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "../include/BaseContainers.hpp"
#include "../include/ImageContainer.hpp"
#include "../include/BaseWindows.hpp"

class App {
public:
    App();
    ~App();

    void run();
    
private:
    void log(const std::string& message, std::ofstream& logFile);

private:
    // std::ofstream logFile;
    std::unique_ptr<BaseWindow> baseWindowMain;
    std::unique_ptr<BaseContainer> baseContainerMain;
    std::unique_ptr<ImageContainer> imageContainerMain;  // Используется для отображения изображений
};
