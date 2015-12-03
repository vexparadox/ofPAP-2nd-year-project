//
//  Sprite.hpp
//  LabOF1
//
//  Created by William Meaton on 12/11/2015.
//
//

#ifndef Texture_hpp
#define Texture_hpp

#include <stdio.h>
#include <vector>
#include "ofMain.h"

/*his function loads and holds all the sprites that will be used in the game
 it's beneficial to do this because there ever only needs to be one instance of the loaded texture for each object in the game
 
 If BasicZombie is made and shown 100 times in once scene, it's pointless to hold 100 ofImages in 100 classes. Using one static array and calling like
 Sprite::getTexture(ENUM_CODE)->draw();
 
 Each enum-code relates to a place in the array and a specific texture, these are kept the same by naming the files i.jpg and using a for loop. As long as there are no changes to the enum values, there is no chance of unexpected results.
 
 */

enum spriteCodes{
    PLAYER = 0,
    BasicZOMBIE = 1,
    BigZOMBIE = 2,
    stdBULLET = 3,
    ddBULLET = 4,
    item_STIMPACK = 5,
    item_DD = 6,
    item_JETPACK = 7,
    END_SPRITE = 8,
    SPRITE_SIZE = 50
};

enum tileCodes{
    SKY = 0,
    GRASS_TOP = 1,
    DIRT_CENTER = 2,
    STONE = 3,
    END_TILE = 4,
    TILE_SIZE = 50
};

class Texture{
public:
    static ofImage spriteImages[END_SPRITE];
    static ofImage tileImages [END_TILE];
    static void loadAll(bool resize);
    static ofImage getSprite(int i);
    static ofImage getTile(int i);
    static float getSpriteWidth(int i);
    static float getSpriteHeight(int i);
    static float getTileWidth(int i);
    static float getTileHeight(int i);
};
#endif /* Sprite_hpp */
