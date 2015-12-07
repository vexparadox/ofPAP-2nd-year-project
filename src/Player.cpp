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
    if(doubleDamageShot > maxDoubleDamageShot){
        doubleDamage = false;
        doubleDamageShot = 0;
    }
    
    if(jetPackFuel < jetPackFuelMax){
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

float Player::getJetPackMax(){
    return jetPackFuelMax;
}

void Player::setJetPackFuel(float f){
    //if you're trying to set it higher than the maximum
    if(f > jetPackFuelMax){
        jetPackFuel = jetPackFuelMax;
        return;
    }
    jetPackFuel = f;
}

float Player::getJetPackCurrent(){
    return jetPackFuel;
}

bool Player::addJetPackMax(float j){
    //if it's already at the maximum
    if(jetPackFuelMax == jetPackFuelMaxMaximum){
        //check to see if you can add some on to the fuel isntead of expanding the capcity
        if(jetPackFuel+j > jetPackFuelMax){
            //if it's going to overflow just set it to max
            jetPackFuel = jetPackFuelMax;
            return true;
        }
        //else just addit
        jetPackFuel += j;
        return true;
    }
    //if the max+j is greater then the max-capacity
    if(jetPackFuelMax+j > jetPackFuelMaxMaximum){
        //just set it to max
        jetPackFuelMax = jetPackFuelMaxMaximum;
        return true;
    }
    //just to the maximum capcity
    jetPackFuelMax += j;
    return true;
}
void Player::setJetPackMax(float j){
    //make sure you're not setting it above max capacity
    if(j > jetPackFuelMaxMaximum){
        jetPackFuel = jetPackFuelMaxMaximum;
        return;
    }
    jetPackFuelMax = j;
}

void Player::setDoubleDamageShot(int s){
    doubleDamageShot = s;
}

void Player::setDoubleDamage(){
    //incase you pick up two at once
    if(!doubleDamage){
        doubleDamage = true;
    }
    //reset the damage shot anyways
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