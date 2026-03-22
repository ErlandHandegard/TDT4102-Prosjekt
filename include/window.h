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
        int gridWidth;
        int gridHeight; 
        int camerapositionX;
        int camerapositionY;
    public: 
        
        GameWindow(TDT4102::Point position, int height, int width, TDT4102::Point cameraPosition, const std::string& title, const std::string &filePath);

        void moveCamera();

        //std::vector<int> cameraPosToGridPos(int width, int height, int camerapositionX, int camerapositionY);

        void updateWorld(const std::string &filePath);
};