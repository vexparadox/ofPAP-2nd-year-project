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
class Item : public Entity{
public:
    Item(ofPoint position, bool visible);
    virtual void itemAction();
    virtual void display();
};
#endif /* Item_hpp */
