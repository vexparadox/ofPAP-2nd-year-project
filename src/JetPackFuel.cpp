//
//  JetPackFuel.cpp
//  LabOF1
//
//  Created by William Meaton on 03/12/2015.
//
//

#include "JetPackFuel.hpp"

JetPackFuel::JetPackFuel(ofPoint position, bool visible, float ability) : Item(position, visible), ability(ability){
    
}

bool JetPackFuel::itemAction(Player &p){
    p.addJetPackMax(ability);
}

void JetPackFuel::display(){
    if(visible){
        Texture::getSprite(item_JETPACK).draw(position);
    }
}

void JetPackFuel::update(){
    this->gravity(true);
}