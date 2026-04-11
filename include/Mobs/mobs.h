#pragma once
#include <iostream>
#include "AnimationWindow.h"
#include "window.h"
#include "worlds.h"

class MobileEntities{
    protected:
        int health;
        TDT4102::Point position; 
        TDT4102::Point gridPosition; 
        TDT4102::Point velocity;
        TDT4102::Point acceleration;
        TDT4102::Point mobSize;
        bool moving;
    public:
        MobileEntities(TDT4102::Point startingPosition);
        int getHealth() const { return health; }
        TDT4102::Point getPosition() const { return position; }
        TDT4102::Point getMobsize() const { return mobSize; }
        TDT4102::Point getVelocity() const { return velocity; }
        TDT4102::Point getAcceleration() const { return acceleration; }

        // void move(const World& world, const GameWindow& gameWindow);
        
};