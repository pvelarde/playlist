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

Playlist::Playlist(string playlist_id, string str_of_songs,int popularity){
    stringstream lineStream(str_of_songs);
    string song_id;
    while (lineStream >> song_id)
        this->my_songs.push_back(song_id);
    
    this->popularity = popularity;
    this->my_id = playlist_id;
}

Playlist::~Playlist(){
    
}

string Playlist::getId(){
    return this->my_id;
}

int Playlist::getPopularity(){
    return this->popularity;
}