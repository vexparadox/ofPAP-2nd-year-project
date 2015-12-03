//
//  JetPackFuel.cpp
//  LabOF1
//
//  Created by William Meaton on 03/12/2015.
//
//

#include "JetPackFuel.hpp"

JetPackFuel::JetPackFuel(ofPoint position, bool visible) : Item(position, visible){
    
}

bool JetPackFuel::itemAction(Player &p){
    p.setDoubleDamage();
}

void JetPackFuel::display(){
    if(visible){
        Texture::getSprite(item_DD).draw(position);
    }
}

void JetPackFuel::update(){
    this->gravity(true);
}