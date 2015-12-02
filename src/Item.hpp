//
//  Item.hpp
//  LabOF1
//
//  Created by William Meaton on 01/12/2015.
//
//

#ifndef Item_hpp
#define Item_hpp

#include <stdio.h>
#include "Entity.hpp"
#include "Player.hpp"

class Item : public Entity{
public:
    Item(ofPoint position, bool visible);
    virtual void itemAction(Player &p){};
    virtual ~Item(){};
    virtual void display(){};
    virtual void update(){};
};
#endif /* Item_hpp */
