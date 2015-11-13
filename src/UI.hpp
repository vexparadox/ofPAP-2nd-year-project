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
public:
    UI(ofPoint position, ofPoint size, std::string value);
    void display();
    bool isClicked(int mousex, int mousey);
    ofPoint position;
    ofPoint size;
    int x, y, width, height;
};

#endif /* UI_hpp */
