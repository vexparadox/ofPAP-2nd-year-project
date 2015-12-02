//
//  Bullet.hpp
//  LabOF1
//
//  Created by William Meaton on 02/12/2015.
//
//

#ifndef Bullet_hpp
#define Bullet_hpp

#include <stdio.h>
#include "Entity.hpp"

class Bullet: public Entity{
protected:
    float movementSpeed;
    float damage;
    ofPoint target, velocity, direction;
public:
    Bullet(ofPoint position, ofPoint target, float movementSpeed, bool visible, float damage);
    virtual ~Bullet(){};
    virtual void update();
    virtual bool bulletWorldCollide();
    virtual void display(){};
    float getDamage();

};
#endif /* Bullet_hpp */
