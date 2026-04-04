#include "include/player.h"
#include "include/window.h"
#include "include/worlds.h"

Player::Player(TDT4102::Point strartingPosition){
    this -> health = 400;
    this -> position = strartingPosition;
    this -> velocity = TDT4102::Point(0, 0);
    this -> acceleration = TDT4102::Point(0, 0);
}

void Player::move(const World& world, const GameWindow& gameWindow) {
    this -> gridPosition.x = position.x / 32; // Dette er posisojonen til øvre venstre hjørne av spilleren
    this -> gridPosition.y = position.y / 32; 
    std::vector<std::vector<bool>> collitionMatrix = world.getCollitionMatrix();
    

    //Hopping
    if (gameWindow.is_key_down(KeyboardKey::SPACE)) {
        this -> velocity.y = -10; // Jumping velocity
    }
    // Bevegelse frem og tilbake
    if (gameWindow.is_key_down(KeyboardKey::A)) {
        this -> velocity.x = -5; // Move left
    }
    if (gameWindow.is_key_down(KeyboardKey::D)) {
        this -> velocity.x = 5; // Move right
    }
    this -> velocity.y += this -> acceleration.y;
    this -> velocity.x += this -> acceleration.x;
    this -> position.y += this -> velocity.y;
    this -> position.x += this -> velocity.x;
}