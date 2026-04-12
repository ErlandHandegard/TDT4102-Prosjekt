#include "Mobs/mobs.h"

MobileEntities::MobileEntities(TDT4102::Point startPosition, std::string filepath){
    this -> health = 100;
    this -> position = startPosition;
    this -> velocity = TDT4102::Point(0,0);
    this -> acceleration = TDT4102::Point(0,1);
    this -> mobSize  = TDT4102::Point(80,40);
    this -> moving = 0;
    this -> colition = Colition::none;
    this -> look = TDT4102::Image(filepath);
}

int randomValueZeroMax(int max){
    srand(time(0));
    int nr = rand() % max;
    return nr;
}

