#pragma once
#include <iostream>
#include <filesystem>
#include <fstream>
#include <vector>
#include <string>
#include "AnimationWindow.h"

class World{
    private:
        TDT4102::Point worldGrid;
        TDT4102::Point worldPixelSize;
        std::vector<std::vector<std::string>> worldBlocks;
        std::vector<std::vector<bool>> collitionBlock;
    public:
        /*Deklarerer get funksjoner*/
        std::vector<std::vector<std::string>> getBlocks() const {return worldBlocks;}
        TDT4102::Point getWorldSizeInPixels() const {return worldPixelSize;}
        TDT4102::Point getWorldSizeInBlocks() const {return worldGrid;}
        std::vector<std::vector<bool>> getCollitionMatrix() const {return collitionBlock;}
        /*
        Planen nå. Jeg laster alltid inn firstWorld.txt
        World laster inn denne. 

        Dersom jeg trukker esc kan jeg lagre og bytte verden. 
        */
        World(const std::string &filePath);
        /*
        Dersom denne funksjonen blir kalt opp i menyen 
        skal den lage en verden å legge den inn i
        eworlds-mappen
        */
        void worldGenerator();
        /*
        Funksjon som 

        antall mobs

        spiller

        ødelegg

        plasser
        */

};