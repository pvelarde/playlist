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
#include <vector>
#include <map>
#include <string>
#include <iostream>

class Playlist;
class Song_Container;

using namespace std;

// grab ID from database if the song already exists
class Song{
    
public:
    
    Song();
    Song(string index, Song_Container* db);
    ~Song();

    // unique ID
    string index;
    
    // list of all playlists associated with
    vector<string> member_of;
    
    // pointer to the song database
    Song_Container* s_db;
    
private:

protected:
    
    
    
};




#endif /* defined(__PlayList_prac__Song__) */
