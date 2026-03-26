#include <iostream>
#include "AnimationWindow.h"
#include "include/window.h"
#include "include/worlds.h"

int main() {
    GameWindow gameWindow({100, 100}, {9*32, 4*32}, "Game window");

    World world1("eworlds/firstWorld.txt");

    while(!gameWindow.should_close()){
        gameWindow.updateWindowPosition(world1);
        gameWindow.updateWindow(world1);
        gameWindow.next_frame();
    }
    return 0;
}