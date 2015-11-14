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
    std::cout << "loadWorld";
    std::string line;
    std::ifstream infile("test.txt");
    infile.open("test.txt");
    if(infile.is_open()){
        std::cout << "File is opened";
    }
    for( std::string line; getline(infile, line ); )
    {
        int temp;
        infile >> temp;
        std::cout << temp;
    }

}