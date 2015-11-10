//
//  Player.hpp
//  LabOF1
//
//  Created by William Meaton on 09/11/2015.
//
//

#ifndef Player_hpp
#define Player_hpp

#include <stdio.h>
#include "Creature.hpp"
#include "Keyboard.hpp"

class Player : public Creature{
public:
    Player(int x, int y, int movementSpeed, int health, bool visible, std::string imgPath);
    void move();
};

#endif /* Player_hpp */
