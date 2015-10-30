//
//  UI.cpp
//  LabOF1
//
//  Created by William Meaton on 17/10/2015.
//
//

#include "UI.hpp"


UI::UI(int x, int y, int width, int height, std::string value):x(x), y(y), width(width), height(height), value(value){
    ofRectangle rect = ofRectangle(x, y, width, height);
}

void UI::display(){
    ofColor(255, 0, 0);
    ofDrawRectangle(rect);
    std::cout << "lol";
}

bool UI::isClicked(int mousex, int mousey){
}

void UI::setX(int x){
    rect.setX(x);
}

void UI::setY(int y){
    rect.setY(y);
}