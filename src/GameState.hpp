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

class GameState : public State{
public:
    GameState();
    vector<BasicZombie> basicE;
    Player player = *new Player(2, 2, 0.5, 200, true, "player.jpg");
    void render();
    void tick();
    
};

#endif /* GameState_hpp */
