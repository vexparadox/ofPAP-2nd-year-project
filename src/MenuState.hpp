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
#include "Keyboard.hpp"
#include "UI.hpp"
 //this class is what is called when the program is in menu state 
class MenuState : public State{
public:
    void tick();
    void render();

};

#endif /* MenuState_hpp */
