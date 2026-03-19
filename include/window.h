#pragma once
#include <iostream>
#include "AnimationWindow.h"

/*
Flytte kamera i verden

Kanskje lage en person, men vi får se på det. 
*/

class GameWindow : public TDT4102::AnimationWindow{
    private: 
        int width;
        int height;
        int windowPositionX = 300;
        int windowPositionY = 100;
        double camerapositionX;
        double camerapositionY;
        TDT4102::AnimationWindow window; 
    public:
        GameWindow(TDT4102::Point position, int height, int width, TDT4102::Point cameraPosition, const std::string& title);

        void moveCamera(TDT4102::Point playerPosition);
        void updateWorld(const std::string &filePath);
};

