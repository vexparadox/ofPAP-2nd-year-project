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
#include <boost/lexical_cast.hpp>
#include <vector>

enum worldCodes{
    GRASS_Tile = 0;
    END_Tile = 1;
};

class World{
public:
    int xSize, ySize;
    std::string path;
    World(std::string path, int xScale, int yScale);
    void loadWorld();
    vector< vector<int> > worldMatrix;
};

#endif /* World_hpp */
