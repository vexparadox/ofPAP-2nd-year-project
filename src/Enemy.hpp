//
//  Enemy.hpp
//  LabOF1
//
//  Created by William Meaton on 16/10/2015.
//
//

#ifndef Enemy_hpp
#define Enemy_hpp

#include "Creature.hpp"
#include "ofMain.h"
#include <stdio.h>
#include <iostream>

class Enemy : public Creature{
public:
    Enemy(int x, int y, int health, bool visible);
    void display();
private:
    ofImage img;
};

#endif /* Enemy_hpp */
