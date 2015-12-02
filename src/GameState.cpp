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
    
    Memory< vector<Item*> >::vectorClear(items);
    //lol
    items.push_back(new StimPack(ofPoint(ofRandom(0, ofGetWidth()), 0), true));
    gameScore = 0;
    player.position = ofPoint(ofGetWidth()/2, 2);
    player.setHealth(200);
    stdBullet.clear();
    basicE.clear();
    //create basic zombies
    for(int i =0; i < maxBasic; i++){
        this->push_basicEnemy();
    }
    for(int i =0; i < maxBig; i++){
        this->push_bigEnemy();
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
    
    //Do any rendering under HERE!
    ofSetColor(0, 0, 0);
    ofDrawBitmapString("Score: "+std::to_string(gameScore), ofGetWidth()-100,20);
    ofSetColor(255, 255, 255);
    
    for(auto e : basicE){
        //display the enemies
        e.display();
    }
    for(auto e : bigE){
        //display the enemies
        e.display();
    }

    for(auto b : stdBullet){
        b.display();
    }
    
    for(auto i : items){
        i->display();
    }
    player.display();
    jetFuelUI.display();
    healthUI.display();
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
        if(w.getDamageLevel() >= w.getHealth()){
            w = World::tiles[0];
            //set world to be updated
            worldNeedUpdate = true;
        }
    }
    int rndItem = (int)ofRandom(0, 40);
    switch(rndItem){
        case 10:
          //
        break;
            
    }
    
    //respawn all dead BasicZombies
    if(basicE.size() < maxBasic){
        for(int i=0; i < (maxBasic-basicE.size());i++){
            this->push_basicEnemy();
        }
    }
    if(bigE.size() < maxBig){
        for(int i=0; i < (maxBig-bigE.size());i++){
            this->push_bigEnemy();
        }
    }

    for(auto &e : basicE){
        e.moveTo(player.position.x, player.position.y);
        if(e.entityCollide(player)){
            player.takeDamage(e.attackDamage);
        }
    }
    for(auto &e : bigE){
        e.moveTo(player.position.x, player.position.y);
        if(e.entityCollide(player)){
            player.takeDamage(e.attackDamage);
        }
    }

    //make the bullets update
    for(auto &b : stdBullet){
        float damage = b.getDamage();
        if(b.bulletWorldCollide()){
            gameScore += damage;
            b.setVisible(false);
        }
        //loop through enemies for bullet collision
        for(auto &e : basicE){
            //if there's a collision, take damage and set bullets to invisible
            if(e.entityCollide(b)){
                e.takeDamage(damage);
                gameScore += damage;
                b.setVisible(false);
            }
        }
        for(auto &e : bigE){
            //if there's a collision, take damage and set bullets to invisible
            if(e.entityCollide(b)){
                e.takeDamage(damage);
                gameScore += damage;
                b.setVisible(false);
            }
        }
        
        //erase enemies if they're dead
        basicE.erase(std::remove_if(basicE.begin(), basicE.end(), [this](BasicZombie e){return e.isDead();}), basicE.end());
        bigE.erase(std::remove_if(bigE.begin(), bigE.end(), [this](BigZombie e){return e.isDead();}), bigE.end());
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


void GameState::push_basicEnemy(){
    basicE.push_back(BasicZombie(ofPoint(ofRandom(0, ofGetWidth()), ofRandom(0,ofGetHeight()/3)), 3, 100, 5, true));
}

void GameState::push_bigEnemy(){
    bigE.push_back(BigZombie(ofPoint(ofRandom(0, ofGetWidth()), ofRandom(0,ofGetHeight()/3)), 1, 300, 10, true));
}




