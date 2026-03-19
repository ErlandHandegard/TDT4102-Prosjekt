#include <iostream>
#include "AnimationWindow.h"
#include "include/window.h"

int main() {
    TDT4102::AnimationWindow window;

    TDT4102::Image image("pictures/dirtBlock.png");

    while(!window.should_close()) {
        TDT4102::Point topLeftCorner {0, 0};
        TDT4102::Point mouse = window.get_mouse_coordinates();
        int imageWidth = mouse.x;
        int imageHeight = mouse.y;
        window.draw_image(topLeftCorner, image, imageWidth, imageHeight);
        window.next_frame();
    }

    /*
    
    bool run = 1; 

    GameWindow gameWindow({100, 100}, 400, 600, {100, 100}, "Game window");

	gameWindow.wait_for_close();
    */
    return 0;
}