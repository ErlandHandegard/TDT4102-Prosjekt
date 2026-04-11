#include <iostream>
#include "AnimationWindow.h"
#include "include/window.h"
#include "include/player.h"
#include "include/worlds.h"
#include "include/Mobs/mobs.h"

int main() {
    GameWindow gameWindow({100, 100}, {14*32, 7*32}, "Game window");

    Player player({100, 100});
    std::vector<std::unique_ptr<MobileEntities>> mobs;
    std::unique_ptr<MobileEntities> mobPtr = std::make_unique<MobileEntities>(TDT4102::Point {30,150});
    mobs.push_back(std::move(mobPtr));

    World world1("eworlds/physicsTestWorld.txt");

    while(!gameWindow.should_close()){
        //Oppdaterer antall blokker som skal rendres
        gameWindow.amountOfBlocksToRender();

        //Uppdaterer posisjonen til vinduet og spilleren
        gameWindow.updateWindowPosition(world1, player);
        player.move(world1, gameWindow);
        
        //Tegne funksjonene må legges til sist. 
        gameWindow.drawWindow(world1);
        gameWindow.drawPlayer(player);
        gameWindow.drawMobs(mobs);

        gameWindow.next_frame();
    }
    return 0;
}