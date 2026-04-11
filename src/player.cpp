#include <cmath>
#include "include/player.h"
#include "include/window.h"
#include "include/worlds.h"

bool isCollision(const std::vector<std::vector<bool>>& matrix, int x, int y) {
    if (y < 0 || y >= matrix.size() ||
        x < 0 || x >= matrix[y].size()) {
        return true; // utenfor verden = solid
    }
    return matrix[y][x];
}

Player::Player(TDT4102::Point strartingPosition, const std::string &filePath){
    this -> health = 400;
    this -> position = strartingPosition;
    this -> velocity = TDT4102::Point(0, 0);
    this -> acceleration = TDT4102::Point(0, 1);
    this -> playerSize = TDT4102::Point(40, 80);
    this -> hotBarIndex = 0;

    std::filesystem::path filename(filePath);
    std::ifstream playerInventory{filename};
    std::string inventoryRow;

    //Denne må endres
    for (int i = 0; i < 4; ++i){
        std::getline(playerInventory, inventoryRow);
        std::vector<std::string> row;
        std::string item;
        for (char c : inventoryRow){
            if (c != ','){
                item += c;
            } else {
                row.push_back(item);
                item = "";
            }
        }
        this -> inventory.push_back(row);
    }
}

void Player::desideCurrentAction(const GameWindow& gameWindow, World& world){
    this -> hotBarIndex -= gameWindow.get_delta_mouse_wheel();
    if (this -> hotBarIndex < 0){
        this -> hotBarIndex = 0;
    } else if (this -> hotBarIndex > 9){
        this -> hotBarIndex = 9;
    }
    std::string findAction = this -> inventory.at(0).at(hotBarIndex);
    for (char c : findAction){
        this -> action += c;
        if (c == '*'){
            this -> action = "";
        }
    }
}

void Player::mine(const GameWindow& gameWindow, World& world){
    if (gameWindow.is_left_mouse_button_down()){
        world.deleteBlock(gameWindow.getMouseGridPosition());
    }    
}

void Player::build(const GameWindow& gameWindow, World& world){
    if (gameWindow.is_right_mouse_button_down()){
        world.setBlock(gameWindow.getMouseGridPosition(), "1");
    } 
}

void Player::move(const GameWindow& gameWindow, const World& world) {
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

    //Henter kollisjonsmatrisen fra verdenen, og størrelsen på verdenen i blokker.
    const auto& collitionMatrix = world.getCollitionMatrix();

    //Skjekker om spilleren er på bakken slik at han har lov å hoppe. 
    bool onGround = false;

    int left  = position.x / 32;
    int right = (position.x + 39) / 32;
    int y     = (position.y + 80) / 32;

    for (int x = left; x <= right; x++) {
        if (isCollision(collitionMatrix, x, y)) {
            onGround = true;
            break;
        }
    }

    //Hopping
    if (gameWindow.is_key_down(KeyboardKey::SPACE) && onGround) {
        this -> velocity.y = -15; // Jumping velocity
    }

    // Legger inn steps slik at vi ikke får tunnelering i vertikal retning.
    int stepsY = abs((int)velocity.y);
    int dirY = (velocity.y > 0) ? 1 : -1;

    //Går gjennom hver step i vertikal retning og sjekker for kollisjon.
    // Dersom det er kollisjon setter vi hastigheten i den retningen til 0 og plasserer spilleren rett ved siden av blokken han kolliderte med.
    for (int i = 0; i < stepsY; i++) {

        position.y += dirY;

        int left   = position.x / 32;
        int right  = (position.x + 39) / 32;
        int top    = position.y / 32;
        int bottom = (position.y + 79) / 32;

        bool hit = false;

        if (dirY < 0) { // opp
            for (int x = left; x <= right; x++) {
                if (isCollision(collitionMatrix, x, top)) {
                    velocity.y = 0;
                    position.y = (top + 1) * 32;
                    hit = true;
                    break;
                }
            }
        } 
        else { // ned
            for (int x = left; x <= right; x++) {
                if (isCollision(collitionMatrix, x, bottom)) {
                    velocity.y = 0;
                    position.y = bottom * 32 - 80;
                    hit = true;
                    break;
                }
            }
        }
        if (hit) break;
    }

    //Sjekk for kollisjon til venstre og høyre.
    //Her også legger vi inn steps for å unngå tunneling i horisontal retning.
    int stepsX = abs((int)velocity.x);
    int dirX = (velocity.x > 0) ? 1 : -1;

    for (int i = 0; i < stepsX; i++) {

        position.x += dirX;

        int left   = (int)floor(position.x / 32.0f);
        int right  = (int)floor((position.x + 39) / 32.0f);
        int top    = (int)floor(position.y / 32.0f);
        int bottom = (int)floor((position.y + 79) / 32.0f);

        bool hit = false;

        if (dirX < 0) { // venstre
            for (int y = top; y <= bottom; y++) {
                if (isCollision(collitionMatrix, left, y)) {
                    velocity.x = 0;
                    position.x = (left + 1) * 32;
                    hit = true;
                    break;
                }
            }
        } else { // høyre
        for (int y = top; y <= bottom; y++) {
            if (isCollision(collitionMatrix, right, y)) {
                velocity.x = 0;
                position.x = right * 32 - 40;
                hit = true;
                break;
            }
        }
    }
    if (hit) break;
    }
}

void Player::updateInventory(){

}

void Player::savePlayer(){

}