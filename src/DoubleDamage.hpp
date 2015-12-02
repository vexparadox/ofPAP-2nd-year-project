//
//  DoubleDamage.hpp
//  LabOF1
//
//  Created by William Meaton on 02/12/2015.
//
//

#ifndef DoubleDamage_hpp
#define DoubleDamage_hpp

#include <stdio.h>
#include "Item.hpp"
#include "Player.hpp"

class DoubleDamage : public Item{
public:
    DoubleDamage(ofPoint position, bool visible);
    ~DoubleDamage(){};
    void display();
    bool itemAction(Player &p);
    void update();
};
#endif /* DoubleDamage_hpp */
