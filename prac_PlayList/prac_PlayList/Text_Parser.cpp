//
//  Text_Parser.cpp
//  prac_PlayList
//
//  Created by Nick Maresco on 4/5/16.
//  Copyright © 2016 ___Marss___. All rights reserved.
//

#include "Text_Parser.h"

Text_Parser::Text_Parser(string file_name){
    this->my_file = file_name;
}

Text_Parser::~Text_Parser(){
    
}

Song_Container* Text_Parser::parse_song_text(){
    Song_Container * sng_c = NULL;
    
    string line;
    ifstream myfile (this->my_file);
    if (myfile.is_open())
    {
        sng_c = new Song_Container();
        while ( getline (myfile,line) )
        {
            string deliminator = "	";

            // find id
            string id = "";
            for(int ii = 0; ii < line.find(deliminator); ii++){
                id += line[ii];
            }
            line = line.substr(line.find(deliminator)+1,line.length()-line.find(deliminator)+1);
            
            string song_name = "";
            for(int ii = 0; ii < line.find(deliminator); ii++){
                song_name += line[ii];
            }
            line = line.substr(line.find(deliminator)+1,line.length()-line.find(deliminator)+1);
            
            // find song artist
            string artist_name = line;
            
            
            // id, song_name, and artist_name are set at this point
// UNCOMMENT            Song* new_song = new Song(id,song_name,artist_name);
// UNCOMMENT           sng_c->add(new_song);
            
        }
        myfile.close();
    }
    
    else cout << "Unable to open file";
    
    return sng_c;
}

static const char alphanum[] =
"0123456789"
"!@#$%^&*"
"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
"abcdefghijklmnopqrstuvwxyz";

int stringLength = sizeof(alphanum) - 1;

char genRandom(){
    return alphanum[rand() % stringLength];
}

Playlist_Container* Text_Parser::parse_playlist_text(){
    Playlist_Container* pl_c = NULL;
    
    string line;
    ifstream myfile (this->my_file);
    if (myfile.is_open())
    {
        pl_c = new Playlist_Container();
        while ( getline (myfile,line) )
        {
            string deliminator = " 	";
            string str_of_song_ids = "";
            for(int ii = 0; ii < line.find(deliminator); ii++){
                str_of_song_ids += line[ii];
            }// + 2 since the deliminator is 2 characters long
            line = line.substr(line.find(deliminator)+2,line.length()-line.find(deliminator)+1);
            string pl_pop = line;
            int pl_popularity = stoi(pl_pop);
            
            srand(time(0));
            string temp_str = "";
            for(unsigned int i = 0; i < 31; ++i){
                temp_str += genRandom();
            }
            cout << temp_str << endl;
            
            // pl_popularity, str_of_song_ids are set at this point
            Playlist* new_pl = new Playlist(temp_str, str_of_song_ids, pl_popularity);
            pl_c->add(new_pl);
            
        }
        myfile.close();
    }
    
    else cout << "Unable to open file";

    
    
    
    return pl_c;
}
