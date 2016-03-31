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
    Playlist(Playlist_Container* dp, string formatted_str);
    ~Playlist();
    
    // Unique ID
    int my_id;
    
    // this playlist's popularity
    int popularity;
    
    // (This may be replaced) All songs in this play list access using the song's unqiue ID
    vector<int> my_songs;
    
    // Pointer to the entire Playlist_Container
    Playlist_Container* pl_db;
    
private:
    
    int generate_id();
    
};

#endif /* defined(__PlayList_prac__Playlist__) */
