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
    for(int i =0; i < maxBasic; i++){
        basicE.push_back(BasicZombie(ofRandom(0, ofGetWidth()), ofRandom(0,ofGetHeight()/3), 3, 100, 5, true));
    }
}

void GameState::render(){
    if(!worldIsLoaded){
        World::loadWorld();
        worldIsLoaded = true;
    }
    World::display();
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
    if(basicE.size() < maxBasic){
        for(int i=0; i < (maxBasic-basicE.size());i++){
            basicE.push_back(BasicZombie(ofRandom(0, ofGetWidth()), ofRandom(0,ofGetHeight()/3), 3, 100, 5, true));
        }
    }
    
    //dont do anything until the world is loaded dammit
    if(!worldIsLoaded){
        return;
    }
    //create the world if not done already
    //it has to be called here because of constructors and things
    for(auto &e : basicE){
        e.moveTo(player.position.x, player.position.y);
    }
    //make the bullets update
    for(auto &b : stdBullet){
        //loop through enemies for bullet collision
        for(auto &e : basicE){
            //if there's a collision, take damage and set bullets to invisible
            if(e.entityCollide(b)){
                e.takeDamage(b.getDamage());
                b.setVisible(false);
            }
        }
        //erase enemies if they're dead
        basicE.erase(std::remove_if(basicE.begin(), basicE.end(), [this](BasicZombie e){return e.isDead();}), basicE.end());
        b.update();
    }
    //erase for out-of-screen bullets
    stdBullet.erase(std::remove_if(stdBullet.begin(), stdBullet.end(), [this](StandardBullet b){return !b.onScreen();}), stdBullet.end());
    
    //erase for non-visible bullets
    stdBullet.erase(std::remove_if(stdBullet.begin(), stdBullet.end(), [this](StandardBullet b){return !b.isVisible();}), stdBullet.end());
    //call player actions
    player.action();
}

