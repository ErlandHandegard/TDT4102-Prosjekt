#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <unordered_map>
#include "AnimationWindow.h"

class World;
class Player;

class GameWindow : public TDT4102::AnimationWindow{
    private: 
        TDT4102::Point gridPosition;    //Denne angir hvilket blokker som er vits å rendere. 
        TDT4102::Point cameraPosition;  //Skal være kameraposisjonen i pixelgriddet
        TDT4102::Point blocksToRender;  //Skal være en tuple med hvilke blokker i vær retning som skal rendere
        std::unordered_map<std::string, TDT4102::Image> imageCache;  // Cache for block images
        bool openMeny;
        bool wasEscPressed;
    public: 
        /*
        Bare initialiserer det første vinduet
        */
        GameWindow(TDT4102::Point windowPosition, TDT4102::Point startingDimensions, const std::string& title);

        /*
        Oppdaterer for vær frame. Denne skal ta inn antall monstre, spiller, NPC alt etter hvor langt vi kommer. 
        */
        void amountOfBlocksToRender();
        void updateWindowPosition(const World& world, const Player& player);
        void drawWindow(const World& world);
        void drawPlayer(const Player& player);
        // void drawMobs(const std::vector<Mob>& mobs); Vi har enda ikke laget mobs
        /* 
        Dersom esc blir trykt på åpnes en ny meny og man kan lagre quit eller lage ny verden og laste opp den. 
        */
        void openGameMenu(const Player& player); 
};