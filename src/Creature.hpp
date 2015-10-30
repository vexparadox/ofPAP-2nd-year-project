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
    int movementSpeed;
    Creature(int x, int y, int movementSpeed, int health, bool visible, std::string imgPath);
    int getHealth();
    void takeDamage(int dmg);
    void moveTo(int x, int y);
};

#endif /* Creature_hpp */
