#include <iostream>
#include <fstream>
#include "include/window.h"

GameWindow::GameWindow(TDT4102::Point position, int height, int width, TDT4102::Point cameraPosition, const std::string& title, const std::string &filePath):
    AnimationWindow{position.x, position.y, width , height, title}
    {
    this -> camerapositionX = cameraPosition.x;
    this -> camerapositionY = cameraPosition.y;

    //Her må vi skaffe størrelsen på rutenettet
    int countingWidth = 0; 
    std::filesystem::path filename(filePath);
    std::ifstream worldFile{filename};
    std::string worldLineInText; 
    std::getline(worldFile, worldLineInText); //Trenger bare lese fra første linje 
    for (char c : worldLineInText) {
        if (c == ','){
            countingWidth += 1;
        }
    }
    this -> gridWidth = countingWidth;

    int countingHeight = 0; 
    while (std::getline(worldFile, worldLineInText)){
        countingHeight += 1;
    }

    this -> gridHeight = countingHeight + 1; 
}

void GameWindow::moveCamera(){
    bool wKeyIsPressed = this -> is_key_down(KeyboardKey::W);
    bool aKeyIsPressed = this -> is_key_down(KeyboardKey::A);
    bool sKeyIsPressed = this -> is_key_down(KeyboardKey::S);
    bool dKeyIsPressed = this -> is_key_down(KeyboardKey::D);
    if (wKeyIsPressed){
        this -> camerapositionY -= 1;
    } else if (sKeyIsPressed){
        this -> camerapositionY += 1;
    } else if (dKeyIsPressed){
        this -> camerapositionX += 1;
    } else if (aKeyIsPressed){
        this -> camerapositionX -= 1;
    }
}

void GameWindow::updateWorld(const std::string &filePath){
    this -> setBackgroundColor(TDT4102::Color::white);
    std::filesystem::path filename(filePath);
    std::fstream worldFile{filename};
    int number;

    for (int i = 0; i < 29; ++i){
        std::string worldLineInText; 
        getline(worldFile, worldLineInText);
        int tileNumber = 0;
        for (char worldTile : worldLineInText){
            TDT4102::Point topLeftCorner {tileNumber * 16, i * 32};
            if (worldTile != ',' && worldTile != '0'){
                TDT4102::Image image("cpictures/" + std::string(1, worldTile) +".png");
                this -> draw_image(topLeftCorner, image, 32, 32);
                this -> draw_text({100, 100}, std::to_string(this -> camerapositionX), TDT4102::Color::navy);
                this -> draw_text({100, 120}, std::to_string(this -> camerapositionY), TDT4102::Color::navy);
            }
            tileNumber++;
        }
    }
    
}

// std::vector<int> cameraPosToGridPos(){
    

// }