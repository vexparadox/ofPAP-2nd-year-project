#include "ofApp.h"


void ofApp::setup(){
    // Fixed framerate
    ofSetFrameRate(30);
    // No need to define the initial position of the ball
    // because the Ball constructor does it for yo
    zombies.push_back(BasicZombie(0,0,10,100,true, "img.jpg"));
    
}

void ofApp::update(){

    
}

void ofApp::draw(){
    ofBackground(255);
    for(auto zombie : zombies){
        auto z = &zombie;
        z.display();
    }
    
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
