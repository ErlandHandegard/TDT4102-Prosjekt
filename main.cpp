#include <iostream>
#include "AnimationWindow.h"
#include "include/window.h"
#include "include/player.h"
#include "include/worlds.h"

int main() {
    GameWindow gameWindow({100, 100}, {14*32, 7*32}, "Game window");

    Player player({100, 100});

    World world1("eworlds/firstWorld.txt");

    while(!gameWindow.should_close()){
        gameWindow.amountOfBlocksToRender();
        gameWindow.updateWindowPosition(world1);
        player.move(world1, gameWindow);
        gameWindow.updateWindow(world1);
        gameWindow.drawPlayer(player);
        gameWindow.next_frame();
    }
    return 0;
}