//
//  Keyboard.hpp
//  LabOF1
//
//  Created by William Meaton on 09/11/2015.
//
//

#ifndef Keyboard_hpp
#define Keyboard_hpp

#include <stdio.h>

//this class handles keyboard input with predefined buttons

class Keyboard{
public:
    Keyboard();
    static bool UP, LEFT, RIGHT, DOWN, AnyPRESSED, SPACE;
    static void keyUp(int key);
    static void keyDown(int key);
    static bool getUP();
    static bool getLEFT();
    static bool getRIGHT();
    static bool getDOWN();
    static bool getAnyPRESSED();
    static bool getSPACE();
};


#endif /* Keyboard_hpp */
