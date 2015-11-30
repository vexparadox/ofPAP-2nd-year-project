//
//  GameState.cpp
//  LabOF1
//
//  Created by William Meaton on 04/11/2015.
//
//

#include "GameState.hpp"


GameState::GameState(){
    this->reset();
}

void GameState::reset(){
    player.position = ofPoint(2, 2);
    player.setHealth(200);
    stdBullet.clear();
    basicE.clear();
    //create basic zombies
    for(int i =0; i < maxBasic; i++){
        this->push_basicEnemy();
    }
}

void GameState::render(){
    if(!worldIsLoaded){
        World::loadWorld();
        worldIsLoaded = true;
    }
    if(worldNeedUpdate){
        World::updateWorldImg();
        worldNeedUpdate = false;
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
    jetFuelUI.display();
    healthUI.display();
}

void GameState::push_basicEnemy(){
    basicE.push_back(BasicZombie(ofRandom(0, ofGetWidth()), ofRandom(0,ofGetHeight()/3), 3, 100, 5, true));
}

void GameState::tick(){
    //dont do anything until the world is loaded dammit
    if(!worldIsLoaded){
        return;
    }
    if(player.getHealth() < 0){
        this->reset();
        return;
    }
    //remove filly degraded tiles to air
    for(auto &w : World::worldMatrix){
        if(w.getDamageLevel() >=10){
            w = World::tiles[0];
            //set world to be updated
            worldNeedUpdate = true;
        }
    }
    
    
    if(basicE.size() < maxBasic){
        for(int i=0; i < (maxBasic-basicE.size());i++){
            this->push_basicEnemy();
        }
    }

    //create the world if not done already
    //it has to be called here because of constructors and things
    for(auto &e : basicE){
        e.moveTo(player.position.x, player.position.y);
        if(e.entityCollide(player)){
            player.takeDamage(e.attackDamage);
        }
    }
    //make the bullets update
    for(auto &b : stdBullet){
        if(b.bulletWorldCollide()){
            b.setVisible(false);
        }
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
    //set the UI to the new jetPackFuel
    if(player.jetPackFuel < 0){
        jetFuelUI.setWidth(0);
    }else{
        jetFuelUI.setWidth(player.jetPackFuel*20);
    }
    healthUI.setWidth(player.getHealth()*2);
    
}

