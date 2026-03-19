#include <iostream>
#include "include/window.h"

GameWindow::GameWindow(TDT4102::Point position, int height, int width, TDT4102::Point cameraPosition, const std::string& title):
    TDT4102::AnimationWindow{position.x, position.y, width , height, title}
{
    this -> camerapositionX = cameraPosition.x;
    this -> camerapositionY = cameraPosition.y;
}

void GameWindow::moveCamera(TDT4102::Point playerPosition){
    this -> camerapositionX = playerPosition.x;
    this -> camerapositionY = playerPosition.y; 
}

void GameWindow::draw(std::string picturePath){
    
}