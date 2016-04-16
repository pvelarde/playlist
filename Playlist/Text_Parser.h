//
//  Text_Parser.hpp
//  prac_PlayList
//
//  Created by Nick Maresco on 4/5/16.
//  Copyright © 2016 ___Marss___. All rights reserved.
//

#ifndef Text_Parser_h
#define Text_Parser_h

#include <stdio.h>
#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "Song_Container.h"
#include "Playlist_Container.h"
#include "Song.h"
#include "Playlist.h"
#include <QString>
#include <QFile>
#include <QDir>
#include <QDebug>

//class Song;
//class Song_Container;
//class Playlist_Container;

using namespace std;

class Text_Parser{

public:

    /*  WHAT IS LEFT TO IMPLEMENT

     -- this needs to get a pointer from the main playlist_container and song_container respectively
         -- the parser functions should not be actually create the containers

     */

    Text_Parser(QString file_name);
    ~Text_Parser();

    Song_Container* parse_song_text();
    Playlist_Container* parse_playlist_text();


private:

    QString my_file;

};

#endif /* Text_Parser_hpp */
