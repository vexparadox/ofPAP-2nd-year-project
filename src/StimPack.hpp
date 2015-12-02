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
public:
    StimPack(ofPoint position, bool visible);
    ~StimPack(){};
    void display();
    void itemAction(Player &p);
};
#endif /* StimPack_hpp */
