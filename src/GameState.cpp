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
    
    //reset pointer vectors using templated memory clear
    Memory< vector<Item*> >::vectorClear(items);
    Memory< vector<Enemy*> >::vectorClear(enemies);
    
    //reset gameScore
    gameScore = 0;
    
    //reset player
    player.position = ofPoint(ofGetWidth()/2, 2);
    player.setHealth(200);
    
    stdBullet.clear();
    
    currentBasic = 0;
    currentBig = 0;
    //push back into the enemies array
    while(currentBasic <= maxBasic){
        this->push_basicEnemy();
        currentBasic++;
    }
    while(currentBig <= maxBig){
        this->push_bigEnemy();
        currentBig++;
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
    
    for(auto e : enemies){
        //display the enemies
        e->display();
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
    //remove fully degraded tiles to air
    for(auto &w : World::worldMatrix){
        if(w.getDamageLevel() >= w.getHealth()){
            w = World::tiles[0];
            //set world to be redrawn next render call
            worldNeedUpdate = true;
        }
    }
    //this will create a random item drop at a set rate
    this->rndItemDrop();
    
    //call the update on items
    for(auto i : items){
        i->update();
        if(i->entityCollide(player)){
            if(i->itemAction(player)){
             //remove the item from array
            }
        }
    }
    
    //call the moveTo on enemies
    for(auto e : enemies){
        e->moveTo(player.position);
    }
    
    //enemy collision
    for(auto &e : enemies){
        if(e->entityCollide(player)){
            player.takeDamage(e->getAttackDamage());
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
        for(auto &e : enemies){
            //if there's a collision, take damage and set bullets to invisible
            if(e->entityCollide(b)){
                e->takeDamage(damage);
                gameScore += damage;
                b.setVisible(false);
            }
        }
        b.update();
    }
    
    //erase for non-visible and offscreen bullets
    stdBullet.erase(std::remove_if(stdBullet.begin(), stdBullet.end(), [this](StandardBullet b){return (!b.isVisible() || !b.onScreen());}), stdBullet.end());
    
    auto it = std::find_if (enemies.begin(), enemies.end(), [this](Enemy* e){return e->isDead();});
    if(it != enemies.end()){
        Memory<Enemy*>::iteratorClear(it.operator->());
        enemies.erase(it);
    }
    
    //call player actionss
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
    enemies.push_back(new BasicZombie(ofPoint(ofRandom(0, ofGetWidth()), ofRandom(0,ofGetHeight()/3)), 3, 100, true, 5));
}

void GameState::push_bigEnemy(){
    enemies.push_back(new BigZombie(ofPoint(ofRandom(0, ofGetWidth()), ofRandom(0,ofGetHeight()/3)), 1, 300, true, 10));
}

void GameState::rndItemDrop(){
    int rndItem = (int)ofRandom(0, 500);
    switch(rndItem){
        case 50:
            items.push_back(new StimPack(ofPoint(ofRandom(0, ofGetWidth()), 0), true, 20));
            break;
    }
}



