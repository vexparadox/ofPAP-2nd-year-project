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
#include "DoubleBullet.hpp"


#include <vector>

class Player : public Creature{
private:
    vector<Bullet*> &bullets;
    bool doubleDamage;
    int doubleDamageShot = 0;
    int maxDoubleDamageShot = 50;
    float jetPackFuelMax = 20;
    float jetPackFuelMaxMaximum = 40;
    float jetPackFuel = 10;
    int ammo = 10;
public:
    Player(ofPoint position, float movementSpeed, float health, bool visible, vector<Bullet*> &bullets);
    void action();
    void fire();
    void display();
    void setDoubleDamage();
    void setDoubleDamageShot(int s);
    void addJetPackMax(float j);
    void setJetPackMax(float j);
    float getJetPackMax();
    float getJetPackCurrent();
};

#endif /* Player_hpp */
