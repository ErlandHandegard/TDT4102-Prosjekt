#include <iostream>
#include <fstream>
#include "include/window.h"

GameWindow::GameWindow(TDT4102::Point windowPosition, TDT4102::Point startingDimensions, const std::string& title):
    AnimationWindow(windowPosition.x, windowPosition.y, startingDimensions.x, startingDimensions.y, title = "Game Window")
{
    
}


//Funksjonen skal ta inn mobs, players og rett antall blocker. 
void GameWindow::updateWindow(){


}