//
//  Creature.hpp
//  LabOF1
//
//  Created by William Meaton on 16/10/2015.
//
//

#ifndef Creature_hpp
#define Creature_hpp

#include <stdio.h>
#include "Entity.hpp"
#include <math.h>
//creatures are any organic entity in the game
class Creature : public Entity{
public:
    float health;
    float movementSpeed;
    Creature(float x, float y, float w, float h, float movementSpeed, float health, bool visible);
    int getHealth();
    bool isDead();
    void takeDamage(float dmg);
    void moveTo(float x, float y);
    void moveTo(ofPoint target);
};

#endif /* Creature_hpp */
