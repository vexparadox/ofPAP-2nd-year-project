//
//  Player.cpp
//  LabOF1
//
//  Created by William Meaton on 09/11/2015.
//
//

#include "Player.hpp"
ofImage texture;

Player::Player(float x, float y, float movementSpeed, int health, bool visible, vector<StandardBullet> &bullets) : Creature(x, y, Sprite::getWidth(PLAYER), Sprite::getHeight(PLAYER), movementSpeed, health), visible(visible), bullets(bullets){
}

void Player::action(){
    //keyboard controls
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
    if(Keyboard::getMOUSE1()){
        this->fire();
    }
}

void Player::display(){
    if(visible){
        Sprite::getTexture(PLAYER).draw(position);
    }
}

//create a bullet
void Player::fire(){
    if(bullets.size() <= ammo){
    bullets.push_back(StandardBullet(position, ofPoint(ofGetMouseX(),ofGetMouseY()), 0.1, true));
    }
}