//
//  Creature.cpp
//  LabOF1
//
//  Created by William Meaton on 16/10/2015.
//
//

#include "Creature.hpp"

//the Creature class holds the Health, Speed, damage etc of the creature
Creature::Creature(int x, int y, float movementSpeed, int health, bool visible = true, std::string imgPath = ""):Entity(x, y, visible, imgPath), health(health), movementSpeed(movementSpeed){
    
}

void Creature::takeDamage(int dmg){
    health -= dmg;
}

void Creature::moveTo(float mX, float mY){
    float tempX = mX-x;
    float tempY = mY-y;
    std::cout << movementSpeed <<  std::endl;
    x += tempX*movementSpeed;
    y += tempY*movementSpeed;
}