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
    //Håndterer spiller input for bevegelse frem og tilbake. 
    if (gameWindow.is_key_down(KeyboardKey::A)) {
        this->velocity.x = -5;
    } else if (gameWindow.is_key_down(KeyboardKey::D)) {
        this->velocity.x = 5;
    } else {
        this->velocity.x = 0;
    }

    //Tyngdekraften påvirker spilleren hele tiden, 
    // så vi legger til akselerasjonen i hastigheten hver frame
    this -> velocity.y += this -> acceleration.y;
    

    //Legg inn akselerasjon i motsattretning av x hastighet. 
    // Ser på dette senere

    //Oppdaterer posisjonen til spilleren basert på hastigheten
    this -> position.y += this -> velocity.y;
    this -> position.x += this -> velocity.x;

    //Bruker dette som base for å sjekke kollisjoner. 
    // Det er posisjonen til spilleren i gridet, og det er det vi bruker for å sjekke kollisjoner.
    this -> gridPosition.x = position.x / 32; // Dette er posisojonen til øvre venstre hjørne av spilleren
    this -> gridPosition.y = position.y / 32; 

    //Henter kollisjonsmatrisen fra verdenen, og størrelsen på verdenen i blokker.
    std::vector<std::vector<bool>> collitionMatrix = world.getCollitionMatrix();
    int worldWidthInBlocks = world.getWorldSizeInBlocks().x;
    int worldHeightInBlocks = world.getWorldSizeInBlocks().y;

    //Pågrunn av bredden til spilleren må vi av og til sjekke tre blokker i bredden
    // og av og til skjekke to blokker. Det gjør disse testene. 
    bool onGround = 0;
    if (position.x - gridPosition.x * 32 > 24) {
        onGround =  collitionMatrix[gridPosition.y + 3][gridPosition.x] ||
                    collitionMatrix[gridPosition.y + 3][gridPosition.x + 1] ||
                    collitionMatrix[gridPosition.y + 3][gridPosition.x + 2];
    } else {
        onGround = collitionMatrix[gridPosition.y + 3][gridPosition.x] ||
                   collitionMatrix[gridPosition.y + 3][gridPosition.x + 1];
    }

    //Hopping
    if (gameWindow.is_key_down(KeyboardKey::SPACE) && onGround) {
        this -> velocity.y = -10; // Jumping velocity
    }

    // --- VERTIKAL MOVEMENT MED STEP (hindrer tunneling) ---
    int steps = abs((int)this->velocity.y);
    int direction = (this->velocity.y > 0) ? 1 : -1;

    for (int i = 0; i < steps; i++) {

        this->position.y += direction;

        // Oppdater grid etter hver lille bevegelse
        this->gridPosition.x = this->position.x / 32;
        this->gridPosition.y = this->position.y / 32;

        // Sjekk hvor mange blokker vi må teste i bredden
        int left = this->position.x / 32;
        int right = (this->position.x + 39) / 32; // 40px bred

        if (direction < 0) {
            int topY = this->position.y / 32;

            for (int x = left; x <= right; x++) {
                if (collitionMatrix[topY][x]) {
                    this->velocity.y = 0;
                    this->position.y = (topY + 1) * 32;
                    goto endVertical; // bryt ut av begge loops
                }
            }
        }

        if (direction > 0) {
            int bottomY = (this->position.y + 79) / 32; // 80px høy

            for (int x = left; x <= right; x++) {
                if (collitionMatrix[bottomY][x]) {
                    this->velocity.y = 0;
                    this->position.y = bottomY * 32 - 80;
                    goto endVertical;
                }
            }
        }
    }
    endVertical:;
    
    //Sjekk for kollisjon til venstre og høyre.
}