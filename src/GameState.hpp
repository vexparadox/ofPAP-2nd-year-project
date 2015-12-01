//
//  GameState.hpp
//  LabOF1
//
//  Created by William Meaton on 04/11/2015.
//
//

#ifndef GameState_hpp
#define GameState_hpp

#include <stdio.h>
#include <vector>
#include "State.hpp"
#include "BasicZombie.hpp"
#include "BigZombie.hpp"
#include "Player.hpp"
#include "StandardBullet.hpp"
#include "World.hpp"
#include "UI.hpp"

//the gamestate is the state that is run when the gmae is running
//here the render and tick fucntions hold the data of the game
class GameState : public State{
private:
    int maxBasic = 10;
    int maxBig = 2;
    int gameScore = 0;
    bool worldIsLoaded = false;
    bool worldNeedUpdate = false;
public:
    GameState();
    vector<BasicZombie> basicE;
    vector<BigZombie> bigE;
    vector<StandardBullet> stdBullet;
    //THE PLAYER OBJECT uses movement speed in a different way
    Player player = Player(ofPoint(0,0), 10, 200, true, stdBullet);
    
    UI jetFuelUI = UI(ofPoint(20, 20), ofPoint(0, 25), "Fuel", 255, 0, 0, 200);
    UI healthUI = UI(ofPoint(20, 50), ofPoint(0, 25), "Health", 0, 255, 0, 200);
    
    void render();
    void reset();
    void tick();
    void push_basicEnemy();
    void push_bigEnemy();
    
};

#endif /* GameState_hpp */
