//
//  Sprite.cpp
//  LabOF1
//
//  Created by William Meaton on 12/11/2015.
//
//

#include "Sprite.hpp"

ofImage Sprite::textures[END_SPRITE];

void Sprite::loadTextures(){
    //load all the textures
    for(int i = 0; i < END_SPRITE; i++){
        textures[i].load(std::to_string(i)+".png");
        textures[i].resize(SPRITE_SIZE, SPRITE_SIZE);
    }
}

ofImage Sprite::getTexture(int i){
    return textures[i];
}

float Sprite::getWidth(int i){
    return textures[i].getWidth();
}

float Sprite::getHeight(int i){
    return textures[i].getHeight();
}