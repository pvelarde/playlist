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

class Playlist;
class Song;

using namespace std;

/* Should be a singleton */

class Song_Container{
public:
    
    Song_Container();
    ~Song_Container();
    
    bool add(Song*);
    Song* query(int _id);
    bool erase(int _id);
    
    map<int,Song*> s_backend;
    static short int instance_count;
    
private:
    
protected:
    
    
};

#endif /* defined(__PlayList_prac__Song_Container__) */
