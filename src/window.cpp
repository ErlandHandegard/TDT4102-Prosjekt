#include <iostream>
#include <fstream>
#include "include/window.h"

GameWindow::GameWindow(TDT4102::Point windowPosition, TDT4102::Point startingDimensions, const std::string& title):
    AnimationWindow(windowPosition.x, windowPosition.y, startingDimensions.x, startingDimensions.y, title)
{
    this -> gridPosition = TDT4102::Point(0, 0);
    this -> cameraPosition = TDT4102::Point(0,0);
    this -> blocksToRender = TDT4102::Point(10, 5); 
}

//Funksjonen skal ta inn mobs, players og rett antall blocker. 
void GameWindow::updateWindow(){
    this -> setBackgroundColor(TDT4102::Color::dark_green);

    
}

void OpenMeny(){

}