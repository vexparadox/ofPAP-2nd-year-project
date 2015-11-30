//
//  Creature.cpp
//  LabOF1
//
//  Created by William Meaton on 16/10/2015.
//
//

#include "Creature.hpp"

//the Creature class holds the Health, Speed, damage etc of the creature
Creature::Creature(float x, float y, float w, float h, float movementSpeed, int health):Entity(x, y, w, h), health(health), movementSpeed(movementSpeed){
    
}

void Creature::takeDamage(int dmg){
    health -= dmg;
}

void Creature::moveTo(float mX, float mY){
    ofPoint target = ofPoint(mX, mY);
    ofPoint direction = target - position;
    direction.normalize();
    position += direction*(movementSpeed);

    if(worldCollide(direction*movementSpeed)){
        position += direction*movementSpeed;
    }
}

bool Creature::collide(vector<Entity> &v){
    //collision code goes here
    return true;
}