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

void World::setBlock(TDT4102::Point gridPosition, std::string blockType){
    this -> worldBlocks[gridPosition.x][gridPosition.y] = blockType; //Mulig disse må byttes og
}

void World::deleteBlock(TDT4102::Point gridPosition){
    this -> worldBlocks[gridPosition.x][gridPosition.y] = "0"; //Mulig x og y må byttes
}

void World::worldGenerator(const std::string &filePath, int worldWidth, int worldHeight, int seed){
    //Liste for å legge til alle blokkene. 
    std::vector<std::vector<std::string>> blocks(worldWidth, std::vector<std::string>(worldHeight, "0"));

    FastNoiseLite noise;
    noise.SetNoiseType(FastNoiseLite::NoiseType_Perlin);
    noise.SetSeed(seed);
    noise.SetFrequency(0.05f);

    //Vector som skal holde høyden på hver x posisjon.
    // Denne er for å lage fjell på toppen. 
    std::vector<int> height; 
    for (int x = 0; x < worldWidth; x++){
        // Rå støy fra perlin funksjonen
        float rawNoise = noise.GetNoise(static_cast<float>(x), 0.0f);

        // Finner avstanden fra sentrum slik at jeg kan ha større åser lengre ut i verden
        float distanceFromCenter = std::abs((x - worldWidth / 2.0f) / (worldWidth / 2.0f));

        // Her øker styrken med en eksponensial funksjon. Hadde vært kulere med ett 4. grads polinom slik at det ble 0 i kantene
        float heightMultiplier = std::pow(distanceFromCenter, 2);

        float finalHeight = (rawNoise * heightMultiplier * (worldHeight * 0.3f)) + (worldHeight * 0.80f);
        height.push_back(static_cast<int>(finalHeight));
    }
    
    // Konfigurer støy for huler
    FastNoiseLite caveNoise;
    caveNoise.SetNoiseType(FastNoiseLite::NoiseType_Perlin);
    caveNoise.SetFrequency(0.05f); // Mellomstor frekvens for huler

    //Bruke denne for hule lesing for å få slanger.
    //std::abs(noise.GetNoise(x, y)) < 0.05f

    //Konfigurer støy for ores
    FastNoiseLite oreNoise; 
    oreNoise.SetNoiseType(FastNoiseLite::NoiseType_Perlin);
    oreNoise.SetFrequency(0.10f);

    // En enkelt loop over verdenen
    for (int x = 0; x < worldWidth; x++) {
        for (int y = 0; y < worldHeight; y++) {
            float fx = static_cast<float>(x);
            float fy = static_cast<float>(y);

            if (y < worldHeight - height[x]) {
                blocks[x][y] = "0"; // Luft over bakken
                continue; // Ingen vits i å sjekke huler/malm i lufta
            } 
            else if (y == worldHeight - height[x]) {
                blocks[x][y] = "1"; // Gress
            } 
            else if (y > worldHeight - height[x] && y < worldHeight - height[x] + 9) {
                blocks[x][y] = "2"; // Jord
            } 
            else {
                blocks[x][y] = "3"; // Stein
            }

            // Sjekk huler først
            float caveVal = caveNoise.GetNoise(fx, fy);
            if (caveVal > 0.6f) { // Kun luft hvis støyen er veldig høy
                blocks[x][y] = "0";
                continue; // Gå til neste blokk, trenger ikke sjekke malm her
            }

            if (blocks[x][y] == "3"){
                float copperVal = oreNoise.GetNoise(fx + 100.0f, fy + 100.0f);
                float ironVal = oreNoise.GetNoise(fx + 200.0f, fy + 200.0f);
                float silverVal = oreNoise.GetNoise(fx + 300.0f, fy + 300.0f);
                float goldVal = oreNoise.GetNoise(fx + 400.0f, fy + 40.0f);

                if (goldVal > 0.70f) blocks[x][y] = "5";
                else if (silverVal > 0.65f) blocks[x][y] = "7";
                else if (ironVal > 0.60f) blocks[x][y] = "6";
                else if (copperVal > 0.55f) blocks[x][y] = "4";
            }
        }
    }

    std::ofstream worldFile{filePath};
    if (worldFile.is_open()) {
        for (int y = 0; y < worldHeight; y++) {
            for (int x = 0; x < worldWidth; x++) {
                worldFile << blocks[x][y] << (x == worldWidth - 1 ? "" : ",");
            }
            worldFile << "\n";
        }
        worldFile.close();
    }

}

void World::growGrass(){

}

void World::saveWorld(const std::string &filePath){

}