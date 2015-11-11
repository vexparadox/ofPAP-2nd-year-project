//
//  StandardBullet.cpp
//  LabOF1
//
//  Created by William Meaton on 11/11/2015.
//
//

#include "StandardBullet.hpp"

StandardBullet::StandardBullet(float x, float y, float movementSpeed, bool visible = true, std::string imgPath = ""):Entity(x, y, visible, imgPath), movementSpeed(movementSpeed){
    
}

void moveTo(Creature &c){
    auto temp = &c;
    
}