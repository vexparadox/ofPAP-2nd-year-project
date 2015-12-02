//
//  Enemy.hpp
//  LabOF1
//
//  Created by William Meaton on 02/12/2015.
//
//

#ifndef Enemy_hpp
#define Enemy_hpp

#include <stdio.h>
#include "Creature.hpp"
class Enemy : public Creature{
public:
    Enemy(ofPoint position, float movementSpeed, float health, bool visible);
    virtual void display(){};
};
#endif /* Enemy_hpp */
