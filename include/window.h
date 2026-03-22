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
        TDT4102::Point gridPosition;  //Denne angir hvilket blokker som er vits å rendere. 
        int blocksToRenderX;          //Antall blokker å rende i x retning
        int blocksToRenderY;          //Antall blokker å rende i y retning
    public: 
        
        GameWindow(TDT4102::Point position, int height, int width, TDT4102::Point cameraPosition, const std::string& title, const std::string &filePath);

        void moveCamera();

        void cameraPosToGridPos();

        void updateWorld(const std::string &filePath);
};