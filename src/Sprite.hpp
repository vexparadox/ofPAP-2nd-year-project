//
//  Sprite.hpp
//  LabOF1
//
//  Created by William Meaton on 12/11/2015.
//
//

#ifndef Sprite_hpp
#define Sprite_hpp

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
    SKY = 0,
    GRASS_TOP = 1,
    DIRT_CENTER = 2,
    PLAYER = 3,
    BasicZOMBIE = 4,
    stdBULLET = 5,
    END_SPRITE = 6,
    SPRITE_SIZE = 50
};

class Sprite{
public:
    static ofImage textures[END_SPRITE];
    static void loadTextures();
    static ofImage getTexture(int i);
    static float getWidth(int i);
    static float getHeight(int i);
};
#endif /* Sprite_hpp */
