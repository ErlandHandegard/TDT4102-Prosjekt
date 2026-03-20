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
    public: 
        int camerapositionX = 0;
        int camerapositionY = 0;
        GameWindow(TDT4102::Point position, int height, int width, TDT4102::Point cameraPosition, const std::string& title);

    
        void moveCamera();
        void updateWorld(const std::string &filePath);
};