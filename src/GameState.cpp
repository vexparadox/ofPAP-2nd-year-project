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
        basicE.push_back(BasicZombie(ofRandom(0, ofGetWidth()), ofRandom(0,ofGetHeight()), 0.001, 100, 5, true));
    }
}

void GameState::render(){
    for(auto e : basicE){
        //display the enemies
        e.display();
    }
    for(auto b : stdBullet){
        b.display();
    }
    player.display();
}

void GameState::tick(){
    for(auto &e : basicE){
        e.moveTo(player.position.x, player.position.y);
    }
    for(auto &b : stdBullet){
        b.update();
    }
    basicE.erase(std::remove_if(basicE.begin(), basicE.end(), [this](BasicZombie e){return !e.collide(&stdBullet);}), basicE.end());

    //check for out-of-screen bullets
    stdBullet.erase(std::remove_if(stdBullet.begin(), stdBullet.end(), [this](StandardBullet b){return !b.onScreen();}), stdBullet.end());
    player.action();
}