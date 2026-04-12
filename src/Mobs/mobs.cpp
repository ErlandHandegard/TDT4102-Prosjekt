#include "Mobs/mobs.h"

MobileEntities::MobileEntities(TDT4102::Point startPosition){
    this -> health = 100;
    this -> position = startPosition;
    this -> velocity = TDT4102::Point(4,0);
    this -> acceleration = TDT4102::Point(0,1);
    this -> mobSize  = TDT4102::Point(80,40);
    this -> moving = 0;
    this -> colition = Colition::none;
}

int randomValueZeroMax(int max){
    srand(time(0));
    int nr = rand() % max;
    return nr;
}

