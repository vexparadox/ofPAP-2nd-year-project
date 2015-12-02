//
//  StimPack.cpp
//  LabOF1
//
//  Created by William Meaton on 01/12/2015.
//
//

#include "StimPack.hpp"


StimPack::StimPack(ofPoint position, bool visible) : Item(position, visible){
    
}

void StimPack::itemAction(Player &p){
    
}

void StimPack::display(){
    if(visible){
        Texture::getSprite(PLAYER).draw(position);
    }
}