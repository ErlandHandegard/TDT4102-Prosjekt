#pragma once
#include <iostream>
#include "AnimationWindow.h"

class GameWindow : public TDT4102::AnimationWindow{
    private: 
        int width;
        int height;
        int windowPositionX = 300;
        int windowPositionY = 100;
        double camerapositionX;
        double camerapositionY;
    public:
        GameWindow(TDT4102::Point position, int height, int width, TDT4102::Point cameraPosition, const std::string& title);

        void moveCamera(TDT4102::Point playerPosition);

};

