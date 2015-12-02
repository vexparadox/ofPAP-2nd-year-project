//
//  Player.cpp
//  LabOF1
//
//  Created by William Meaton on 09/11/2015.
//
//

#include "Player.hpp"
ofImage texture;

Player::Player(ofPoint position, float movementSpeed, float health, bool visible, vector<Bullet*> &bullets) : Creature(position, movementSpeed, health, visible), bullets(bullets){
}

void Player::action(){
    //only have 40 shots
    if(doubleDamageShot > 40){
        this->setDoubleDamage();
    }
    
    if(jetPackFuel < 20){
        jetPackFuel+= 0.2;
    }
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
        if(jetPackFuel > 0){
            if(this->worldCollide(0, -movementSpeed*3)){
                position.y -= movementSpeed*3;
                jetPackFuel -= 1;
            }
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

void Player::setDoubleDamage(){
    doubleDamage = !doubleDamage;
    doubleDamageShot = 0;
}

//create a new bullet
void Player::fire(){
    if(bullets.size() <= ammo){
        if(doubleDamage){
            bullets.push_back(new DoubleBullet(position, ofPoint(ofGetMouseX(),ofGetMouseY()), 20, true, 20));
            doubleDamageShot++;
            return;
        }
        bullets.push_back(new StandardBullet(position, ofPoint(ofGetMouseX(),ofGetMouseY()), 20, true, 10));
    }
}