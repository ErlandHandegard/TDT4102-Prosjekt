#include <iostream>
#include <fstream>
#include "include/window.h"

GameWindow::GameWindow(TDT4102::Point windowPosition):
    TDT4102::AnimationWindow(windowPosition.x, windowPosition.y, title = "Game Window")
{

}


//Funksjonen skal ta inn mobs, players og rett antall blocker. 
void GameWindow::updateWindow(){


}