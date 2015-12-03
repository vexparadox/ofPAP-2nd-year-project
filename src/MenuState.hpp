//
//  MenuState.hpp
//  LabOF1
//
//  Created by William Meaton on 04/11/2015.
//
//

#ifndef MenuState_hpp
#define MenuState_hpp

#include <stdio.h>
#include "State.hpp"
#include "Keyboard.hpp"
#include "UI.hpp"

#include "GameState.hpp"
 //this class is what is called when the program is in menu state 
class MenuState : public State{
public:
    void tick();
    void render();
    void mouse1Pressed();
    GameState gameState;
    int tempWidth = 300;
    int tempHeight = 200;
    UI playBtn = UI(ofPoint((ofGetWidth()/2)-tempWidth/2, (ofGetHeight()/2)-tempHeight/2), ofPoint(tempWidth, tempHeight), "Play", 100, 100, 100, 240);
};

#endif /* MenuState_hpp */
