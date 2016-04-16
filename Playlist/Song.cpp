//
//  Song.cpp
//  PlayList_prac
//
//  Created by Nick Maresco on 2/11/16.
//  Copyright (c) 2016 ___Marss___. All rights reserved.
//

#include "Song.h"
#include "Song_Container.h"
#include "Playlist.h"
#include "Playlist_Container.h"

// Public

// Default Constructor
Song::Song(){
    song_id                 = "";
    song_title              = "";
    song_artist             = "";
    song_most_pop_playlist_id  = "NULL";
    song_popularity         = 0;
}

Song::Song(string sg_id, string sg_title, string sg_artist){
    song_id                 = sg_id;
    song_title              = sg_title;
    song_artist             = sg_artist;
    song_most_pop_playlist_id  = ""; //the most popular pl's ID
    song_popularity         = 0;
}

Song::~Song(){
    
}
//slight change
bool Song::song_delete_playlist(string play_id){
    bool result = false;
    this->song_popularity = this->song_popularity - pl_c->query(play_id)->getPopularity();
    
    for ( list<string>::iterator iterator = this->song_playlist_ids.begin(); iterator != this->song_playlist_ids.end() ; ++iterator ){
        if (play_id == *iterator) {
            song_playlist_ids.erase(iterator);
            if (pl_c->query(play_id)->getPopularity() == pl_c->query(this->song_most_pop_playlist_id)->getPopularity()) {
                for (list<string>::iterator checkPop = this->song_playlist_ids.begin(); checkPop != this->song_playlist_ids.end(); ++checkPop) {
                    if (*checkPop >= this->song_most_pop_playlist_id) {
                        this->song_most_pop_playlist_id = *checkPop;
                    }
                }
            }
            return true;
        }
    }
    return false;
}//teasf

bool Song::song_add_playlist(string playlist_id, int playlist_popularity){
    this->song_playlist_ids.push_front(playlist_id);
    this->song_popularity += playlist_popularity;
    
    if (pl_c->query(playlist_id)->getPopularity() >= pl_c->query(song_most_pop_playlist_id)->getPopularity()) {
        this->song_most_pop_playlist_id = playlist_id;
    }
    
    return true;
}


string Song::get_song_id(){
    return song_id;
}

string Song::get_song_name(){
    return song_title;
}

string Song::get_song_artist(){
    return song_artist;
}

string Song::get_song_most_pop_playlist_id(){
    return song_most_pop_playlist_id;
}

int Song::getPopularity(){
    return this->song_popularity;
}
