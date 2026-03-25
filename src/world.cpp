#include <iostream>
#include <filesystem>
#include <fstream>
#include <vector>
#include "AnimationWindow.h"
#include "include/worlds.h"

World::World(const std::string &filePath){
    /*
    Skal laste filen og returnere vectorer med blokkene. 
    */
    std::filesystem::path filename(filePath);
    std::ifstream worldFile{filename};
    std::string worldLineInText;

    while (std::getline(worldFile, worldLineInText)){
        std::vector<std::string> row; 
        std::string block;
        for (char c : worldLineInText){
            if (c != ','){
                block += c; 
            } else {
                row.push_back(block);
                block = "";
            }
        }
        row.push_back(block);
        this -> worldBlocks.push_back(row);
    }

    this -> worldGrid = TDT4102::Point(this->worldBlocks.at(0).size(), this->worldBlocks.size());
    this -> worldPixelSize = TDT4102::Point((this -> worldGrid.x * 32), (this -> worldGrid.y * 32));
}

void World::worldGenerator(){

}