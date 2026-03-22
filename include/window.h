#pragma once
#include <iostream>
#include "AnimationWindow.h"


class GameWindow : public TDT4102::AnimationWindow{
    private: 
        int gridWidth;     //Dette er antall blokker i x-retning
        int gridHeight;    //Dette er antall blokker i y-retning
        int width;         //Bredden til kameraet er brukt til å bestemme hvilke blokker som skal vises
        int height;        //Høyden til kameraet gjør samme som bredden men i y-retning
        TDT4102::Point cameraPosition; //Dette er kameraposisjonen i griddet. Som må oversettes til gridposition
    public: 

        GameWindow(TDT4102::Point position, int height, int width, TDT4102::Point cameraPosition, const std::string& title);

        //Denne funksjonen tar cameraposisjonen og flytter til gridPosisjon slik at jeg vet hvilke blokker som må "rendere".
        int cameraPositionToGridPosition(); 
    
        void moveCamera();

        void updateWorld(const std::string &filePath);


};