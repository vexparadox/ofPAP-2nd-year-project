//
//  State.hpp
//  LabOF1
//
//  Created by William Meaton on 04/11/2015.
//
//

#ifndef State_hpp
#define State_hpp

#include <stdio.h>
#include "ofMain.h"

class State{
private:
    static State currentState;
public:
    static State getState();
    static void setState(State &state);
    virtual void render();
    virtual void tick();
};

#endif /* State_hpp */
