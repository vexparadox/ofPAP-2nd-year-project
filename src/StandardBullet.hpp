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
#include "Bullet.hpp"

class StandardBullet : public Bullet{
public:
    StandardBullet(ofPoint position, ofPoint target, float movementSpeed, bool visible, float damage);
    ~StandardBullet(){};
    void display();
};


#endif /* StandardBullet_hpp */
