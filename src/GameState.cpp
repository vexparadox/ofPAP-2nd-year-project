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
    worldIsLoaded = false;
    //reset pointer vectors using templated memory clear
    Memory< vector<Item*> >::vectorClear(items);
    Memory< vector<Enemy*> >::vectorClear(enemies);
    Memory< vector<Bullet*> >::vectorClear(bullets);
    
    //reset gameScore
    gameScore = 0;
    
    //reset player
    player.setJetPackMax(20);
    player.setDoubleDamageShot(0);
    player.position = ofPoint(ofGetWidth()/2, 2);
    player.setHealth(200);
    
    currentEnemies = 0;
    
    this->spawnEnemies();
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

    for(auto b : bullets){
        b->display();
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
    //call player actionss
    player.action();
    
    //this will create a random item drop at a set rate
    this->rndItemDrop();
    
    //replace dead enemies
    this->spawnEnemies();
    
    //call the update on items
    for(auto it = items.begin(); it != items.end(); it++){
        auto i = *it;
        i->update();
        if(i->entityCollide(player)){
            //boolean in case there's one which cannot be done for some reason
            if(i->itemAction(player)){
             //remove the item from array
                delete i;
                items.erase(it);
                //delete the item and erase it from the list
                //we can break here because there's rarely going to be more than
                //one object in Item, a skipped update will be okay
                break;
            }
        }
    }
    
    //call the moveTo on enemies
    for(auto e : enemies){
        e->moveTo(player.position);
    }
    
    //enemy collision with the player
    for(auto &e : enemies){
        if(e->entityCollide(player)){
            player.takeDamage(e->getAttackDamage());
        }
    }

    //make the bullets update
    for(auto itB = bullets.begin(); itB != bullets.end();){
        auto b = *itB;
        bool isBulletDelete = false;
        b->update();
        float damage = b->getDamage();
        //loop through enemies for bullet collision
        for(auto itE = enemies.begin(); itE != enemies.end();){
            auto e = *itE;
            bool isEnemyDelete = false;
            //if there's a collision, take damage and set bullets to invisible
            if(e->entityCollide(*b)){
                e->takeDamage(damage);
                gameScore += damage;
                //if the enemy is now sdead
                //delete the data stored at e
                //and remove the object sorted at point itE
                if(e->isDead()){
                    delete *itE;
                    enemies.erase(itE);
                    //lower enemy count
                    currentEnemies--;
                    //then tell the loop not to iterate
                    //this stops nasty mid-delete-loop errors
                    isEnemyDelete = true;
                }
                b->setVisible(false);
                delete *itB;
                bullets.erase(itB);
                isBulletDelete = true;
                //you need to bareak here otherwise further enemies will be compared against an already deleted bullet
                break;
            }
            //only iterate if one wasn't deleted
            if(!isEnemyDelete){
                itE++;
            }
        }
        if(!isBulletDelete){
            itB++;
        }
    }
    //seperate loop for world collide because otherwise deletion mid loop gets confusing
    //delete bullets offscreen
    for(auto itB = bullets.begin(); itB != bullets.end();){
        auto b = *itB;
        bool isBulletDelete = false;
        //check the collision with the world
        if(b->bulletWorldCollide() || !b->onScreen()){
            b->setVisible(false);
            delete *itB;
            bullets.erase(itB);
            isBulletDelete = true;
        }
        if(!isBulletDelete){
            itB++;
        }
    }
    
    //set the UI to the new jetPackFuel
    if(player.getJetPackCurrent() < 0){
        jetFuelUI.setWidth(0);
    }else{
        jetFuelUI.setWidth(player.getJetPackCurrent()*20);
    }
    healthUI.setWidth(player.getHealth()*2);
}


void GameState::push_basicEnemy(){
    enemies.push_back(new BasicZombie(ofPoint(ofRandom(0, ofGetWidth()), ofRandom(0,ofGetHeight()/3)), 3, 100, true, 5));
}

void GameState::push_bigEnemy(){
    enemies.push_back(new BigZombie(ofPoint(ofRandom(0, ofGetWidth()), ofRandom(0,ofGetHeight()/3)), 1, 200, true, 10));
}

void GameState::rndItemDrop(){
    int rndItem = (int)ofRandom(0, 500);
    //case of 1 in 500
    //spawn a random item
    switch(rndItem){
        case 50:
            items.push_back(new StimPack(ofPoint(ofRandom(0, ofGetWidth()), 0), true, 20));
            break;
        case 56:
            items.push_back(new DoubleDamage(ofPoint(ofRandom(0, ofGetWidth()), 0), true));
            break;
        case 60:
            items.push_back(new JetPackFuel(ofPoint(ofRandom(0, ofGetWidth()), 0), true, 5));
            break;
    }
}

void GameState::spawnEnemies(){
    //push back into the enemies array
    while(currentEnemies < maxEnemies){
        int random = (int)ofRandom(0, maxEnemies);
        if(random > 3){
            this->push_basicEnemy();
        }else{
            this->push_bigEnemy();
        }
        currentEnemies++;
    }
}