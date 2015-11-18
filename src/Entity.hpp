//
//  Entity.hpp
//  LabOF1
//
//  Created by William Meaton on 17/10/2015.
//
//

#ifndef Entity_hpp
#define Entity_hpp

#include <stdio.h>
#include "ofMain.h"
#include "Sprite.hpp"
#include "Collider.hpp"
#include "World.hpp"

class Entity{
private:
    float x, y, w, h;
public:
    ofPoint position, size;
    Collider collider;
    Entity(float x, float y, float w, float h);
    bool onScreen();
    bool worldCollide();
};

#endif /* Entity_hpp */
