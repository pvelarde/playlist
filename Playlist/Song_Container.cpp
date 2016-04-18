//
//  Song_Container.cpp
//  PlayList_prac
//
//  Created by Nick Maresco on 2/11/16.
//  Copyright (c) 2016 ___Marss___. All rights reserved.
//

#include "Song_Container.h"
#include "Song.h"

// Public

Song_Container::Song_Container(){
   /* this->instance_count = 0;
    this->instance_count++;
    
    if(this->instance_count > 1){
        cout << "you have illegally made another instance of a singleton" << endl;
    }*/
}

Song_Container::~Song_Container(){
    
}

Song* Song_Container::query(string _id){
    Song* result = NULL;
    result = this->s_backend.find(_id)->second;
    return result;
}

void Song_Container::add(Song* new_s){
    //bool result;
    this->s_backend.insert(std::pair<string,Song*>(new_s->get_song_id(),new_s));
    //return result;
}

// return true if the element was deleted successfully
bool Song_Container::erase(string _id){
    bool result = false;
    std::map<string,Song*>::iterator it;
    it = this->s_backend.find(_id);
    // return true if successfully deleted
    if (it != this->s_backend.end()){
        this->s_backend.erase(it);
        result = true;
    }
    return result;
}

void Song_Container::print(){
    this->s_backend; // map<string,Playlist*> s_backend
    int ii = 0;
    for(map<string, Song* >::const_iterator it = s_backend.begin();it != s_backend.end(); ++it){
        std::cout << "counter " << ii << " song title: " << it->second->get_song_name() << " id: " << it->first << "\n";
        ii++;
    }
}

Try* Song_Container::load_trie_w_songs(){
    Try* search_tree = new Try();
    // load up the Trie Tree with all the songs in the system
    for(map<string, Song* >::const_iterator it = s_backend.begin();it != s_backend.end(); ++it){
        search_tree->insert(it->second->get_song_name());
    }
    return search_tree;
}




