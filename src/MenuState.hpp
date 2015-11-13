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
#include "UI.hpp"

class MenuState : public State{
public:
    void tick();
    void render();
    UI ui = UI(ofPoint(0, 0), ofPoint(50,50), "Hello");

};

#endif /* MenuState_hpp */
