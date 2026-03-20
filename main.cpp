#include <iostream>
#include "AnimationWindow.h"
#include "include/window.h"

int main() {
    bool gameRun = 1; 
    GameWindow gameWindow({100, 100}, 800, 1200, {100, 100}, "Game window");
    while(!gameWindow.should_close()){
        gameWindow.updateWorld("Worlds/firstWorld.txt");
    }
    return 0;
}