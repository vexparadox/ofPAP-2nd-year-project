//
//  Creature.cpp
//  LabOF1
//
//  Created by William Meaton on 16/10/2015.
//
//

#include "Creature.hpp"

//the Creature class holds the Health, Speed, damage etc of the creature
Creature::Creature(int x, int y, int movementSpeed, int health, bool visible = true, std::string imgPath = ""):Entity(x, y, visible, imgPath), health(health), movementSpeed(movementSpeed){
    
}

void Creature::takeDamage(int dmg){
    health -= dmg;
}

void Creature::moveTo(int mX, int mY){
    int tempX = x - mX;
    int tempY = y - mY;
    
    x += tempX*movementSpeed;
    x += tempY*movementSpeed;
}