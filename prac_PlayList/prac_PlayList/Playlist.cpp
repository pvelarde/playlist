//
//  Playlist.cpp
//  PlayList_prac
//
//  Created by Nick Maresco on 2/11/16.
//  Copyright (c) 2016 ___Marss___. All rights reserved.
//

#include "Playlist.h"

// Public

// Default Constructor
Playlist::Playlist(){
    
}

Playlist::Playlist(Playlist_Container* dp, string formatted_str){
    
    // this is an error handling case
    if(formatted_str[formatted_str.length()-1] == '\t'){
        formatted_str = "\t0";
    }
    
    this->pl_db = dp;

    stringstream stream(formatted_str);
    int pop; // short for popularity
    int nn;
    vector<int> temp;
    
    do{
        stream >> nn;
        temp.push_back(nn);
        if(!stream){
            pop = nn;
        }
    }while(stream);
    
    // the last element is actually the popularity so it shouldnt exist
    temp.pop_back();
    temp.pop_back();
    
    for(int ii = 0; ii < temp.size(); ii++){
        cout << temp.at(ii) << endl;
    }
    
    cout << "Popularity: " << pop << endl;
    
    this->my_songs = temp;
    
}

Playlist::~Playlist(){
    
}

// Private

int Playlist::generate_id(){
    int result;
    
    return result;
}
