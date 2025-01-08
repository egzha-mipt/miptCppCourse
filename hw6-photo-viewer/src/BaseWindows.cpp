#include "../include/BaseWindows.hpp"

BaseWindow::BaseWindow(sf::VideoMode mode, std::string windowName)
    : mode(std::move(mode)), windowName(std::move(windowName)) {}

BaseWindow::~BaseWindow() {}