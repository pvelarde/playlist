//
//  Playlist_Container.cpp
//  PlayList_prac
//
//  Created by Nick Maresco on 2/11/16.
//  Copyright (c) 2016 ___Marss___. All rights reserved.
//

#include "Playlist_Container.h"
#include "Playlist.h"

// Public

Playlist_Container::Playlist_Container(){
   /* this->instance_count = 0;
    this->instance_count++;
    
    if(this->instance_count > 1){
        cout << "you have illegally made another instance of a singleton" << endl;
    }*/
}

Playlist_Container::~Playlist_Container(){
    
}

Playlist* Playlist_Container::query(string _id){
    Playlist* result = NULL;
    
    return result;
}

bool Playlist_Container::add(Playlist* new_pl){
    bool result;
    
    return result;
}

bool Playlist_Container::erase(string _id){
    bool result = false;
    
    
    return result;
}