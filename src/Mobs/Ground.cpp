#include "Mobs/ground.h"

Ground::Ground(TDT4102::Point point) : MobileEntities(point){
}

void Ground::move(const World& world, const GameWindow& gameWindow, const Player& player){
    //Tyngdekraften påvirker bakke mobs hele tiden, 
    // så vi legger til akselerasjonen i hastigheten hver frame i starten
    this -> velocity.y += this -> acceleration.y;

    //Henter kollisjonsmatrisen fra verdenen, og størrelsen på verdenen i blokker.
    const auto& collitionMatrix = world.getCollitionMatrix();

    //Skjekker om mobben er på bakken slik at han har lov å hoppe. 
    bool onGround = false;

    int left  = position.x / 32;
    int right = (position.x + this->width() -1) / 32;
    int y     = (position.y + this->height()) / 32;
    

    for (int x = left; x <= right; x++) {
        if (isCollision(collitionMatrix, x, y)) {
            onGround = true;
            break;
        }
    }

    Colition newColition = Colition::none;

    // gir hopping hvis mobben er på bakken og har kolidert enten til høyre eller venstre for seg
    if(onGround && (this -> colition == Colition::left || this -> colition == Colition::right)){
        this->velocity.y = -15;
    }

    //Får mobben til å følge etter player hvis de ikke er nærme nok hverandre
    TDT4102::Point deltaPlayer = {player.getPosition().x-this->position.x, player.getPosition().y-this->position.y};
    if(abs(deltaPlayer.x) > this->width()-10 && abs(deltaPlayer.x) < 800 && abs(deltaPlayer.y) < 300) {
        this->velocity.x = (deltaPlayer.x> 0) ? 4 : -4;
    }else{
        this->velocity.x = 0;
    }



    // Legger inn steps slik at vi ikke får tunnelering i vertikal retning.
    int stepsY = abs((int)velocity.y);
    int dirY = (velocity.y > 0) ? 1 : -1;

    //Går gjennom hver step i vertikal retning og sjekker for kollisjon.
    // Dersom det er kollisjon setter vi hastigheten i den retningen til 0 og plasserer moben rett ved siden av blokken han kolliderte med.
    for (int i = 0; i < stepsY; i++) {

        position.y += dirY;

        int left   = position.x / 32;
        int right  = (position.x + this->width() -1) / 32;
        int top    = position.y / 32;
        int bottom = (position.y + this->height() -1) / 32;

        if (dirY < 0) { // opp
            if (!isCollision(collitionMatrix,right+1,bottom) && this -> colition == Colition::right){
                velocity.x = 4;
                this -> colition = Colition::none;
            }else if (!isCollision(collitionMatrix,left-1,bottom) && this -> colition == Colition::left){
                velocity.x = -4;
                this -> colition = Colition::none;
            }
            for (int x = left; x <= right; x++) {
                if (isCollision(collitionMatrix, x, top)) {
                    velocity.y = 0;
                    position.y = (top + 1) * 32;
                    newColition = Colition::top;
                    break;
                }
            }
        } 
        else { // ned
            for (int x = left; x <= right; x++) {
                if (isCollision(collitionMatrix, x, bottom)) {
                    velocity.y = 0;
                    position.y = bottom * 32 - this->height();
                    newColition = Colition::bottom;
                    break;
                }
            }
        }
        if (newColition == Colition::top || newColition == Colition::bottom) break;
    }

    //Sjekk for kollisjon til venstre og høyre.
    //Her også legger vi inn steps for å unngå tunneling i horisontal retning.
    int stepsX = abs((int)velocity.x);
    int dirX = (velocity.x > 0) ? 1 : -1;

    newColition = Colition::none;
    for (int i = 0; i < stepsX; i++) {

        position.x += dirX;

        int left   = (int)floor(position.x / 32.0f);
        int right  = (int)floor((position.x + this->width() -1) / 32.0f);
        int top    = (int)floor(position.y / 32.0f);
        int bottom = (int)floor((position.y + this->height()-1) / 32.0f);
    
        if (dirX < 0) { // venstre
            for (int y = top; y <= bottom; y++) {
                if (isCollision(collitionMatrix, left, y)) {
                    velocity.x = 0;
                    position.x = (left + 1) * 32;
                    newColition = Colition::left;
                    break;
                }
            }
        } else { // høyre
        for (int y = top; y <= bottom; y++) {
            if (isCollision(collitionMatrix, right, y)) {
                velocity.x = 0;
                position.x = right * 32 - this->width();
                newColition = Colition::right;
                break;
            }
        }
    }
    if (newColition == Colition::right ||newColition == Colition::left) {
        colition = newColition; 
        break;
    }
    }
}