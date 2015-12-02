//
//  StandardBullet.cpp
//  LabOF1
//
//  Created by William Meaton on 11/11/2015.
//
//

#include "StandardBullet.hpp"
StandardBullet::StandardBullet(ofPoint position, ofPoint target, float movementSpeed, bool visible, float damage = 0) : Entity(position, visible), movementSpeed(movementSpeed), damage(damage), target(target){
    direction = (target - position);
    direction.normalize();
}
//update the bullets position and pull towards the target
void StandardBullet::update(){
    if(visible){
        position += direction*(movementSpeed);
    }
}

//display the bullet
void StandardBullet::display(){
    if(visible){
        Texture::getSprite(stdBULLET).draw(position);
    }
}

float StandardBullet::getDamage(){
    return damage;
}

bool StandardBullet::bulletWorldCollide(){
    float tempX = position.x + size.x/2;
    float tempY = position.y + size.y/2;
    ofPoint gridPos = ofPoint((int)tempX/TILE_SIZE, (int)tempY/TILE_SIZE);
    if(World::worldMatrix[gridPos.x + gridPos.y * World::getySize()].isSolid()){
        World::worldMatrix[gridPos.x + gridPos.y * World::getySize()].damageTile();
        return true;
    }
    return false;
}