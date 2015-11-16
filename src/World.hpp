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
#include "Sprite.hpp"
#include <boost/lexical_cast.hpp>
#include <vector>

class World{
public:
    static int xSize, ySize;
    static void loadWorld();
    static void display();
    static ofImage worldImg;
    static void updateWorldImg();
    static vector<int> worldMatrix;
};

#endif /* World_hpp */
