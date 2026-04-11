#include "include/window.h"
#include "include/worlds.h"
#include "include/player.h"
#include "include/Mobs/mobs.h"

GameWindow::GameWindow(TDT4102::Point windowPosition, TDT4102::Point startingDimensions, const std::string& title):
    AnimationWindow(windowPosition.x, windowPosition.y, startingDimensions.x, startingDimensions.y, title)
{
    this -> gridPosition = TDT4102::Point(1, 1);
    this -> cameraPosition = TDT4102::Point(32,32);
    this -> blocksToRender = TDT4102::Point((this->width() / 32) + 1, (this->height() / 32) + 1); 
}

void GameWindow::amountOfBlocksToRender(){
    this->blocksToRender.x = (this->width() / 32) + 1; // Vi legger til 1 for å være sikker på at vi rendrer nok blokker i kantene av vinduet.
    this->blocksToRender.y = (this->height() / 32) + 2;
}

void GameWindow::updateWindowPosition(const World& world, const Player& player){
    int speedX = 1;
    int speedY = 1;

    if ((player.getPosition().x - ((this->width()/2) - 20)) - this -> cameraPosition.x > 50 || player.getPosition().x - ((this->width()/2) - 20) - this -> cameraPosition.x < -50){
        speedX = 20;
    } else if ((player.getPosition().x - ((this->width()/2) - 20)) - this -> cameraPosition.x > 10 || player.getPosition().x - ((this->width()/2) - 20) - this -> cameraPosition.x < -10){
        speedX = 5;
    } else {
        speedX = 1;
    }
    if ((player.getPosition().y - ((this->height()/2) - 40)) - this -> cameraPosition.y > 50 || player.getPosition().y - ((this->height()/2) - 40) - this -> cameraPosition.y < -50){
        speedY = 20;
    } else if ((player.getPosition().y - ((this->height()/2) - 40)) - this -> cameraPosition.y > 10 || player.getPosition().y - ((this->height()/2) - 40) - this -> cameraPosition.y < -10){
        speedY = 5;
    } else {
        speedY = 1;
    }

    try{
        if ((player.getPosition().x - ((this->width()/2) - 20)) < this -> cameraPosition.x){
            this -> cameraPosition.x -= speedX;
        }
        if (cameraPosition.x < 0){
            throw std::out_of_range("Outside camerabounds");
        }
        }
        catch(const std::out_of_range& e){
            this -> cameraPosition.x = 0;
        }  
    try{
        if ((player.getPosition().x - ((this->width()/2) - 20)) > this -> cameraPosition.x){
            this -> cameraPosition.x += speedX;
        }
        if (cameraPosition.x > world.getWorldSizeInPixels().x-(this->blocksToRender.x * 32)){
            throw std::out_of_range("Outside camerabounds");
        }
        }
        catch(const std::out_of_range& e){
            this -> cameraPosition.x = world.getWorldSizeInPixels().x-(this->blocksToRender.x * 32);
        }
    try{
        if ((player.getPosition().y - ((this->height()/2) - 40)) < this -> cameraPosition.y){
            this -> cameraPosition.y -= speedY;
        }
        if (cameraPosition.y > world.getWorldSizeInPixels().y-(this->blocksToRender.y * 32)){
            throw std::out_of_range("Outside camerabounds");
            }
        }
        catch(const std::out_of_range& e){
            this -> cameraPosition.y = world.getWorldSizeInPixels().y-(this->blocksToRender.y * 32);
        }
    try{
        if ((player.getPosition().y - ((this->height()/2) - 40)) > this -> cameraPosition.y){
            this -> cameraPosition.y += speedY;
        }
        if (cameraPosition.y < 0){
            throw std::out_of_range("Outside camerabounds");
        }
        }
        catch(const std::out_of_range& e){
            this -> cameraPosition.y = 0;
        }
    this -> gridPosition.x = cameraPosition.x / 32;
    this -> gridPosition.y = cameraPosition.y / 32; 
}

//Funksjonen skal ta inn mobs, players og rett antall blocker. 
void GameWindow::drawWindow(const World& world){
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

void GameWindow::drawMobs(const std::vector<std::unique_ptr<MobileEntities>>& mobs){
    for(const std::unique_ptr<MobileEntities>& mob : mobs){
        TDT4102::Point posTopLeft = mob->getPosition();
        TDT4102::Point posTopRight = mob->getPosition();
        TDT4102::Point posBottomLeft = mob->getPosition();
        TDT4102::Point posBottomRight = mob->getPosition();

        posTopRight.x += mob->getMobsize().x;
        posBottomRight.x += mob->getMobsize().x;
        posBottomLeft.y += mob->getMobsize().y;
        posBottomRight.y += mob->getMobsize().y;


        TDT4102::Point topLeftWindow = this -> cameraPosition;
        // TDT4102::Point topRightWindow = mob->getPosition();
        // TDT4102::Point posBottomLeft = mob->getPosition();
        // TDT4102::Point posBottomRight = mob->getPosition();

        // posTopRight.x += mob->getMobsize().x;
        // posBottomRight.x += mob->getMobsize().x;
        // posBottomLeft.y += mob->getMobsize().y;
        // posBottomRight.y += mob->getMobsize().y;

        // if(topLeftWindow.x - posTopLeft.x < 0 || topLeftWindow.y -posTopLeft.y < 0 ||
        //    -(topRightWindow.x - posTopRight.x) < 0 || topRightWindow.y - posTopRight.y < 0 ||
        //    bottomLeftWindow.x - posBottomLeft.x < 0 || -(bottomLeftWindow.y -posTopLeft.y) < 0 ||
        //    -(bottomRightWindow.x - posBottomRight.x) < 0 || -(bottomRightWindow.y - posBottomRight.y) < 0){

        this -> draw_rectangle({(posTopLeft.x - topLeftWindow.x),posTopLeft.y - topLeftWindow.y}, mob->getMobsize().x, mob->getMobsize().y, TDT4102::Color::firebrick); // Midlertidig, skal tegne mobsene som et rektangel før vi har laget sprites.
//}
}
}
// void GameWindow::openGameMenu(){

// }