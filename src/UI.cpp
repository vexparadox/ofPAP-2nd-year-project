//
//  UI.cpp
//  LabOF1
//
//  Created by William Meaton on 17/10/2015.
//
//

#include "UI.hpp"


UI::UI(ofPoint position, ofPoint size, std::string value, float r, float g, float b, float a):position(position), size(size), r(r), g(g), b(b), a(a){
    rect = ofRectangle(position, size.x, size.y);
}

void UI::display(){
    ofSetColor(r, g, b, a);
    ofDrawRectangle(rect);
    ofSetColor(255, 255, 255);
    ofDrawBitmapString(value, position.x+size.x/2,position.y+size.y/2);
}

bool UI::isClicked(int mousex, int mousey){
    return rect.inside(mousex, mousey);
}

void UI::setWidth(float w){
    rect.setWidth(w);
}