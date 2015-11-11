//
//  Player.cpp
//  LabOF1
//
//  Created by William Meaton on 09/11/2015.
//
//

#include "Player.hpp"


Player::Player(float x, float y, float movementSpeed, int health, bool visible, std::string imgPath, vector<StandardBullet> &bullets) : Creature(x, y, movementSpeed, health, visible, imgPath){
    this->bullets = &bullets;
}

void Player::action(){
    if (Keyboard::getRIGHT()) {
        position.x+=movementSpeed;
    }
    if(Keyboard::getLEFT()){
        position.x-=movementSpeed;
    }
    if(Keyboard::getUP()){
        position.y-=movementSpeed;
    }
    if(Keyboard::getDOWN()){
        position.y+=movementSpeed;
    }
    if(Keyboard::getSPACE()){
        this->fire();
    }
}

void Player::fire(){
    bullets->push_back(StandardBullet(position.x, position.y, 0.2, true, "bullet.jpg"));
}