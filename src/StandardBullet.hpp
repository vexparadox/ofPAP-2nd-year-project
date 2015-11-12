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
private:
    int movementSpeed;
    bool visible;
//this is a standard bullet
public:
    StandardBullet(ofPoint position, ofPoint target, float movementSpeed, bool visible);
    void update();
    void display();
};


#endif /* StandardBullet_hpp */
