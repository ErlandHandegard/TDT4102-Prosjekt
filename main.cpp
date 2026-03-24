#include <iostream>
#include "AnimationWindow.h"
#include "include/window.h"
#include "include/worlds.h"

int main() {
    GameWindow gameWindow();

    // gameWindow.updateWorld("eworlds/firstWorld.txt");
    // gameWindow.wait_for_close(); 
    while(!gameWindow.should_close()){
        gameWindow.next_frame();
    }
    return 0;
}