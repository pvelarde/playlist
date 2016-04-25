//
//  Playlist_Container.h
//  PlayList_prac
//
//  Created by Nick Maresco on 2/11/16.
//  Copyright (c) 2016 ___Marss___. All rights reserved.
//

#ifndef __PlayList_prac__Playlist_Container__
#define __PlayList_prac__Playlist_Container__

#include <stdio.h>
#include <map>
#include <utility>
#include <string>
#include <iostream>
#include <vector>
#include "mainwindow.h"
#include "Song_Container.h"
#include "Song.h"

class Playlist;
//class Song;

using namespace std;

/* Should be a singleton */

class Playlist_Container{
public:
    /*  WHAT IS LEFT TO IMPLEMENT
     
     -- add functionality to keep it to a max size of 1024
     
     
     
     
     */
    Playlist_Container();
    ~Playlist_Container();

    // Pass in the index of the desired playlist
    Playlist* query(string _id);
    bool add(Playlist* new_pl);
    bool erase(string _id);
    // this is called after new playlists have been introduced to the container
    void refine();
    void print();

    //this function will go through and query all live 1024 playlists. It will sort them based on popularity but store the
    // associated UIDs in the "my_sortd_ids" vector - note this array will not be maintained. It will need to be constantly
    // re-sorted
    void sort_me();

    void sort_me_initially();

    void update_song_popularities();
    
    map<string,Playlist*> pl_backend;
    vector<string> my_sorted_ids;
    static short int instance_count;
    
private:
    
protected:
    
    
};





#endif /* defined(__PlayList_prac__Playlist_Container__) */
