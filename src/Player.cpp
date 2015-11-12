//
//  Player.cpp
//  LabOF1
//
//  Created by William Meaton on 09/11/2015.
//
//

#include "Player.hpp"
ofImage texture;

Player::Player(float x, float y, float movementSpeed, int health, bool visible, vector<StandardBullet> &bullets) : Creature(x, y, movementSpeed, health), visible(visible){
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

void Player::display(){
    if(visible){
        Sprite::getTexture(PLAYER).draw(position);
    }
}

void Player::fire(){
    bullets->push_back(StandardBullet(position.x, position.y, 0.2, true));
}