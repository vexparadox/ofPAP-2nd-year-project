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
public:
    int x, y;
    bool visible;
    ofImage texture;
    std::string imgPath;
    Entity(int x, int y, bool visible, std::string imgPath);
};

#endif /* Entity_hpp */
