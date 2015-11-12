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
#include "ofMain.h"
enum spriteCodes{
    PLAYER = 0,
    stdBULLET = 1,
    BasicZOMBIE = 2,
    END_SPRITE = 3
};

class Sprite{
public:
    static ofImage textures[END_SPRITE];
    static void loadTextures(int w, int h);
    static ofImage getTexture(int i);
};
#endif /* Sprite_hpp */
