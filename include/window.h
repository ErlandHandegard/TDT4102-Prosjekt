#pragma once
#include <iostream>
#include "AnimationWindow.h"


class GameWindow : public TDT4102::AnimationWindow{
    private: 
        int width;
        int height;
    public: 
        int gridWidth;
        int gridHeight;
        int camerapositionX = 0;
        int camerapositionY = 0;

        GameWindow(TDT4102::Point position, int height, int width, TDT4102::Point cameraPosition, const std::string& title, const std::string &filePath);

    
        void moveCamera();

        void updateWorld(const std::string &filePath);

        
};