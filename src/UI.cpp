//
//  UI.cpp
//  LabOF1
//
//  Created by William Meaton on 17/10/2015.
//
//

#include "UI.hpp"


UI::UI(ofPoint position, ofPoint size, std::string value, ofPoint colour):position(position), size(size), colour(colour){
    rect = ofRectangle(position, size.x, size.y);
}

void UI::display(){
    ofSetColor(colour.x, colour.y, colour.z);
    ofDrawRectangle(rect);
    //back to white for images
    ofSetColor(255, 255, 255);
}

bool UI::isClicked(int mousex, int mousey){
    return rect.inside(mousex, mousey);
}

void UI::setWidth(float w){
    rect.setWidth(w);
}