#include <iostream>
#include <fstream>
#include "include/window.h"

GameWindow::GameWindow(TDT4102::Point position, int height, int width, TDT4102::Point cameraPosition, const std::string& title){
    this -> window = TDT4102::AnimationWindow{position.x, position.y, width , height, title};
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

    for (int i = 0; i < 29; ++i){
        std::string worldLineInText; 
        getline(worldFile, worldLineInText);
        int tileNumber = 0;
        for (char worldTile : worldLineInText){
            TDT4102::Point topLeftCorner {tileNumber * 16, i * 16};
            if (worldTile != '"' && worldTile != ','){
                TDT4102::Image image(worldTile +".png");
                this->window.draw_image(topLeftCorner, image, 16, 16);
            }
            tileNumber++;
        }
    }
    
}