//
//  StandardBullet.hpp
//  LabOF1
//
//  Created by William Meaton on 11/11/2015.
//
//

#ifndef StandardBullet_hpp
#define StandardBullet_hpp

#include <stdio.h>
#include "Entity.hpp"
#include "Creature.hpp"

class StandardBullet : public Entity{
private:
    int movementSpeed;
//this is a standard bullet
public:
    StandardBullet(float x, float y, float movementSpeed, bool visible, std::string imgPath);
    void moveTo(Creature &c);
    
    
};


#endif /* StandardBullet_hpp */
