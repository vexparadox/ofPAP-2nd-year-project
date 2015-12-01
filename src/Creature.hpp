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
protected:
    float health;
    float movementSpeed;
public:
    Creature(ofPoint position, float w, float h, float movementSpeed, float health, bool visible);
    bool isDead();
    void takeDamage(float dmg);
    void moveTo(float x, float y);
    void moveTo(ofPoint target);
    void setHealth(float h);
    float getHealth();
};

#endif /* Creature_hpp */
