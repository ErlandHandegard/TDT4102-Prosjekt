#pragma once
#include <iostream>
#include "AnimationWindow.h"
#include "include/player.h"

class ItemDrop{
    private:
        TDT4102::Point position;
        std::string blockType;
    public:
        ItemDrop(TDT4102::Point originPoint, std::string blockType);

        void pickUp(Player& player);
};