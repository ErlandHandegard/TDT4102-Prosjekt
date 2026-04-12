#include "include/window.h"
#include "include/worlds.h"
#include "include/player.h"

GameWindow::GameWindow(TDT4102::Point windowPosition, TDT4102::Point startingDimensions, const std::string& title):
    AnimationWindow(windowPosition.x, windowPosition.y, startingDimensions.x, startingDimensions.y, title)
{
    this -> gridPosition = TDT4102::Point(1, 1);
    this -> cameraPosition = TDT4102::Point(32,32);
    this -> blocksToRender = TDT4102::Point((this->width() / 32) + 1, (this->height() / 32) + 1); 
    this -> openMeny = 0;
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

    this -> mouseGridPosition.x = (this -> get_mouse_coordinates().x + this -> cameraPosition.x)/32;
    this -> mouseGridPosition.y = (this -> get_mouse_coordinates().y + this -> cameraPosition.y)/32;
}

//Funksjonen skal ta inn mobs, players og rett antall blocker. 
void GameWindow::drawWindow(const World& world){
    //this -> setBackgroundColor(TDT4102::Color::dark_green);
    const std::vector<std::vector<std::string>>& blocks = world.getBlocks();

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

void GameWindow::drawDrops(const World& world){
    for (const auto& item : world.getDroppedItems()){
        // Lag en unik nøkkel, f.eks. "1_drop" i stedet for bare "1"
        std::string dropKey = item.getBlockType() + "_drop";

        if (imageCache.find(dropKey) == imageCache.end()){
            imageCache[dropKey] = TDT4102::Image("cpictures/" + item.getBlockType() + "Drop.png");
        }
        
        TDT4102::Image& image = imageCache[dropKey];
        this->draw_image({item.getPosition().x - this->cameraPosition.x, 
                          item.getPosition().y - this->cameraPosition.y}, 
                        image, 16, 16);
    }
}

void GameWindow::drawItemInSlot(std::string itemType, int x, int y, int size) {
    // Bestem filnavn: Er det en pickaxe eller en blokk-drop?
    std::string path;
    std::string cacheKey;

    if (itemType == "1"){
        itemType = "2";
    }

    if (itemType.find("Pick") != std::string::npos) {
        path = "cpictures/" + itemType + ".png";
        cacheKey = itemType; // f.eks "ironPick"
    } else {
        path = "cpictures/" + itemType + "Drop.png";
        cacheKey = itemType + "_drop"; // Viktig for å ikke blande med blokker i verden
    }

    // Sjekk cache
    if (imageCache.find(cacheKey) == imageCache.end()) {
        imageCache[cacheKey] = TDT4102::Image(path);
    }

    // Tegn bildet skalert til slot-størrelsen
    this->draw_image({x, y}, imageCache[cacheKey], size, size);
}

void GameWindow::openGameMenu(Player& player, World& world) {
    //Initialiserer det grunnlegende for GUI
    int menyWidth = this -> width() * 0.40;  //Skal ta 40% av skjermen, gjør det til int senere
    int slotSize = menyWidth / 10;           // Del opp i 10 kolonner
    int padding = slotSize * 0.1;            // 10% av slot-størrelsen som mellomrom
    int startX = (menyWidth) * 0.05;         // Starter Oppe i venstre gjørne
    int startY = startX;                     // Samme avstand som x

    //Gjør slik at menyen kun er åpen om escape er blitt trykt på. 
    if (this->is_key_down(KeyboardKey::ESCAPE)) {
        this->openMeny = !this->openMeny;
    }

    //Henter hvilket item man har i inventoriet sitt. 
    std::vector<std::vector<std::string>> item = player.getItem();

    // Tegner hele menyen om openMeny er true
    if (this->openMeny) {
        for (int row = 1; row < 4; ++row) {
            for (int slot = 0; slot < 10; ++slot) {
                int xPos = startX + (slot * slotSize);
                int yPos = startY + (row * slotSize);

                // Tegn bakgrunn for slot. Dette hadde blit finere om vi hadde hatt ett bilde
                this->draw_rectangle({xPos + padding, yPos + padding}, slotSize - padding*2, slotSize - padding*2, TDT4102::Color::aqua);

                // Tegn innhold (Bilde)
                std::string itemType = item.at(row).at(slot);
                if (itemType != "0") {
                    this -> drawItemInSlot(itemType, xPos + 2 * padding, startY + 2 * padding, slotSize - padding*4);
                }
            }
        }
        // legg inn knapper her :)
    }

    int activeSlot = player.getHotBarIndex();

    for (int slot = 0; slot < 10; ++slot) {
        int xPos = startX + (slot * slotSize);
        
        // Sjekk om dette er den aktive slotten
        TDT4102::Color slotColor = (slot == activeSlot) ? TDT4102::Color::dark_yellow : TDT4102::Color::cornflower_blue;

        this->draw_rectangle({xPos + padding, startY + padding}, slotSize - padding*2, slotSize - padding*2, slotColor);

        std::string itemType = item.at(0).at(slot);
        if (itemType != "0") {
            this -> drawItemInSlot(itemType, xPos + 2 * padding, startY + 2 * padding, slotSize - padding*4);
        }
    }
}