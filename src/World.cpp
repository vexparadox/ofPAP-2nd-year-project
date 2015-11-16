//
//  World.cpp
//  LabOF1
//
//  Created by William Meaton on 14/11/2015.
//
//

#include "World.hpp"

World::World(std::string path, int xSize, int ySize): xSize(xSize), ySize(ySize), path(path){
    this->loadWorld();
}

void World::loadWorld(){
    std::ifstream textfile ("/Users/williammeaton/Desktop/openFrameworks/apps/myApps/Project/bin/data/test.txt", std::ios::in); //declare a file stream
    if (textfile.is_open()) //checks if the file is open??
    {
        string str; //declare a string for storage
        while (getline(textfile, str)){ //get a line from the file, put in the string
            
            //loop through skipping all the spaces
            //i holds the place in the line that's being parsed
            int i = 0;
            vector<int> tempRow;
            while(i <= str.length()){
                //convert the string into an int
                int tempInt = boost::lexical_cast<int>(str[i]);
                //push into a temp row
                tempRow.push_back(tempInt);
                //incrememnt through the line
                i+=2;
            }
            //push the row into the world matrix
            worldMatrix.push_back(tempRow);
            std::cout << std::endl;
        }
    }
    
}