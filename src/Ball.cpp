//
//  Ball.cpp
//  LabOF1
//
//  Created by William Meaton on 13/10/2015.
//
//
#include "Ball.hpp"

Ball::Ball(int _x, int _y): x(_x), y(_y){// Set the initial color
    color.set( ofRandom(255), ofRandom(255), ofRandom(255));
}

void Ball::moveTo(){
    
}

void Ball::draw(){
    ofSetColor(color);
    ofFill();
    ofDrawCircle(x, y, 30);
}