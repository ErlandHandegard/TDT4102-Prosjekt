#include <iostream>
#include "AnimationWindow.h"
#include "include/window.h"

int main() {
    GameWindow gameWindow({100, 100}, 800, 1200, {100, 100}, "Game window", "eworlds/firstWorld.txt");

    // gameWindow.updateWorld("eworlds/firstWorld.txt");
    // gameWindow.wait_for_close(); 
    while(!gameWindow.should_close()){
        gameWindow.updateWorld("eworlds/firstWorld.txt");
        gameWindow.moveCamera();
        gameWindow.next_frame();
    }
    return 0;
}