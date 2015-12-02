//
//  StimPack.hpp
//  LabOF1
//
//  Created by William Meaton on 01/12/2015.
//
//

#ifndef StimPack_hpp
#define StimPack_hpp

#include <stdio.h>
#include "Item.hpp"
#include "Player.hpp"

class StimPack : public Item{
    float ability;
public:
    StimPack(ofPoint position, bool visible, float ability);
    ~StimPack(){};
    void display();
    void itemAction(Player &p);
    void update();
};
#endif /* StimPack_hpp */
