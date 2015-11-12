#pragma once

#include "ofMain.h"
#include "Keyboard.hpp"
#include "GameState.hpp"
#include "Sprite.hpp"

#include "MenuState.hpp"



using std::vector;

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		void keyPressed(int key);
		void keyReleased(int key);
    
        GameState gameState;
        MenuState menuState;
};
