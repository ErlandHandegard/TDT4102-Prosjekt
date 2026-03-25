#include <iostream>
#include "AnimationWindow.h"
#include "include/window.h"
#include "include/worlds.h"

int main() {
    GameWindow gameWindow({100, 100}, {1024, 768}, "Game window");

    World world1("eworlds/firstWorld.txt");

    while(!gameWindow.should_close()){
        gameWindow.next_frame();
    }
    return 0;
}