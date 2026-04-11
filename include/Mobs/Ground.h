#pragma once 
#include "mobs.h"


class Ground : public MobileEntities{
    private:
    public: 
    void move(const World& world, const GameWindow& gameWindow);
};
