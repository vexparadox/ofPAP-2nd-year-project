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
    int health;
    float movementSpeed;
    Creature(float x, float y, float w, float h, float movementSpeed, int health);
    int getHealth();
    void takeDamage(int dmg);
    void moveTo(float x, float y);
    bool collide(vector<Entity> &v);
    
};

#endif /* Creature_hpp */
