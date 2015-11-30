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
#include "Player.hpp"
#include "StandardBullet.hpp"
#include "World.hpp"
#include "UI.hpp"

//the gamestate is the state that is run when the gmae is running
//here the render and tick fucntions hold the data of the game
class GameState : public State{
private:
    int maxBasic = 10;
    bool worldIsLoaded = false;
    bool worldNeedUpdate = false;
public:
    GameState();
    vector<BasicZombie> basicE;
    vector<StandardBullet> stdBullet;
    //THE PLAYER OBJECT uses movement speed in a different way
    Player player = Player(2, 2, 10, 200, true, stdBullet);
    UI jetFuelUI = UI(ofPoint(20, 20), ofPoint(0, 25), "Fuel", ofPoint(255, 0, 0));
    UI healthUI = UI(ofPoint(20, 50), ofPoint(0, 25), "Health", ofPoint(0, 255, 0));
    void render();
    void reset();
    void tick();
    void push_basicEnemy();
};

#endif /* GameState_hpp */
