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
#include "Texture.hpp"
#include <boost/lexical_cast.hpp>
#include <vector>
#include "Tile.hpp"

class World{
private:
    static int xSize, ySize;
    static std::string path;
public:
    static void loadWorld();
    static void display();
    static ofImage worldImg;
    static void updateWorldImg();
    static vector<Tile> worldMatrix;
    static vector<Tile> tiles;
    static int numFlips;
    static void loadTiles();
    static int getxSize();
    static int getySize();
};

#endif /* World_hpp */
