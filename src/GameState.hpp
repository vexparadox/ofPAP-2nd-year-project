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
#include "State.hpp"

class GameState : public State{
public:
    virtual void tick();
    virtual void render();
};

#endif /* GameState_hpp */
