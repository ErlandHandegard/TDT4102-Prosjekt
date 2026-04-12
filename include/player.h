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
        std::vector<std::vector<std::string>> inventory;
        std::vector<std::vector<std::string>> item; //Dette er hva som er i en gitt slott i inventory
        std::vector<std::vector<std::string>> amount; //Dette er mengden, men kan være mine for pickaxe
        int hotBarIndex; //Tall fra en til ti i hotbaren
        int currentBlockAmount; //Antall blokker om action er Build
        std::string action; //Tillatt handling er "attack", "Mine", "Build"
        std::string currentItem; //Hva han holder. For eksempel pickaxe. Viktig under tegning!
    public:
        //Skal lastes av vindu
        std::vector<std::vector<std::string>> getInventory() const {return inventory;}
        std::vector<std::vector<std::string>> getItem() const {return item;}
        std::vector<std::vector<std::string>> getAmount() const {return amount;}
        TDT4102::Point getGridPosition() const {return gridPosition;}

        Player(TDT4102::Point strartingPosition, const std::string &filePath); // Må laste inn ett bilde av karakteren og sette det som sprite.
        
        int getHealth() const { return health; }
        int getHotBarIndex() const { return hotBarIndex; }
        std::string getCurrentItem() const { return currentItem; }
        std::string getAction() const { return action; }
        TDT4102::Point getPosition() const { return position; }

        void move(const GameWindow& gameWindow, const World& world);

        void desideCurrentAction(const GameWindow& gameWindow);
        
        void executeAction(const GameWindow& gameWindow, World& world);
        
        // void attack();

        // void takeDamage(int damage);

        void mine(const GameWindow& gameWindow, World& world);

        void build(const GameWindow& gameWindow, World& world, std::string blockType);

        bool updateInventory(std::string blockType);

        void savePlayer();
};