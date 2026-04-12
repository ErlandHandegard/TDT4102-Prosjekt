#include "include/drops.h"

bool isCollitionItem(TDT4102::Point playerPos, TDT4102::Point itemPos){
    int itemUpper = itemPos.y, itemLower = itemPos.y + 16;
    int itemLeft = itemPos.x, itemRight = itemPos.x + 16;

    int playerUpper = playerPos.y, playerLower = playerPos.y + 80;
    int playerLeft = playerPos.x, playerRight = playerPos.x + 40;

    return (playerLower > itemUpper && playerUpper < itemLower && playerRight > itemLeft && playerLeft < itemRight);
}

ItemDrop::ItemDrop(TDT4102::Point originPoint, std::string blockType){
    this -> position.x = originPoint.x + 8;
    this -> position.y = originPoint.y + 16;
    this -> blockType = blockType;
    this -> shouldRemove = false;
}

std::string ItemDrop::getBlockType() const{
    if (this -> blockType == "1"){
        return "2";
    } else {
        return this -> blockType; 
    }
}

void ItemDrop::pickUp(Player& player){
    if (isCollitionItem(player.getPosition(), this -> position)){
        if (this -> blockType == "1"){
            this -> blockType = "2";
        }
        if (player.updateInventory(this -> blockType)){
            this -> shouldRemove = true;
        }
    }
}