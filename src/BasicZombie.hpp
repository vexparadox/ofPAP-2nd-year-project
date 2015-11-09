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

class BasicZombie : public Creature{
public:
    std::string imgUrl;
    BasicZombie(int x, int y, int movementSpeed, int health, bool visible, std::string imgPath);
};

#endif /* BasicZombie_hpp */