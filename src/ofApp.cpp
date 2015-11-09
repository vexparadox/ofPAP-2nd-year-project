#include "ofApp.h"


void ofApp::setup(){
    //create basic zombies
    int maxBasic = 10;
    for(int i =0; i < maxBasic; i++){
        basicE.push_back(BasicZombie(0, 0, 10, 100, true, "img.jpg"));
    }
}

void ofApp::update(){
    for(auto &e : basicE){
        auto it = e;
        it.moveTo(ofGetMouseX(), ofGetMouseY());
    }

}

void ofApp::draw(){
    for(auto e : basicE){
        //display the enemies
        e.display();
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

//---ß-----------------------------------------------------------
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
