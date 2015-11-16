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


//load the txt file and make the world vector
void World::loadWorld(){
    std::ifstream textfile ("/Users/williammeaton/Desktop/openFrameworks/apps/myApps/Project/bin/data/test.txt", std::ios::in); //declare a file stream
    if (textfile.is_open()) //checks if the file is open??
    {
        string str; //declare a string for storage
        xSize = str.length();
        while (getline(textfile, str)){ //get a line from the file, put in the string
            //loop through and push all the ints to a vector
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
            ySize++;
        }
    }
    World::updateWorldImg();
}
//get a new version of worldImg
void World::updateWorldImg(){
    for(int i = 0; i < xSize; i++){
        for(int j = 0; j < ySize; j++){
            Sprite::getTexture(worldMatrix[i*xSize + j]).draw(j*SPRITE_SIZE, i*SPRITE_SIZE);
        }
    }
    worldImg.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
}

//display the worldImg
void World::display(){
    ofPushMatrix();
    ofRotate(180);
    ofTranslate(-ofGetWidth(), -ofGetHeight());
    World::worldImg.draw(0, 0);
    ofPopMatrix();

}