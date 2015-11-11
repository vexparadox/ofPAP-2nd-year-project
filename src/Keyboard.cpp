//
//  Keyboard.cpp
//  LabOF1
//
//  Created by William Meaton on 09/11/2015.
//
//

#include "Keyboard.hpp"

bool Keyboard::UP;
bool Keyboard::LEFT;
bool Keyboard::DOWN;
bool Keyboard::RIGHT;
bool Keyboard::AnyPRESSED;
bool Keyboard::SPACE;

void Keyboard::keyDown(int key){
    AnyPRESSED = true;
    switch(key){
        case 356:
            LEFT = true;
            break;
        case 357:
            UP = true;
            break;
        case 358:
            RIGHT = true;
            break;
        case 359:
            DOWN = true;
            break;
        case 32:
            SPACE = true;
            break;
    }
}

void Keyboard::keyUp(int key){
    AnyPRESSED = true;
    switch(key){
        case 356:
            LEFT = false;
            break;
        case 357:
            UP = false;
            break;
        case 358:
            RIGHT = false;
            break;
        case 359:
            DOWN = false;
            break;
        case 32:
            SPACE = false;
            break;
    }
}
bool Keyboard::getSPACE(){
    return SPACE;
}

bool Keyboard::getUP(){
    return UP;
}

bool Keyboard::getDOWN(){
    return DOWN;
}

bool Keyboard::getLEFT(){
    return LEFT;
}

bool Keyboard::getRIGHT(){
    return RIGHT;
}
bool Keyboard::getAnyPRESSED(){
    return AnyPRESSED;
}