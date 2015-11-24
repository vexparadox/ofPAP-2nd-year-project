//
//  World.cpp
//  LabOF1
//
//  Created by William Meaton on 14/11/2015.
//
//

#include "World.hpp"

vector<int> World::worldMatrix;
vector<Tile> World::tiles;
ofImage World::worldImg;
int World::xSize = 0;
int World::ySize = 0;
int World::numFlips =0;


void World::loadTiles(){
    std::ifstream textfile("/Users/williammeaton/Desktop/openFrameworks/apps/myApps/Project/bin/data/tiles.txt", std::ios::in); //declare a file stream
    if(textfile.is_open())
    {
        string str;
        while (getline(textfile, str)){
            bool temp;
            str.resize(1);
            if(str == "0"){
                temp = false;
            }else{
                temp = true;
            }
            tiles.push_back(Tile(temp));
        }
        
    }else{
        std::cout << "File could not be loaded";
    }
}

//load the txt file and make the world vector
void World::loadWorld(){
    std::ifstream textfile("/Users/williammeaton/Desktop/openFrameworks/apps/myApps/Project/bin/data/test.txt", std::ios::in); //declare a file stream
    if (textfile.is_open()) //checks if the file is open??
    {
        string str; //declare a string for storage
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
                    std::cout << "Error on " << str[i] << e.what() << "\n";
                }
                worldMatrix.push_back(tempInt);
                xSize++;
            }
            //count how many lines there are
            ySize++;

        }
        //xSize will end up being xSize*number of lines
        //so fix that
        xSize = xSize/ySize;
    }
    else{
        std::cout << "File could not be loaded" << std::endl;
    }
    //update the world
    World::updateWorldImg();
}
//get a new version of worldImg
void World::updateWorldImg(){
    numFlips++;
    for(int i = 0; i < xSize; i++){
        for(int j = 0; j < ySize; j++){
            Texture::getTile(World::worldMatrix[i*xSize + j]).draw(j*SPRITE_SIZE, i*SPRITE_SIZE);
        }
    }
    World::worldImg.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
}

//display the worldImg
void World::display(){
    worldImg.draw(0, 0);
}