#pragma once
#include <iostream>
#include "AnimationWindow.h"

class GameWindow : public TDT4102::AnimationWindow{
    private: 
        TDT4102::Point gridPosition;    //Denne angir hvilket blokker som er vits å rendere. 
        TDT4102::Point cameraPosition;  //Skal være kameraposisjonen i pixelgriddet
        TDT4102::Point blocksToRender;  //Skal være en tuple med hvilke blokker i vær retning som skal rendere
    public: 
        /*
        Bare initialiserer det første vinduet
        */
        GameWindow(TDT4102::Point windowPosition, TDT4102::Point startingDimensions, const std::string& title);

        /*
        Oppdaterer for vær frame. Denne skal ta inn antall monstre, spiller, NPC alt etter hvor langt vi kommer. 
        */
        void updateWindow();

        /* 
        Dersom esc blir trykt på åpnes en ny meny og man kan lagre quit eller lage ny verden og laste opp den. 
        */
        void openMeny(); 
};