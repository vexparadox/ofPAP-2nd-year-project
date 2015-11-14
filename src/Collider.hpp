//
//  Collider.hpp
//  LabOF1
//
//  Created by William Meaton on 13/11/2015.
//
//

#ifndef Collider_hpp
#define Collider_hpp

#include <stdio.h>
#include "ofMain.h"

//this class will eventually handle all collision in the game..
class Collider{
private:
    ofPoint position, size;
public:
    Collider(ofPoint position, ofPoint size);
};

#endif /* Collider_hpp */
