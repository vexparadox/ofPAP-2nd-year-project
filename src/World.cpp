//
//  World.cpp
//  LabOF1
//
//  Created by William Meaton on 14/11/2015.
//
//

#include "World.hpp"

World::World(std::string path, int scale): scale(scale), path(path){
    this->loadWorld();
}

void World::loadWorld(){

    std::ifstream textfile ("/Users/williammeaton/Desktop/openFrameworks/apps/myApps/Project/bin/data/test.txt", std::ios::in); //declare a file stream
    if (textfile.is_open()) //checks if the file is open??
    {
        string str; //declare a string for storage
        while (getline(textfile, str)){ //get a line from the file, put in the string
            //loop through skipping all the spaces
            int i = 0 ;
            while(i <= str.length()){
                std::cout << str[i];
                i+=2;
            }
            std::cout << std::endl;
        }
    }

}