//
//  main.cpp
//  prac_PlayList
//
//  Created by Nick Maresco on 2/11/16.
//  Copyright (c) 2016 ___Marss___. All rights reserved.
//

#include <iostream>
#include "Song.h"
#include "Playlist.h"
#include "Playlist_Container.h"
#include "Song_Container.h"
#include <string>

using namespace std;

int main(int argc, const char * argv[]) {

    Playlist_Container* pl_DB = new Playlist_Container();
    Song_Container* s_DB = new Song_Container();
    
    string str = "\t";
    string str0 = "0\t32";
    string str1 = "3 2 23 64 75 233\t50";
    string str2 = "45 34 3 2 6 2 33 53 534 2 34\t250";
    string str3 = "1 2 3\t40";
    
    Playlist * temp = new Playlist(pl_DB,str);
    
    
    
    return 0;
}
