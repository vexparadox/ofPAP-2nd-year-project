//
//  State.cpp
//  LabOF1
//
//  Created by William Meaton on 04/11/2015.
//
//

#include "State.hpp"
//this holds a pointer to the current state the program is in
State* State::currentState = nullptr;


//this returns the pointer to the current state the program is in
//you can use it like Sprite::getState()->method
State* State::getState(){
 return currentState;
}

//this takes a reference of a new state that the program will be in
void State::setState(State &state){
    currentState = &state;
}