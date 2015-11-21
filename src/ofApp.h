#pragma once

#include "ofMain.h"
#include "Keyboard.hpp"
#include "GameState.hpp"
#include "Texture.hpp"

#include "MenuState.hpp"



//the aim of this project is to make a fluid-movement grid based survival game with multiple weapons, items, enemies and survival aspects.

//So far I have made the base of a game but little is being displayed.
//TODO
/*
 -Get the World to make tiles and display them
 -Add more enmies to the game
 -Add transform movement - player is central with the map around them
 -Add colliders in the collider class
 -Add actual gameplay
 -Normalise the movement of the bullets/enemies
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
        //two instances of the current states
        GameState gameState;
        MenuState menuState;
};
