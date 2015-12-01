//
//  BigZombie.hpp
//  LabOF1
//
//  Created by William Meaton on 01/12/2015.
//
//

#ifndef BigZombie_hpp
#define BigZombie_hpp

#include <stdio.h>
#include "Creature.hpp"

class BigZombie :public Creature{
    
public:
    float attackDamage;
    BigZombie(ofPoint position, float movementSpeed, float health, float attackDamage, bool visible);
    void display();

};

#endif /* BigZombie_hpp */
