#include <iostream>
#include "AnimationWindow.h"
#include "include/window.h"
#include "include/player.h"
#include "include/worlds.h"
#include "include/perlinNoise/FastNoiseLite.h"


int main() {
    GameWindow gameWindow({100, 100}, {14*32, 7*32}, "Game window");

    Player player({100, 100});

    World world1("eworlds/testWorldGenerator.txt");
    
    world1.worldGenerator("eworlds/testWorldGenerator.txt", 200, 100, 67);


    while(!gameWindow.should_close()){
        //Oppdaterer antall blokker som skal rendres
        gameWindow.amountOfBlocksToRender();

        //Uppdaterer posisjonen til vinduet og spilleren
        gameWindow.updateWindowPosition(world1, player);
        player.move(world1, gameWindow);
        
        //Tegne funksjonene må legges til sist. 
        gameWindow.drawWindow(world1);
        gameWindow.drawPlayer(player);

        gameWindow.next_frame();
    }

    return 0;
}