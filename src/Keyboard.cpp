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
            //LEFT ARROW
        case 356:
            LEFT = true;
            break;
            //LETTER A
        case 97:
            LEFT = true;
            break;
            //UP ARROW
        case 357:
            UP = true;
            break;
            //LETTER W
        case 119:
            UP = true;
            break;
            //RIGHT ARROW
        case 358:
            RIGHT = true;
            break;
            //LETTER D
        case 100:
            RIGHT = true;
            break;
            //DOWN ARROR
        case 359:
            DOWN = true;
            break;
            //LETTER S
        case 115:
            DOWN = true;
            break;
            //SPACE BAR
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
            //LETTER S
        case 115:
            DOWN = false;
            break;
            //LETTER D
        case 100:
            RIGHT = false;
            break;
            //LETTER W
        case 119:
            UP = false;
            break;
            //LETTER A
        case 97:
            LEFT = false;
            break;
    }
}
bool Keyboard::getSPACE(){
    return SPACE;
}

bool Keyboard::getUP(){
    return UP;
}

bool Keyboard::getMOUSE1(){
    return ofGetMousePressed();
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