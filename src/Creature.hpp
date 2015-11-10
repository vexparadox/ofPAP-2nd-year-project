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

class Creature : public Entity{
public:
    int health;
    float movementSpeed;
    Creature(int x, int y, float movementSpeed, int health, bool visible, std::string imgPath);
    int getHealth();
    void takeDamage(int dmg);
    void moveTo(float x, float y);
};

#endif /* Creature_hpp */
