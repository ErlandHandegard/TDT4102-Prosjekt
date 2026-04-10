#pragma once
#include <iostream>
#include "AnimationWindow.h"

class World;
class GameWindow;

class Player {
    private:
        int health;
        TDT4102::Point position;
        TDT4102::Point gridPosition; 
        TDT4102::Point velocity;
        TDT4102::Point acceleration;
        TDT4102::Point playerSize;
        std::vector<std::vector<char>> inventory;
    public:
        //Skal lastes av vindu
        std::vector<std::vector<char>> getInventory() const {return inventory;}
        TDT4102::Point getGridPosition() const {return gridPosition;}

        Player(TDT4102::Point strartingPosition, const std::string &filePath); // Må laste inn ett bilde av karakteren og sette det som sprite.
        
        int getHealth() const { return health; }
        TDT4102::Point getPosition() const { return position; }

        void move(const World& world, const GameWindow& gameWindow);

        // void attack();

        // void takeDamage(int damage);

        // void mine();

        // void build();

        void savePlayer();
};