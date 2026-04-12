#pragma once
#include <cmath>
#include <iostream>
#include <ctime>
#include "AnimationWindow.h"
#include "window.h"
#include "worlds.h"
#include "player.h"

enum class Colition {
    none,
    left,
    right,
    top,
    bottom,
};

class MobileEntities{
    protected:
        int health;
        TDT4102::Point position; 
        TDT4102::Point gridPosition; 
        TDT4102::Point velocity;
        TDT4102::Point acceleration;
        TDT4102::Point mobSize;
        Colition colition;
        bool moving;
    public:
        MobileEntities(TDT4102::Point startingPosition);
        int getHealth() const { return health; }
        TDT4102::Point getPosition() const { return position; }
        TDT4102::Point getMobsize() const { return mobSize; }
        int width() const {return getMobsize().x;}
        int height() const {return getMobsize().y;}
        TDT4102::Point getVelocity() const { return velocity; }
        TDT4102::Point getAcceleration() const { return acceleration; }

        virtual void move(const World& world, const GameWindow& gameWindow, const Player& player) = 0;
        
};

int randomValueZeroMax(int max);

