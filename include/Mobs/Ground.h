#pragma once 
#include "mobs.h"


class Ground : public MobileEntities{
    private:
    public: 
    void move(const World& world, const GameWindow& gameWindow, const Player& player);
    Ground(TDT4102::Point point, std::string filepath);
};
