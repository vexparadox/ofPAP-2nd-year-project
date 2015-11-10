#pragma once

#include "ofMain.h"
#include "Ball.hpp"
#include "UI.hpp"
#include "BasicZombie.hpp"
#include "Keyboard.hpp"
#include "Player.hpp"
#include "GameState.hpp"



using std::vector;

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		void keyPressed(int key);
		void keyReleased(int key);
    
        GameState gameState;
};
