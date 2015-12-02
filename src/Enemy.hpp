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
#include "Player.hpp"
class Enemy : public Creature{
private:
    float attackDamage;
public:
    Enemy(ofPoint position, float movementSpeed, float health, bool visible, float attackDamage);
    virtual void display(){};
    virtual void update(Player &p);
    float getAttackDamage();
};
#endif /* Enemy_hpp */
