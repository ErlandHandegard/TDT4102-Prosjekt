#include "Mobs/mobs.h"

MobileEntities::MobileEntities(TDT4102::Point startPosition){
    this -> health = 100;
    this -> position = startPosition;
    this -> velocity = TDT4102::Point(0,0);
    this -> acceleration = TDT4102::Point(0,1);
    this -> mobSize  = TDT4102::Point(80,40);
    this -> moving = 0;
}

