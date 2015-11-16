//
//  World.cpp
//  LabOF1
//
//  Created by William Meaton on 14/11/2015.
//
//

#include "World.hpp"

vector<int> World::worldMatrix;
ofImage World::worldImg;
int World::xSize;
int World::ySize;

World::World(std::string path, int xSize, int ySize):path(path){
    this->xSize = xSize;
    this->ySize = ySize;
}

void World::loadWorld(){
    std::ifstream textfile ("/Users/williammeaton/Desktop/openFrameworks/apps/myApps/Project/bin/data/test.txt", std::ios::in); //declare a file stream
    if (textfile.is_open()) //checks if the file is open??
    {
        string str; //declare a string for storage
        while (getline(textfile, str)){ //get a line from the file, put in the string

            for(int i = 0; i <= str.length(); i+=2){
                //convert the string into an int
                int tempInt;
                try{
                    tempInt = boost::lexical_cast<int>(str[i]);
                }
                catch(boost::bad_lexical_cast const& e)
                {
                    std::cout << "Error: " << e.what() << "\n";
                }
                worldMatrix.push_back(tempInt);
            }
        }
    }
    this -> updateWorld();
}

void World::updateWorld(){
    for(int i = 0; i < xSize; i++){
        for(int j = 0; j < ySize; j++){
            Sprite::getTexture(worldMatrix[i*xSize + j]).draw(j*SPRITE_SIZE, i*SPRITE_SIZE);
        }
    }

    worldImg.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
}

void World::display(){
    ofPushMatrix();
    ofRotate(180);
    ofTranslate(-ofGetWidth(), -ofGetHeight());
    worldImg.draw(0, 0);
    ofPopMatrix();

}