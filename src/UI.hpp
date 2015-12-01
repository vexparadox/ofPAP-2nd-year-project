//
//  UI.hpp
//  LabOF1
//
//  Created by William Meaton on 17/10/2015.
//
//

#ifndef UI_hpp
#define UI_hpp

#include "ofMain.h"
#include <stdio.h>

class UI{
private:
    std::string value;
    ofRectangle rect;
    float r, g, b, a;
public:
    UI(ofPoint position, ofPoint size, std::string value, float r, float g, float b, float a);
    void display();
    bool isClicked(int mousex, int mousey);
    void setWidth(float w);
    ofPoint position;
    ofPoint size;
};

#endif /* UI_hpp */
