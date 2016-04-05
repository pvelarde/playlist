//
//  Song_Container.cpp
//  PlayList_prac
//
//  Created by Nick Maresco on 2/11/16.
//  Copyright (c) 2016 ___Marss___. All rights reserved.
//

#include "Song_Container.h"
#include "Song.h"

// Public

Song_Container::Song_Container(){
   /* this->instance_count = 0;
    this->instance_count++;
    
    if(this->instance_count > 1){
        cout << "you have illegally made another instance of a singleton" << endl;
    }*/
    
}

Song_Container::~Song_Container(){
    
}

Song* Song_Container::query(string _id){
    Song* result = NULL;
    
    return result;
}

bool Song_Container::add(Song* new_s){
    bool result;
    
    return result;
}

// return true if the element was deleted successfully
bool Song_Container::erase(string _id){
    bool result = false;
    
    
    return result;
}