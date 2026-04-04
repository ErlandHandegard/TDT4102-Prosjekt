#pragma once
#include <iostream>
#include "AnimationWindow.h"

class World;
class GameWindow;

class Player {
    private:
        int health;
        TDT4102::Point position;
        TDT4102::Point velocity;
        TDT4102::Point acceleration;
    public:
        Player(TDT4102::Point strartingPosition); // Må laste inn ett bilde av karakteren og sette det som sprite.
        int getHealth() const { return health; }
        TDT4102::Point getPosition() const { return position; }

        void move(const World& world, const GameWindow& gameWindow);

        // void attack();

        // void takeDamage(int damage);

        // void mine();

        // void build();
};