//
//  Song.cpp
//  PlayList_prac
//
//  Created by Nick Maresco on 2/11/16.
//  Copyright (c) 2016 ___Marss___. All rights reserved.
//

#include "Song.h"

// Public

// Default Constructor
Song::Song(){
    song_id                 = "NULL";
    song_title              = "NULL";
    song_artist             = "NULL";
    song_most_pop_playlist  = "NULL";
    song_popularity         = 0;
}

Song::Song(string sg_id, string sg_title, string sg_artist){
    song_id                 = sg_id;
    song_title              = sg_title;
    song_artist             = sg_artist;
    song_most_pop_playlist  = "NULL";
    song_popularity         = 0;
}

Song::~Song(){
    
}
//slight change
bool Song::song_delete_playlist(string play_id){
    bool result = false;
    song_popularity = song_popularity - pl_c.query(play_id).getPopularity();
    
    for ( list<string>::iterator iterator = song_playlist_ids.begin(); iterator != song_playlist_ids.end() ; ++iterator ){
        if (play_id == *iterator) {
            song_playlist_ids.erase(iterator);
            if (pl_c.query(play_id).get_song_popularity() == song_most_pop_playlist) {
                for (list<string>::iterator checkPop = song_playlist_ids.begin(); checkPop != song_playlist_ids.end(); ++checkPop) {
                    if (*checkPop >= song_most_pop_playlist) {
                        song_most_pop_playlist = *checkPop;
                    }
                }
            }
            return true;
        }
    }
    return false;
}//teasf

bool Song::song_add_playlist(string playlist_id, int playlist_popularity){
    song_playlist_ids.push_front(playlist_id);
    song_popularity += playlist_popularity;
    
    if (pl_c.query(playlist_id).getPopularity >= song_most_pop_playlist) {
        song_most_pop_playlist = playlist_id;
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

string Song::get_song_most_pop_playlist(){
    return song_most_pop_playlist;
}

int Song::get_song_popularity(){
    return song_popularity;
}