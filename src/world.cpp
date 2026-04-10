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
        std::vector<bool> colitionActive;
        std::string block;
        for (char c : worldLineInText){
            if (c != ','){
                block += c; 
            } else {
                if (block == "0"){
                    colitionActive.push_back(0);
                } else {
                    colitionActive.push_back(1); 
                }
                row.push_back(block);
                block = "";
            }
        }
        row.push_back(block);
        this -> collitionBlock.push_back(colitionActive);
        this -> worldBlocks.push_back(row);
    }
    this -> worldGrid = TDT4102::Point(static_cast<int>(this->worldBlocks.at(0).size()),
    static_cast<int>(this->worldBlocks.size()));

    this -> worldPixelSize = TDT4102::Point((this -> worldGrid.x * 32), (this -> worldGrid.y * 32));
}

void World::worldGenerator(const std::string &filePath, int worldWidth, int worldHeight, int seed){
    std::filesystem::path filename(filePath);
    std::ofstream worldFile{filename};

    FastNoiseLite noise;
    noise.SetNoiseType(FastNoiseLite::NoiseType_Perlin);
    noise.SetSeed(seed);

    //Liste for å legge til alle blokkene. 
    std::vector<std::vector<std::string>> blocks;
    
    //Vector som skal holde høyden på hver x posisjon.
    // Denne er for å lage fjell på toppen. 
    std::vector<int> height; 

    std::vector<std::vector<int>> caves;
    std::vector<std::vector<int>> copper;
    std::vector<std::vector<int>> iron;
    std::vector<std::vector<int>> silver;
    std::vector<std::vector<int>> gold;
    
    
}

void World::growGrass(){

}

void World::saveWorld(const std::string &filePath){

}