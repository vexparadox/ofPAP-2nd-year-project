//
//  Bullet.cpp
//  LabOF1
//
//  Created by William Meaton on 02/12/2015.
//
//

#include "Bullet.hpp"

Bullet::Bullet(ofPoint position, ofPoint target, float movementSpeed, bool visible, float damage = 0) : Entity(position, visible), movementSpeed(movementSpeed), damage(damage), target(target){
    direction = (target - position);
    direction.normalize();
}


void Bullet::update(){
    if(visible){
        position += direction*(movementSpeed);
    }
}

float Bullet::getDamage(){
    return damage;
}

bool Bullet::bulletWorldCollide(){
    float tempX = position.x + size.x/2;
    float tempY = position.y + size.y/2;
    ofPoint gridPos = ofPoint((int)tempX/TILE_SIZE, (int)tempY/TILE_SIZE);
    if(World::worldMatrix[gridPos.x + gridPos.y * World::getySize()].isSolid()){
        World::worldMatrix[gridPos.x + gridPos.y * World::getySize()].damageTile();
        return true;
    }
    return false;
}