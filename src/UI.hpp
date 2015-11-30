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
    ofPoint colour;
public:
    UI(ofPoint position, ofPoint size, std::string value, ofPoint colour);
    void display();
    bool isClicked(int mousex, int mousey);
    void setWidth(float w);
    ofPoint position;
    ofPoint size;
};

#endif /* UI_hpp */
