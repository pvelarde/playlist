//
//  Song.h
//  PlayList_prac
//
//  Created by Nick Maresco on 2/11/16.
//  Copyright (c) 2016 ___Marss___. All rights reserved.
//

#ifndef __PlayList_prac__Song__
#define __PlayList_prac__Song__

#include <stdio.h>
#include <list>
#include <map>
#include <string>
#include <iostream>

class Playlist;
class Song_Container;

using namespace std;

// grab ID from database if the song already exists

//assumption: the songs in the database are not changing

/*
each song will have:
 a variable equal to the song title
 a variable equal to the song artist
 a variable equal to the song id
 a variable equal to the id of the most popular playlist
 a variable of the current popularity
 a list of playlist ids that the song belongs to
 a function to add a playlist to the list
 a function to delete a playlist to the list
 a function to update the popularity of the song
 
 constructor will have id song name song artist
 
 */



class Song{
    
public:
    
    Song();
    Song(string song_id, string song_title, string song_artist);
    ~Song();

    //getters
    string get_song_id();
    string get_song_name();
    string get_song_artist();
    string get_song_most_pop_playlist();
    int get_song_popularity();

    //functions
    bool song_delete_playlist(string song_id);
    bool song_add_playlist(string playlist_id, int playlist_popularity);
    
private:
    //variables of song
    string song_id;
    string song_title;
    string song_artist;
    string song_most_pop_playlist;
    int song_popularity;
    
    list<string> song_playlist_ids;

protected:
    
    
    
};




#endif /* defined(__PlayList_prac__Song__) */
