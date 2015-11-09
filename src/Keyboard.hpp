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
#include <vector>
#include <iostream>

class Keyboard{
private:
    Keyboard();
public:
    static bool UP, LEFT, RIGHT, DOWN;
    static void keyUp(int key);
    static void keyDown(int key);
    static bool getUP();
    static bool getLEFT();
    static bool getRIGHT();
    static bool getDOWN();
};


#endif /* Keyboard_hpp */
