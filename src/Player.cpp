//
//  Player.cpp
//  LabOF1
//
//  Created by William Meaton on 09/11/2015.
//
//

#include "Player.hpp"

Player::Player(int x, int y, float movementSpeed, int health, bool visible, std::string imgPath) : Creature(x, y, movementSpeed, health, visible, imgPath){

}

void Player::move(){
    if (Keyboard::getRIGHT()) {
        x+=movementSpeed;
    }
    if(Keyboard::getLEFT()){
        x-=movementSpeed;
    }
    if(Keyboard::getUP()){
        y-=movementSpeed;
    }
    if(Keyboard::getDOWN()){
        y+=movementSpeed;
    }
}