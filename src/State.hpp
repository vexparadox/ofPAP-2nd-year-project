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
//a state is what tick and render loops will currently be used
//it's an abstract class and uses pointers to achieve it's goal
class State{
private:
    static State* currentState;
public:
    static State* getState();
    static void setState(State &state);
    virtual void render() = 0;
    virtual void tick() = 0;
};

#endif /* State_hpp */
