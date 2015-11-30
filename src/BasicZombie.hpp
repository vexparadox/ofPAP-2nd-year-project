//
//  BasicZombie.hpp
//  LabOF1
//
//  Created by William Meaton on 17/10/2015.
//
//

#ifndef BasicZombie_hpp
#define BasicZombie_hpp

#include <stdio.h>
#include "Creature.hpp"
#include "ofMain.h"

//this holds the basic zombie creature
class BasicZombie : public Creature{
public:
    float attackDamage;
    BasicZombie(float x, float y, float movementSpeed, float health, float attackDamage, bool visible);
    void display();
};

#endif /* BasicZombie_hpp */