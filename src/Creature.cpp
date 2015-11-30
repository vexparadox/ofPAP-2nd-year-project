//
//  Creature.cpp
//  LabOF1
//
//  Created by William Meaton on 16/10/2015.
//
//

#include "Creature.hpp"

//the Creature class holds the Health, Speed, damage etc of the creature
Creature::Creature(float x, float y, float w, float h, float movementSpeed, float health, bool visible):Entity(x, y, w, h, visible), health(health), movementSpeed(movementSpeed){
    
}

void Creature::takeDamage(float dmg){
    health -= dmg;
}

void Creature::moveTo(ofPoint target){
    this -> moveTo(target.x, target.y);
}

void Creature::moveTo(float mX, float mY){
    if(!visible){
        return;
    }
    ofPoint target = ofPoint(mX, mY);
    ofPoint direction = target - position;
    direction.normalize();
    position += direction*(movementSpeed);

    if(worldCollide(direction*movementSpeed)){
        position += direction*movementSpeed;
    }
}

bool Creature::isDead(){
    if(health <= 0){
        return true;
    }
    return false;
}