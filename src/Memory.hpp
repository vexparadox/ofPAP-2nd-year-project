//
//  Memory.hpp
//  LabOF1
//
//  Created by William Meaton on 02/12/2015.
//
//

#ifndef Memory_hpp
#define Memory_hpp

#include <stdio.h>
#include <vector>
//this class is used to delete all pointers and the data they point to in a vector
//it uses a template so I don't have to write the method out 10+ times
template<typename T>
class Memory{
public:
    //it's static so no need for Memory to be instatniated
    static void vectorClear(T &v){
        //it will take in a reference to a vector no matter it's type
        for (auto it = v.begin(); it != v.end(); ++it){
            //loop through and delete the data stored at the address
            delete *it;
        }
        //now clear the vector, although this doesn't technically clear memory for re-allocation
        //it can be used as such
        v.clear();
    }
    
    static void iteratorClear(T* p){
        delete *p;
    }
};
#endif /* Memory_hpp */