#include <SFML/Graphics.hpp>
#include "../include/BaseWindows.hpp"
#include "../include/BaseContainers.hpp"

BaseContainer::BaseContainer(sf::VideoMode& mode, std::string& containerName) 
    : BaseWindow(mode, containerName){
};

BaseContainer::~BaseContainer(){};