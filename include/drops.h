#pragma once
#include <iostream>
#include "AnimationWindow.h"
#include "include/player.h"

class ItemDrop{
    private:
        TDT4102::Point position;
        std::string blockType;
    public:
        bool shouldRemove;
        TDT4102::Point getPosition() const {return position; }
        std::string getBlockType() const;
        ItemDrop(TDT4102::Point originPoint, std::string blockType);

        void pickUp(Player& player);
};