//
//  Creature.cpp
//  LabOF1
//
//  Created by William Meaton on 16/10/2015.
//
//

#include "Creature.hpp"

//the Creature class holds the Health, Speed, damage etc of the creature
Creature::Creature(ofPoint position, float w, float h, float movementSpeed, float health, bool visible):Entity(position, w, h, visible), health(health), movementSpeed(movementSpeed){
    maxHealth = health;
}
//the creature takes damage
void Creature::takeDamage(float dmg){
    health -= dmg;
}

//takes a vector instead of the x and y point
void Creature::moveTo(ofPoint target){
    this -> moveTo(target.x, target.y);
}

//will move towards an x and y point with the movement speed
void Creature::moveTo(float mX, float mY){
    if(!visible){
        return;
    }
    ofPoint target = ofPoint(mX, mY);
    ofPoint direction = target - position;
    direction.normalize();

    if(worldCollide(direction*movementSpeed)){
        position += direction*(movementSpeed);
    }else{
        position += direction*(movementSpeed/4);
    }
}

float Creature::getHealth(){
    //return the health of the creature
    return health;
}
void Creature::setHealth(float h){
    //set the health to a specific float
    health = h;
}

void Creature::gainHealth(float h){
    //don't allow more than max health
    if(health+h > maxHealth){
        health = maxHealth;
        return;
    }
    health+=h;
}

//returns if the creature is dead or not
bool Creature::isDead(){
    if(health <= 0){
        return true;
    }
    return false;
}