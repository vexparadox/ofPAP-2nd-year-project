#pragma once

#include "ofMain.h"
#include "Keyboard.hpp"
#include "Texture.hpp"
#include "World.hpp"
#include "MenuState.hpp"

//PLEASE NOTE, YOU WILL GET ERRORS!
//getting errors on loading files or issues with bad Access with tiles is because I cannot get OF to find my text files, I've tried for hours and no luck
//In the World.cpp there is a path defined, please change that to the path of this current project

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
