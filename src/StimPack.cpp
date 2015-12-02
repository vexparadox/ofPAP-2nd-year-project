//
//  StimPack.cpp
//  LabOF1
//
//  Created by William Meaton on 01/12/2015.
//
//

#include "StimPack.hpp"


StimPack::StimPack(ofPoint position, bool visible, float ability) : Item(position, visible), ability(ability){
    
}

void StimPack::itemAction(Player &p){
    p.gainHealth(ability);
}

void StimPack::display(){
    if(visible){
        Texture::getSprite(item_STIMPACK).draw(position);
    }
}

void StimPack::update(){
    this->gravity(true);
}