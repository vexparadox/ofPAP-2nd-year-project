//
//  MenuState.cpp
//  LabOF1
//
//  Created by William Meaton on 04/11/2015.
//
//

#include "MenuState.hpp"

void MenuState::tick(){
    if(Keyboard::getMOUSE1()){
        this->mouse1Pressed();
    }
    
    
}

void MenuState::render(){
    ofBackground(255);

    playBtn.display();
}

void MenuState::mouse1Pressed(){
    if(playBtn.isClicked(ofGetMouseX(), ofGetMouseY())){
        State::setState(gameState);
    }
}