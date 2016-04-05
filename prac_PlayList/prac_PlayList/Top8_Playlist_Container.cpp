//
//  Top8_Playlist_Container.cpp
//  prac_PlayList
//
//  Created by Nick Maresco on 4/5/16.
//  Copyright © 2016 ___Marss___. All rights reserved.
//

#include "Top8_Playlist_Container.h"

// Public

Top8_Playlist_Container::Top8_Playlist_Container(){

}

Top8_Playlist_Container::~Top8_Playlist_Container(){
    
}

bool Top8_Playlist_Container::add(string _id){
    bool result;
    
    
    return result;
}

bool Top8_Playlist_Container::erase(string _id){
    bool result = false;
    
    for(int ii = 0; ii < this->top8_backend.size(); ii++){
        if(this->top8_backend.at(ii) == _id){
            this->top8_backend.erase(this->top8_backend.begin() + ii);
        }
        
    }
    
    return result;
}

bool Top8_Playlist_Container::erase_least_popular(){
    bool result = false;
    // find and delete the least popular playlist from this->top8_backend
    
    return result;
}

void Top8_Playlist_Container::sort(){
    
    // sort the playlists in this->top8_backend by id using the pl_c
    
    
    
    
    
}
