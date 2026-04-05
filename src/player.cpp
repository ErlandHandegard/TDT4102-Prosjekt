#include "include/player.h"
#include "include/window.h"
#include "include/worlds.h"

Player::Player(TDT4102::Point strartingPosition){
    this -> health = 400;
    this -> position = strartingPosition;
    this -> velocity = TDT4102::Point(0, 0);
    this -> acceleration = TDT4102::Point(0, 1);
    this -> playerSize = TDT4102::Point(40, 80);
}

void Player::move(const World& world, const GameWindow& gameWindow) {
    //Oppdater posisjonen basert på hastighet og akselerasjon først
    this -> velocity.y += this -> acceleration.y;
    this -> velocity.x += this -> acceleration.x;
    this -> position.y += this -> velocity.y;
    this -> position.x += this -> velocity.x;

    this -> gridPosition.x = position.x / 32; // Dette er posisojonen til øvre venstre hjørne av spilleren
    this -> gridPosition.y = position.y / 32; 

    std::vector<std::vector<bool>> collitionMatrix = world.getCollitionMatrix();
    int worldWidthInBlocks = world.getWorldSizeInBlocks().x;
    int worldHeightInBlocks = world.getWorldSizeInBlocks().y;

    //Pågrunn av bredden til spilleren må vi av og til sjekke tre blokker i bredden
    // og av og til skjekke to blokker. Det gjør disse testene. 
    bool checkForThreeBlocks = 0;
    if (position.x - gridPosition.x * 32 > 24) {
        checkForThreeBlocks = 1;
    }

    if (checkForThreeBlocks){
        //Først sjekker vi bakken slik at spilleren får hoppe og ikke faller gjennom bakken.
        if (this -> velocity.y >= 0 &&
            (collitionMatrix[gridPosition.y + 3][gridPosition.x] || 
            collitionMatrix[gridPosition.y + 3][gridPosition.x + 1] || 
            collitionMatrix[gridPosition.y + 3][gridPosition.x + 2])) {
            this -> velocity.y = 0; // Slutter å falle hvis det er en blokk under
            this -> position.y = gridPosition.y * 32 + 16; // Legger spilleren i rett posisjon i forhold til blokken
        }
        //Sjekk for kollisjon til i taket
        if (this -> velocity.y < 0 &&
            (collitionMatrix[gridPosition.y - 1][gridPosition.x] || 
            collitionMatrix[gridPosition.y - 1][gridPosition.x + 1] || 
            collitionMatrix[gridPosition.y - 1][gridPosition.x + 2])) {
            this -> velocity.y = 0; // Sender spilleren nedover hvis det er en blokk i taket
            this -> position.y = (gridPosition.y) * 32; // Legger spilleren i rett posisjon i forhold til blokken
        }
    } else {
        //Først sjekker vi bakken slik at spilleren får hoppe og ikke faller gjennom bakken.
        if (this -> velocity.y >= 0 && 
            (collitionMatrix[gridPosition.y + 3][gridPosition.x] || 
            collitionMatrix[gridPosition.y + 3][gridPosition.x + 1])) {
            this -> velocity.y = 0; // Stop falling if there's a block below
            this -> position.y = gridPosition.y * 32 + 16; // Align player with the block
        }
        //Sjekk for kollisjon til i taket
        if (this -> velocity.y < 0 &&
            (collitionMatrix[gridPosition.y - 1][gridPosition.x] || 
            collitionMatrix[gridPosition.y - 1][gridPosition.x + 1])) {
            this -> velocity.y = 0; // Sender spilleren nedover hvis det er en blokk i taket
            this -> position.y = (gridPosition.y) * 32; // Legger spilleren i rett posisjon i forhold til blokken
        }
    }

    //Sjekk for kollisjon til venstre og høyre.

    //Spiller inputs

    //Hopping
    if (gameWindow.is_key_down(KeyboardKey::SPACE) && 
        (collitionMatrix[gridPosition.y + 3][gridPosition.x] || 
        collitionMatrix[gridPosition.y + 3][gridPosition.x + 1])) {
        this -> velocity.y = -15; // Jumping velocity
    }
    // Bevegelse frem og tilbake
    if (gameWindow.is_key_down(KeyboardKey::A)) {
        this -> velocity.x = -5; // Move left
    } else if (gameWindow.is_key_down(KeyboardKey::D)) {
        this -> velocity.x = 5; // Move right
    } else {
        this -> velocity.x = 0; // Stop horizontal movement when neither A nor D is pressed
    }
}