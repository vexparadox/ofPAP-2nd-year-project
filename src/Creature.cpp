//
//  Creature.cpp
//  LabOF1
//
//  Created by William Meaton on 16/10/2015.
//
//

#include "Creature.hpp"

//the Creature class holds the Health, Speed, damage etc of the creature
Creature::Creature(ofPoint position, float movementSpeed, float health, bool visible):Entity(position, visible), health(health), movementSpeed(movementSpeed){
    maxHealth = health;
}
//the creature takes damage
void Creature::takeDamage(float dmg){
    health -= dmg;
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