//
//  Enemy.cpp
//  LabOF1
//
//  Created by William Meaton on 16/10/2015.
//
//

#include "Enemy.hpp"

//this is more of template class than anything else

//the enemy class takes in all of the variables for the enemy but holds enemy specific movement
Enemy::Enemy(int x, int y, int health, bool visible) : Creature(x, y, health, visible){
    img.load("img.jpg");
    img.resize(health, health);
}

void Enemy::display(){
    if(visible){
        //ofDrawCircle(x, y, 50);
        img.draw(x, y);
    }
}