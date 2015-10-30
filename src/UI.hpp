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
    UI(int x, int y, int width, int height, std::string value);
    void display();
    bool isClicked(int mousex, int mousey);
    void setX(int x);
    void setY(int y);
    int x, y, width, height;
};

#endif /* UI_hpp */
