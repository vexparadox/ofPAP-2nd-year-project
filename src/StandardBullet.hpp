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

class StandardBullet : public Entity{
protected:
    float movementSpeed;
    float damage;
    ofPoint target, velocity, direction;
public:
    StandardBullet(ofPoint position, ofPoint target, float movementSpeed, bool visible, float damage);
    void update();
    float getDamage();
    void display();
};


#endif /* StandardBullet_hpp */
