#include "Mobs/ground.h"


void Ground::move(const World& world, const GameWindow& gameWindow){
    //Tyngdekraften påvirker bakke mobs hele tiden, 
    // så vi legger til akselerasjonen i hastigheten hver frame i starten
    this -> velocity.y += this -> acceleration.y;

    //Henter kollisjonsmatrisen fra verdenen, og størrelsen på verdenen i blokker.
    std::vector<std::vector<bool>> collitionMatrix = world.getCollitionMatrix();
    int worldWidthInBlocks = world.getWorldSizeInBlocks().x;
    int worldHeightInBlocks = world.getWorldSizeInBlocks().y;
}