#pragma once
#include <iostream>
#include "AnimationWindow.h"


/*
Flytte kamera i verden

Kanskje lage en person, men vi får se på det. 
*/

class GameWindow : public TDT4102::AnimationWindow{
    private: 
        TDT4102::Point gridPosition;    //Denne angir hvilket blokker som er vits å rendere. 
        TDT4102::Point cameraPosition;  //Skal være kameraposisjonen i pixelgriddet
        TDT4102::Point blocksToRender;  //Skal være en tuple med hvilke blokker i vær retning som skal rendere
    public: 
        GameWindow();

        void updateWindow();
};