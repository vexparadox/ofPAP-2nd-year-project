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

class Entity{
private:
    float x, y;
public:
    ofPoint position;
    bool visible;
    ofImage texture;
    std::string imgPath;
    Entity(float x, float y, bool visible, std::string imgPath);
    void display();
};

#endif /* Entity_hpp */
