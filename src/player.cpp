#include "include/player.h"
#include "include/window.h"

Player::Player(TDT4102::Point strartingPosition){
    this -> health = 400;
    this -> position = strartingPosition;
    this -> velocity = TDT4102::Point(0, 0);
    this -> acceleration = TDT4102::Point(0, 0);
}

void Player::move(const World& world, const GameWindow& gameWindow) {
    if (gameWindow.is_key_down(KeyboardKey::A)) {
        position.x -= 5; // Move left
    }
        if (gameWindow.is_key_down(KeyboardKey::D)) {
        position.x += 5; // Move right
    }
    if (gameWindow.is_key_down(KeyboardKey::W)) {
        position.y -= 5; // Move up
    }
    if (gameWindow.is_key_down(KeyboardKey::S)) {
        position.y += 5; // Move down
    }

}