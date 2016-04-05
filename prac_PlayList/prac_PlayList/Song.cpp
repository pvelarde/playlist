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

bool Song::song_delete_playlist(string play_id){
    song_popularity = song_popularity - pl_c.query(play_id).getPopularity();
    //function delete is not complete you need to make sure that the list with the playlists deletes the proper element of the list. that is the play_id in the list
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