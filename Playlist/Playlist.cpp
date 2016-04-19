//
//  Playlist.cpp
//  PlayList_prac
//
//  Created by Nick Maresco on 2/11/16.
//  Copyright (c) 2016 ___Marss___. All rights reserved.
//

#include "Playlist.h"

// Public
static const char alphanum[] =
"0123456789"
"!@#$%^&*"
"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
"abcdefghijklmnopqrstuvwxyz";

int stringLength = sizeof(alphanum) - 1;

char genRandom(){
    return alphanum[rand() % stringLength];
}

// Default Constructor
Playlist::Playlist(){
    
}

Playlist::Playlist(string playlist_id, string str_of_songs,int popularity){
    stringstream lineStream(str_of_songs);
    string song_id;
   // vector<string> temp;
    this->my_songs = new vector<string>();//temp;
    this->my_song_stream = str_of_songs;
    while (lineStream >> song_id)
        this->my_songs->push_back(song_id);
    
    this->popularity = popularity;
    this->my_id = playlist_id;
}


Playlist::Playlist(string str_of_songs, int popularity){
    stringstream lineStream(str_of_songs);
    string song_id;
    //vector<string> temp;
    this->my_songs = new vector<string>();
    this->my_song_stream = str_of_songs;
    while (lineStream >> song_id)
        this->my_songs->push_back(song_id);
    this->popularity = popularity;

    // generate a unique identifier
    string temp_str = "";
    for(unsigned int i = 0; i < 31; ++i){
        temp_str += genRandom();
    }
    this->my_id = temp_str;

}

Playlist::~Playlist(){
    
}

string Playlist::getId(){
    return this->my_id;
}

int Playlist::getPopularity(){
    return this->popularity;
}

void Playlist::remove(){

    //Friend Of God, Your Great Name, Collide, September

    // iterate through my songs, minusing their popularities
    for(int ii = 0; ii < this->my_songs->size(); ii++){
        string song_id = this->my_songs->at(ii);
        //cout << this->getId() << endl;
        //sng_c->query(song_id)->print_playlist_ids();
        sng_c->query(song_id)->song_delete_playlist(this->getId());
        //sng_c->query(song_id)->print_playlist_ids();
        //std::cout << "id: " << song_id << " pop: " << sng_c->query(song_id)->getPopularity() << std::endl;
       // cout << song_id << endl;
    }
    //cout << this->my_songs->size() << endl;
}

