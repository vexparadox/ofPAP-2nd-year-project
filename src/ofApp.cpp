#include "ofApp.h"

void ofApp::setup(){
    //create basic zombies
    ofSetFrameRate(60);
    State::setState(gameState);
    Sprite::loadTextures(50, 50);
}

void ofApp::update(){
    State::getState()->tick();
}

void ofApp::draw(){
    State::getState()->render();
}

void ofApp::keyPressed(int key){
    Keyboard::keyDown(key);
}

void ofApp::keyReleased(int key){
    Keyboard::keyUp(key);
}