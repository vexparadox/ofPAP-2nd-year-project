//
//  Sprite.cpp
//  LabOF1
//
//  Created by William Meaton on 12/11/2015.
//
//

#include "Texture.hpp"

ofImage Texture::spriteImages[END_SPRITE];
ofImage Texture::tileImages[END_TILE];

void Texture::loadAll(bool resize){
    //load all the textures
    //Sprites saved as S_i.png
    for(int i = 0; i < END_SPRITE; i++){
        spriteImages[i].load("S_"+std::to_string(i)+".png");
        if(resize){
            spriteImages[i].resize(SPRITE_SIZE, SPRITE_SIZE);
        }
    }
    //Tiles saved as T_j.png
    for(int j = 0; j < END_TILE; j++){
        tileImages[j].load("T_"+std::to_string(j)+".png");
        if(resize){
            tileImages[j].resize(TILE_SIZE, TILE_SIZE);
        }
    }
}

ofImage Texture::getSprite(int i){
    return spriteImages[i];
}

ofImage Texture::getTile(int i){
    return tileImages[i];
}

float Texture::getSpriteWidth(int i){
    return spriteImages[i].getWidth();
}

float Texture::getSpriteHeight(int i){
    return spriteImages[i].getHeight();
}

float Texture::getTileHeight(int i){
    return tileImages[i].getHeight();
}

float Texture::getTileWidth(int i){
    return tileImages[i].getWidth();
}