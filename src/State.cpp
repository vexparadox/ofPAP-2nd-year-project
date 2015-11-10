//
//  State.cpp
//  LabOF1
//
//  Created by William Meaton on 04/11/2015.
//
//

#include "State.hpp"

State State::currentState;

State State::getState(){
 return currentState;
}

void State::setState(State &state){
    currentState = state;
}

void State::render(){
    std::cout << "not working";
}

void State::tick(){
    
}