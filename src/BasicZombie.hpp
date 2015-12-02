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
#include "Enemy.hpp"

//this holds the basic zombie creature
class BasicZombie : public Enemy{
public:
    BasicZombie(ofPoint position, float movementSpeed, float health, bool visible, float attackDamage);
    ~BasicZombie(){};
    void display();
    
};

#endif /* BasicZombie_hpp */