#include <iostream>
#include <fstream>
#include "include/window.h"

GameWindow::GameWindow(TDT4102::Point position, int height, int width, TDT4102::Point cameraPosition, const std::string& title):
    AnimationWindow{position.x, position.y, width , height, title}
    {
    this -> cameraPosition = {cameraPosition.x, cameraPosition.y};
    /*
    Definer grid widht som er antall blokker.
    og definer grid height som er i y retning

    
    */
}

void GameWindow::moveCamera(){
    bool wKeyIsPressed = this -> is_key_down(KeyboardKey::W);
    bool aKeyIsPressed = this -> is_key_down(KeyboardKey::A);
    bool sKeyIsPressed = this -> is_key_down(KeyboardKey::S);
    bool dKeyIsPressed = this -> is_key_down(KeyboardKey::D);
    if (wKeyIsPressed){
        this -> cameraPosition.y -= 1;
    } else if (sKeyIsPressed){
        this -> cameraPosition.y += 1;
    } else if (dKeyIsPressed){
        this -> cameraPosition.x += 1;
    } else if (aKeyIsPressed){
        this -> cameraPosition.x -= 1;
    }
}

void GameWindow::updateWorld(const std::string &filePath){
    //this -> setBackgroundColor(TDT4102::Color::white);
    std::filesystem::path filename(filePath);
    std::fstream worldFile{filename};

    for (int i = 0; i < this -> gridHeight; ++i){
        std::string worldLineInText; 
        getline(worldFile, worldLineInText);
        int tileNumber = 0;
        for (char worldTile : worldLineInText){
            TDT4102::Point topLeftCorner {tileNumber * 8, i * 32};
            if (worldTile != '"' && worldTile != ',' && worldTile != ' '){
                TDT4102::Image image("cpictures/" + std::string(1, worldTile) +".png");
                this -> draw_image(topLeftCorner, image, 32, 32);
                this -> draw_text({100, 100}, std::to_string(this -> cameraPosition.x), TDT4102::Color::navy);
                this -> draw_text({100, 120}, std::to_string(this -> cameraPosition.y), TDT4102::Color::navy);
                
            }
            tileNumber++;
        }
    }
    
}