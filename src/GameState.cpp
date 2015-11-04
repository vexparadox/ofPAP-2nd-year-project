//
//  GameState.cpp
//  LabOF1
//
//  Created by William Meaton on 04/11/2015.
//
//

#include "GameState.hpp"


GameState::GameState(){
    //create basic zombies
    int maxBasic = 10;
    for(int i =0; i < maxBasic; i++){
        basicE.push_back(BasicZombie(0, 0, 10, 100, true, "img.jpg"));
    }
}

void GameState::render(){
    //visibility is handled by the Entitiy controller
    for(auto e : basicE){
        //display the enemies
        e.display();
    }
}

void GameState::tick(){
    for(auto &e : basicE){
        auto it = e;
        it.moveTo(ofGetMouseX(), ofGetMouseY());
    }
}
