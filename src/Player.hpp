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
private:
    vector<StandardBullet> &bullets;
public:
    float jetPackFuel = 10;
    int ammo = 10;
    Player(ofPoint position, float movementSpeed, float health, bool visible, vector<StandardBullet> &bullets);
    void action();
    void fire();
    void display();
};

#endif /* Player_hpp */
