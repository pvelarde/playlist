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
#include <string>
#include <iostream>
#include "mainwindow.h"

class Playlist;
class Song;

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
    
    map<string,Playlist*> pl_backend;
    static short int instance_count;
    
private:
    
protected:
    
    
};





#endif /* defined(__PlayList_prac__Playlist_Container__) */
