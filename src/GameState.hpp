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

//the gamestate is the state that is run when the gmae is running
//here the render and tick fucntions hold the data of the game
class GameState : public State{
public:
    GameState();
    vector<BasicZombie> basicE;
    //THE PLAYER OBJECT uses movement speed in a different way
    Player player = *new Player(2, 2, 10, 200, true, "player.jpg");
    void render();
    void tick();
    
};

#endif /* GameState_hpp */
