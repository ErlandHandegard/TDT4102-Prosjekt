#include <iostream>
#include <fstream>
#include "include/window.h"

GameWindow::GameWindow(TDT4102::Point position, int height, int width, TDT4102::Point cameraPosition, const std::string& title):
    AnimationWindow{position.x, position.y, width , height, title}
    {
    // this -> camerapositionX = cameraPosition.x;
    // this -> camerapositionY = cameraPosition.y;
}

/*
void GameWindow::moveCamera(TDT4102::Point playerPosition){
    this -> camerapositionX = playerPosition.x;
    this -> camerapositionY = playerPosition.y; 
}
*/


void GameWindow::updateWorld(const std::string &filePath){
    std::filesystem::path filename(filePath);
    std::fstream worldFile{filename};
    int number;

    for (int i = 0; i < 29; ++i){
        std::string worldLineInText; 
        getline(worldFile, worldLineInText);
        int tileNumber = 0;
        for (char worldTile : worldLineInText){
            TDT4102::Point topLeftCorner {tileNumber * 8, i * 32};
            if (worldTile != '"' && worldTile != ',' && worldTile != ' '){
                TDT4102::Image image("pictures/" + std::string(1, worldTile) +".png");
                this -> draw_image(topLeftCorner, image, 32, 32);
            }
            tileNumber++;
        }
    }
    
}
