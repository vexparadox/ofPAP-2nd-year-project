#pragma once

#include "ofMain.h"
#include "Keyboard.hpp"
#include "Texture.hpp"
#include "World.hpp"
#include "MenuState.hpp"

//So far I have made the base of a game but little is being displayed.
//TODO
/*
 -Add transform movement - player is central with the map around them
 -Other things
 */

using std::vector;

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		void keyPressed(int key);
		void keyReleased(int key);
        //instance of the current state
        MenuState menuState;
};
