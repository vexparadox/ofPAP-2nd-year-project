//
//  Player.cpp
//  LabOF1
//
//  Created by William Meaton on 09/11/2015.
//
//

#include "Player.hpp"
ofImage texture;

Player::Player(float x, float y, float movementSpeed, float health, bool visible, vector<StandardBullet> &bullets) : Creature(x, y, SPRITE_SIZE, SPRITE_SIZE, movementSpeed, health, visible), bullets(bullets){
}

void Player::action(){
    this->gravity(true);
    //keyboard controls
    if (Keyboard::getRIGHT()) {
        if(this->worldCollide(movementSpeed, 0)){
            position.x += movementSpeed;
        }    }
    if(Keyboard::getLEFT()){
        if(this->worldCollide(-movementSpeed, 0)){
            position.x -= movementSpeed;
        }
    }
    if(Keyboard::getUP()){
        if(this->worldCollide(0, -movementSpeed*3)){
            position.y -= movementSpeed*3;
        }
    }
    if(Keyboard::getMOUSE1()){
        this->fire();
    }

}

void Player::display(){
    if(visible){
        Texture::getSprite(PLAYER).draw(position);
    }
}

//create a new bullet
void Player::fire(){
    if(bullets.size() <= ammo){
        bullets.push_back(StandardBullet(position, ofPoint(ofGetMouseX(),ofGetMouseY()), 20, true, 10));
    }
}