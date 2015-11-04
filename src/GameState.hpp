//
//  GameState.hpp
//  LabOF1
//
//  Created by William Meaton on 04/11/2015.
//
//

#ifndef GameState_hpp
#define GameState_hpp

#include <stdio.h>
#include <vector>
#include "State.hpp"
#include "BasicZombie.hpp"

class GameState : public State{
public:
    GameState();
    void tick();
    void render();
    vector<BasicZombie> basicE;
};

#endif /* GameState_hpp */
