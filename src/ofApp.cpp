#include "ofApp.h"

void ofApp::setup(){
    //create basic zombies
    ofSetFrameRate(60);
    //set the current state to gameState
    State::setState(gameState);
    //this loads all the games textures at a set size of 50, 50
    //most likely to be changed when all the textures are the right size
    Sprite::loadTextures(50, 50);
}

void ofApp::update(){
    //this uses Sprite to call the tick() method of the currentState
    State::getState()->tick();
}

void ofApp::draw(){
    //this uses Sprite to call the render() method of the currentState
    State::getState()->render();
}

void ofApp::keyPressed(int key){
    //this passes the key that's been pressed to the keyboard handler
    Keyboard::keyDown(key);
}

void ofApp::keyReleased(int key){
    //this passes the key that's been released to the keyboard handler
    Keyboard::keyUp(key);
}