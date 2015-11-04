//
//  MenuState.hpp
//  LabOF1
//
//  Created by William Meaton on 04/11/2015.
//
//

#ifndef MenuState_hpp
#define MenuState_hpp

#include <stdio.h>
#include "State.hpp"

class MenuState{
public:
    virtual void tick();
    virtual void render();
};

#endif /* MenuState_hpp */
