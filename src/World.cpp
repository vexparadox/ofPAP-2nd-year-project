//
//  World.cpp
//  LabOF1
//
//  Created by William Meaton on 14/11/2015.
//
//

#include "World.hpp"

vector<Tile> World::worldMatrix;
vector<Tile> World::tiles;
ofImage World::worldImg;
int World::xSize = 0;
int World::ySize = 0;
std::string World::path = "/Users/williammeaton/Desktop/openFrameworks/apps/myApps/PAPProject/bin/data/";


int World::getxSize(){
    return xSize;
}

int World::getySize(){
    return ySize;
}

void World::loadTiles(){
    std::ifstream textfile(path+"tiles.txt", std::ios::in); //declare a file stream
    if(textfile.is_open())
    {
        string str;
        int counter = 0;
        while (getline(textfile, str)){
            bool tempSolid;
            int solidInt, healthInt;
            // cast to int
            try{
                string temp1 = str.substr(0, 1);
                solidInt = boost::lexical_cast<int>(temp1);
                //get the health it's been given
                string temp2 = str.substr(2, 2);
                healthInt = boost::lexical_cast<int>(temp2);
            }
            catch(boost::bad_lexical_cast const& e)
            {
                std::cout << "Error on " << str[0] << e.what() << "\n";
            }
            //if the file says the tile is solid or not
            switch(solidInt){
                case 0:
                    tempSolid = false;
                    break;
                case 1:
                    tempSolid = true;
                    break;
            }
            //add a tile
            tiles.push_back(Tile(tempSolid, counter, healthInt));
            //add to the counter
            counter++;
        }
    }else{
        //if the file couldn't be loaded
        std::cout << "File could not be loaded";
    }
}

//load the txt file and make the world vector
void World::loadWorld(){
    //clear incase of reset
    worldMatrix.clear();
    xSize = 0;
    ySize = 0;
    std::ifstream textfile(path+"test.txt", std::ios::in); //declare a file stream
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
                worldMatrix.push_back(tiles[tempInt]);
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
    //clear the image to stop memory gain
    World::worldImg.clear();
    for(int i = 0; i < xSize; i++){
        for(int j = 0; j < ySize; j++){
            //get the texture number to load and draw it
            Texture::getTile(World::worldMatrix[i*xSize + j].getTextureNum()).draw(j*SPRITE_SIZE, i*SPRITE_SIZE);
        }
    }
    World::worldImg.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
}

//display the worldImg
void World::display(){
    worldImg.draw(0, 0);
}