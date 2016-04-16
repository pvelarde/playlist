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
    bool result = true;
    this->pl_backend.insert(std::pair<string,Playlist*>(new_pl->getId(),new_pl));
    return result;
}

bool Playlist_Container::erase(string _id){
    bool result = false;
    
    
    return result;
}

void Playlist_Container::print(){
    this->pl_backend; // map<string,Playlist*> pl_backend
    int ii = 0;
    for(map<string, Playlist* >::const_iterator it = pl_backend.begin();it != pl_backend.end(); ++it){
        std::cout << "counter " << ii << " id: " << it->first << "\n";
        ii++;
    }
}

