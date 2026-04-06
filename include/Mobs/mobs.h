#pragma once
#include <iostream>
#include "AnimationWindow.h"
#include "include/worlds.h"

class MobileEntities{
    private:
        int health;
        TDT4102::Point position; 
        TDT4102::Point gridPosition; 
        TDT4102::Point velocity;
        TDT4102::Point acceleration;
        TDT4102::Point mobSize;
    public:
        MobileEntities(int type);
        int getHealth() const { return health; }
        TDT4102::Point getPosition() const { return position; }

        void move(const World& world, const GameWindow& gameWindow);

};