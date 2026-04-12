#include <iostream>
#include "AnimationWindow.h"
#include "include/window.h"
#include "include/player.h"
#include "include/worlds.h"
#include "include/Mobs/mobs.h"
#include "include/Mobs/Ground.h"
#include "include/perlinNoise/FastNoiseLite.h"


int main() {
    GameWindow gameWindow({100, 100}, {14*32, 7*32}, "Game window");

    Player player({100, 100});
    std::vector<std::unique_ptr<MobileEntities>> mobs;
    std::unique_ptr<MobileEntities> mobPtr = std::make_unique<Ground>(TDT4102::Point {30,150});
    mobs.push_back(std::move(mobPtr));

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
        for(const std::unique_ptr<MobileEntities>& mob : mobs){
            mob->move(world1,gameWindow);
        }        
        //Tegne funksjonene må legges til sist. 
        gameWindow.drawWindow(world);
        gameWindow.drawDrops(world); 
        gameWindow.drawPlayer(player);
        gameWindow.drawMobs(mobs);

        gameWindow.openGameMenu(player, world);

        gameWindow.next_frame();
    }

    return 0;
}