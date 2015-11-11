//
//  Player.hpp
//  LabOF1
//
//  Created by William Meaton on 09/11/2015.
//
//

#ifndef Player_hpp
#define Player_hpp

#include <stdio.h>
#include "Creature.hpp"
#include "Keyboard.hpp"
#include "StandardBullet.hpp"

#include <vector>

class Player : public Creature{
    vector<StandardBullet> *bullets;
public:
    Player(float x, float y, float movementSpeed, int health, bool visible, std::string imgPath, vector<StandardBullet> &bullets);
    void action();
    void fire();
};

#endif /* Player_hpp */
