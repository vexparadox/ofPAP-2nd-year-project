#include "ofApp.h"


void ofApp::setup(){
    // Fixed framerate
    ofSetFrameRate(30);
    // No need to define the initial position of the ball
    // because the Ball constructor does it for yo
    
}

void ofApp::update(){
    u.setX(mouseX);
    u.setY(mouseY);
}

void ofApp::draw(){
    ofBackground(255);
    switch(state){
        case 1:
            u.display();
            std::cout << u.x;
            break;
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
