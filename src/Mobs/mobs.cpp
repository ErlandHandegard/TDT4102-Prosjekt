#include "Mobs/mobs.h"

MobileEntities::MobileEntities(TDT4102::Point startPosition){
    this -> health = 100;
    this -> position = startPosition;
    this -> velocity = TDT4102::Point(0,0);
    this -> acceleration = TDT4102::Point(0,1);
    this -> mobSize  = TDT4102::Point(80,40);
}
//Skal lage move, begynner med å få tegnet stillestående rektangel.
// void MobileEntities::move(const World& world, const GameWindow& gameWindow){
//     //Tyngdekraften påvirker bakke mobs hele tiden, 
//     // så vi legger til akselerasjonen i hastigheten hver frame i starten
//     this -> velocity.y += this -> acceleration.y;

//     //Henter kollisjonsmatrisen fra verdenen, og størrelsen på verdenen i blokker.
//     std::vector<std::vector<bool>> collitionMatrix = world.getCollitionMatrix();
//     int worldWidthInBlocks = world.getWorldSizeInBlocks().x;
//     int worldHeightInBlocks = world.getWorldSizeInBlocks().y;
// }
