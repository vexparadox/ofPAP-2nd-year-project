#include "ofApp.h"


void ofApp::setup(){
    // Fixed framerate
    ofSetFrameRate(30);
    // No need to define the initial position of the ball
    // because the Ball constructor does it for yo
    for(int i = 0; i < 10; i ++){
        zombies.push_back(BasicZombie((int)ofRandom(0, ofGetWidth()),(int)ofRandom(0, ofGetHeight()),10,100,true, "img.jpg"));
    }
    State().setState(mainGame);
    
}

void ofApp::update(){
    State().getState().tick();
}

void ofApp::draw(){
    State().getState().render();
}
//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
