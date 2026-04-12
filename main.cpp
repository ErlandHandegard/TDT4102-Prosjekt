#include <iostream>
#include "AnimationWindow.h"
#include "include/window.h"
#include "include/player.h"
#include "include/worlds.h"
#include "include/perlinNoise/FastNoiseLite.h"


int main() {
    GameWindow gameWindow({100, 100}, {14*32, 7*32}, "Game window");

    Player player({100, 100}, "dplayer/examplePlayer.txt");

    World initWorld("eworlds/testWorldGenerator.txt");
    
    initWorld.worldGenerator("eworlds/testWorldGenerator.txt", 200, 100, 67);
    
    //Bare en quick fix slik at det er lettere å demonstrere random tarrain
    //Vi dropper load og save world for nå.
    World world("eworlds/testWorldGenerator.txt");

    while(!gameWindow.should_close()){
        //Oppdaterer antall blokker som skal rendres
        gameWindow.amountOfBlocksToRender();

        //Uppdaterer posisjonen til vinduet og spilleren
        gameWindow.updateWindowPosition(world, player);
        player.move(gameWindow, world);
        player.desideCurrentAction(gameWindow);
        player.executeAction(gameWindow, world);
        world.updateBlockDrops(player);
        world.growGrass();
        
        //Tegne funksjonene må legges til sist. 
        gameWindow.drawWindow(world);
        gameWindow.drawDrops(world); 
        gameWindow.drawPlayer(player);

        gameWindow.openGameMenu(player, world);

        gameWindow.next_frame();
    }

    return 0;
}