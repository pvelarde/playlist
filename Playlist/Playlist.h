//
//  Playlist.h
//  PlayList_prac
//
//  Created by Nick Maresco on 2/11/16.
//  Copyright (c) 2016 ___Marss___. All rights reserved.
//

#ifndef __PlayList_prac__Playlist__
#define __PlayList_prac__Playlist__

#include <stdio.h>
#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <sstream>

class Song;
class Playlist_Container;

using namespace std;

class Playlist{
    
public:
    
    Playlist();
    
    Playlist(string playlist_id, string str_of_songs, int popularity);
    
    ~Playlist();
    
    // Getters
    string getId();
    
    int getPopularity();
    
    // (This may be replaced with another datastructure) All songs in this play list access using the song's unqiue ID
    vector<string> my_songs;
    
    // Pointer to the entire Playlist_Container
    Playlist_Container* pl_db;
    
    // Unique ID
    string my_id;

    // For Debugging purposes
    string my_song_stream;

    // this playlist's popularity
    int popularity;
    
private:
    
};

#endif /* defined(__PlayList_prac__Playlist__) */
