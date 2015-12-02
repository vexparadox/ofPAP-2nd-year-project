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
#include "Enemy.hpp"

class BigZombie :public Enemy{
public:
    BigZombie(ofPoint position, float movementSpeed, float health, bool visible, float attackDamage);
    void display();

};

#endif /* BigZombie_hpp */
