#pragma once
#include <iostream>
#include "AnimationWindow.h"

class ItemDrop{
    private:
        TDT4102::Point position;
        TDT4102::Point velocity;
        TDT4102::Point acceleration;
        TDT4102::Point gridPosition;
    public:
        ItemDrop();

        void move(); 

        void pickUp();
};