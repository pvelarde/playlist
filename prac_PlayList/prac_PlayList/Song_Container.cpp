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
    result = this->s_backend.find(_id)->second;
    return result;
}

bool Song_Container::add(Song* new_s){
    bool result;
    this->s_backend.insert(std::pair<string,Song*>(new_s->index,new_s));
    return result;
}

// return true if the element was deleted successfully
bool Song_Container::erase(string _id){
    bool result = false;
    std::map<string,Song*>::iterator it;
    it = this->s_backend.find(_id);
    // return true if successfully deleted
    if (it != this->s_backend.end()){
        this->s_backend.erase(it);
        result = true;
    }
    return result;
}


