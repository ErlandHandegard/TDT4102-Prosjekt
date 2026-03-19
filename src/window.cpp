#include <iostream>
#include <fstream>
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

void GameWindow::updateWorld(const std::string &filePath){
    std::filesystem::path filename(filePath);
    std::fstream worldFile{filename};
    int number;
    
    TDT4102::Image image(number +".png");

    for (int i = 0; i < 29; ++i){
        std::string worldLineInText; 
        getline(worldFile, worldLineInText);
        for (char worldTile : worldLineInText)
            TDT4102::Point topLeftCorner {0, 0};
            TDT4102::Point bottomRightCorner {16, 16};
    }
    
}