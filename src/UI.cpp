//
//  UI.cpp
//  LabOF1
//
//  Created by William Meaton on 17/10/2015.
//
//

#include "UI.hpp"


UI::UI(ofPoint position, ofPoint size, std::string value):position(position), size(size){

    rect = ofRectangle(position, size.x, size.y);
    
}

void UI::display(){
    ofColor(255, 0, 0);
    ofDrawRectangle(rect);
}

bool UI::isClicked(int mousex, int mousey){
    return rect.inside(mousex, mousey);
}