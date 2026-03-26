#pragma once
#include <iostream>
#include "AnimationWindow.h"
#include "include/worlds.h"

class MobileEntities{
    private:
        int hitPoints;
        TDT4102::Point position; 
    public:
        MobileEntities(int type);
};