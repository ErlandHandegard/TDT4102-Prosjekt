#include <iostream>
#include "AnimationWindow.h"
#include "include/window.h"

int main() {

    GameWindow gameWindow({100, 100}, 1400, 1600, {100, 100}, "Game window");
    
    gameWindow.updateWorld("Worlds/firstWorld.txt");

	gameWindow.wait_for_close();


    return 0;
}