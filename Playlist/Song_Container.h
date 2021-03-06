//
//  Song_Container.h
//  PlayList_prac
//
//  Created by Nick Maresco on 2/11/16.
//  Copyright (c) 2016 ___Marss___. All rights reserved.
//

#ifndef __PlayList_prac__Song_Container__
#define __PlayList_prac__Song_Container__

#include <stdio.h>
#include <map>
#include <string>
#include <iostream>
#include "mainwindow.h"
#include "Try.h"

class Playlist;
class Song;
class Try;

using namespace std;

/* Should be a singleton */

class Song_Container{
public:
    
    Song_Container();
    ~Song_Container();
    
    void add(Song*);
    Song* query(string _id);
    // name is the song title
    Song* query_by_name(string name);
    bool erase(string _id);
    
    void print();
    Try* load_trie_w_songs();

    map<string,Song*> s_backend_id2name; // this actually returns the actual object
    map<string,string> s_backend_name2id;
    static short int instance_count;
    
private:
    
protected:
    
    
};

#endif /* defined(__PlayList_prac__Song_Container__) */
