#include <iostream>
#include "AnimationWindow.h"
#include "include/window.h"

int main() {
    bool run = 1; 

    GameWindow gameWindow({100, 100}, 400, 600, {100, 100}, "Game window");

	gameWindow.wait_for_close();
    return 0;
}