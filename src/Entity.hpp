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

class Entity{
private:
    float x, y, w, h;
public:
    ofPoint position;
    Entity(float x, float y, float w, float h);
    bool onScreen();
};

#endif /* Entity_hpp */
