//
//  DoubleDamage.cpp
//  LabOF1
//
//  Created by William Meaton on 02/12/2015.
//
//

#include "DoubleDamage.hpp"

DoubleDamage::DoubleDamage(ofPoint position, bool visible) : Item(position, visible){
    
}

bool DoubleDamage::itemAction(Player &p){
    p.setDoubleDamage();
}

void DoubleDamage::display(){
    if(visible){
        Texture::getSprite(item_DD).draw(position);
    }
}

void DoubleDamage::update(){
    this->gravity(true);
}