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
#include "Texture.hpp"
#include "Collider.hpp"
#include "World.hpp"

class Entity{
protected:
    bool visible;
public:
    float gravityValue = 10;
    ofPoint position, size, velocity;
    Entity(float x, float y, float w, float h, bool visible);
    bool onScreen();
    bool worldCollide(float vx, float vy);
    bool worldCollide(ofPoint velocity);
    bool entityCollide(const Entity &entity);
    void gravity(bool collision);
    void setVisible(bool set);
    bool isVisible();
};


#endif /* Entity_hpp */
