//
//  DoubleBullet.hpp
//  LabOF1
//
//  Created by William Meaton on 02/12/2015.
//
//

#ifndef DoubleBullet_hpp
#define DoubleBullet_hpp

#include <stdio.h>
#include "Bullet.hpp"

class DoubleBullet : public Bullet{
public:
    void display();
    DoubleBullet(ofPoint position, ofPoint target, float movementSpeed, bool visible, float damage);
};
#endif /* DoubleBullet_hpp */
