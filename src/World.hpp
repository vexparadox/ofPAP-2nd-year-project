//
//  World.hpp
//  LabOF1
//
//  Created by William Meaton on 14/11/2015.
//
//

#ifndef World_hpp
#define World_hpp

#include <stdio.h>
#include "ofMain.h"
#include <fstream>

class World{
public:
    int scale;
    std::string path;
    World(std::string path, int scale);
    void loadWorld();
};

#endif /* World_hpp */
