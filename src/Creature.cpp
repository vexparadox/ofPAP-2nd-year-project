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
    float tempX = mX-position.x;
    float tempY = mY-position.y;
    position.x += tempX*movementSpeed;
    position.y += tempY*movementSpeed;
}

bool Creature::collide(vector<Entity> &v){
    
}