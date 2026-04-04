#include "include/window.h"
#include "include/worlds.h"
#include "include/player.h"

GameWindow::GameWindow(TDT4102::Point windowPosition, TDT4102::Point startingDimensions, const std::string& title):
    AnimationWindow(windowPosition.x, windowPosition.y, startingDimensions.x, startingDimensions.y, title)
{
    this -> gridPosition = TDT4102::Point(1, 1);
    this -> cameraPosition = TDT4102::Point(32,32);
    this -> blocksToRender = TDT4102::Point(30, 16); 
}

void amountOfBlocksToRender(const World& world){

}

void GameWindow::updateWindowPosition(const World& world){
    if (this -> is_key_down(KeyboardKey::A)){
        try{
            this -> cameraPosition.x -= 10;
            if (cameraPosition.x < 0){
                throw std::out_of_range("Outside camerabounds");
            }
        }
        catch(const std::out_of_range& e){
            this -> cameraPosition.x = 0;
        }
    } else if (this -> is_key_down(KeyboardKey::D)){
        try{
            this -> cameraPosition.x += 10;
            if (cameraPosition.x > world.getWorldSizeInPixels().x-(this->blocksToRender.x * 32)){
                throw std::out_of_range("Outside camerabounds");
            }
        }
        catch(const std::out_of_range& e){
            this -> cameraPosition.x = world.getWorldSizeInPixels().x-(this->blocksToRender.x * 32);
        }
    } else if (this -> is_key_down(KeyboardKey::S)){
         try{
            this -> cameraPosition.y += 10;
            if (cameraPosition.y > world.getWorldSizeInPixels().y-(this->blocksToRender.y * 32)){
                throw std::out_of_range("Outside camerabounds");
            }
        }
        catch(const std::out_of_range& e){
            this -> cameraPosition.y = world.getWorldSizeInPixels().y-(this->blocksToRender.y * 32);
        }
    } else if (this -> is_key_down(KeyboardKey::W)){
        try{
            this -> cameraPosition.y -= 10;
            if (cameraPosition.y < 0){
                throw std::out_of_range("Outside camerabounds");
            }
        }
        catch(const std::out_of_range& e){
            this -> cameraPosition.y = 0;
        }
    }
    this -> gridPosition.x = cameraPosition.x / 32;
    this -> gridPosition.y = cameraPosition.y / 32; 
}

//Funksjonen skal ta inn mobs, players og rett antall blocker. 
void GameWindow::updateWindow(const World& world){
    //this -> setBackgroundColor(TDT4102::Color::dark_green);
    std::vector<std::vector<std::string>> blocks = world.getBlocks();

    for (int i = this -> gridPosition.x; i < this -> gridPosition.x + this->blocksToRender.x; ++i){
        for (int j = this -> gridPosition.y; j < this -> gridPosition.y + this->blocksToRender.y; ++j){
            if (blocks.at(j).at(i) != "0"){
                std::string blockType = blocks.at(j).at(i);
                if (imageCache.find(blockType) == imageCache.end()){
                    imageCache[blockType] = TDT4102::Image("cpictures/" + blockType + ".png");
                }
                TDT4102::Image& image = imageCache[blockType];

                TDT4102::Point topLeftCorner
                (((this -> gridPosition.x * 32) - (this -> cameraPosition.x)) + ((i-gridPosition.x) * 32), 
                ((this -> gridPosition.y * 32) - (this -> cameraPosition.y)) + ((j-gridPosition.y) * 32));

                this -> draw_image(topLeftCorner, image, 32, 32);
            }
        }
    } 
}

void GameWindow::drawPlayer(const Player& player){
    //TDT4102::Image playerImage("cpictures/player.png"); // Dette blir feil, vi må laste inn bilder fra klassen slik at vi kan lage animasjoner og forskjellige skins.
    TDT4102::Point playerPosition(player.getPosition().x, player.getPosition().y);
    TDT4102::Point topLeftCorner(playerPosition.x - cameraPosition.x, playerPosition.y - cameraPosition.y);
    this -> draw_rectangle(topLeftCorner, 40, 80, TDT4102::Color::blue); // Midlertidig, skal tegne spilleren som et rektangel før vi har laget sprites.
}

void GameWindow::openGameMenu(){

}