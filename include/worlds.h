#pragma once
#include <iostream>

class World{
    private:
        TDT4102::Point worldGrid;
        TDT4102::Point worldPixelSize;
        
    public:
        std::vector<std::vector<std::string>> worldBlocks; 
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
        generer en verden

        Funksjon som 

        antall mobs

        spiller

        ødelegg

        plasser
        */

};