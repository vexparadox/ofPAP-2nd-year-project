#pragma once

#include "ofMain.h"
#include "Ball.hpp"
#include <vector>
#include "UI.hpp"
#include "BasicZombie.hpp"
#include "GameState.hpp"
#include "MenuState.hpp"

using std::vector;

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
        int state = 1;
        vector<BasicZombie> zombies;
        GameState mainGame;
        MenuState mainMenu;
};
