//
//  JetPackFuel.hpp
//  LabOF1
//
//  Created by William Meaton on 03/12/2015.
//
//

#ifndef JetPackFuel_hpp
#define JetPackFuel_hpp

#include <stdio.h>
#include "Item.hpp"

class JetPackFuel : Item{
    JetPackFuel(ofPoint position, bool visible);
    bool itemAction(Player &p);
    void display();
    void update();
};
#endif /* JetPackFuel_hpp */
