#include <iostream>
#pragma once
#include "AnimationWindow.h"

class Player {
    private:
        int health;
        TDT4102::Point position;
        TDT4102::Point velocity;
        TDT4102::Point acceleration;
    public:
        int getHealth() const { return health; }
        TDT4102::Point getPosition() const { return position; }

        void move();

        // void attack();

        // void takeDamage(int damage);

        // void mine();

        // void build();
};