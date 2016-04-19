//
//  Playlist_Container.cpp
//  PlayList_prac
//
//  Created by Nick Maresco on 2/11/16.
//  Copyright (c) 2016 ___Marss___. All rights reserved.
//

#include "Playlist_Container.h"
#include "Playlist.h"

// Public

Playlist_Container::Playlist_Container(){
   /* this->instance_count = 0;
    this->instance_count++;
    
    if(this->instance_count > 1){
        cout << "you have illegally made another instance of a singleton" << endl;
    }*/
}

Playlist_Container::~Playlist_Container(){
    
}

Playlist* Playlist_Container::query(string _id){
    Playlist* result = NULL;
    result = this->pl_backend.find(_id)->second;
    return result;
}

bool Playlist_Container::add(Playlist* new_pl){
    bool result = true;
    this->pl_backend.insert(std::pair<string,Playlist*>(new_pl->getId(),new_pl));
    return result;
}

bool Playlist_Container::erase(string _id){
    bool result = true;
    Playlist* temp = this->pl_backend.find(_id)->second;
    this->pl_backend.erase(_id);
    delete temp;
    return result;
}

void Playlist_Container::print(){
    this->pl_backend; // map<string,Playlist*> pl_backend
    int ii = 0;
    for(map<string, Playlist* >::const_iterator it = pl_backend.begin();it != pl_backend.end(); ++it){
        std::cout << "counter " << ii << " id: " << it->first << "\n";
        ii++;
    }
}

void Playlist_Container::sort_me(){
    // empty the current IDs
    this->my_sorted_ids.clear();
    // first load all the IDs in the vector
    for(map<string, Playlist* >::const_iterator it = pl_backend.begin();it != pl_backend.end(); ++it){
        //std::cout << "counter " << ii << " id: " << it->first << "\n";
       // ii++;
        this->my_sorted_ids.push_back(it->first);
        //std::cout << it->first << std::endl;
    }

    // bubble sort the array
    int nn = this->pl_backend.size();
    for (int ii = 0 ; ii < ( nn - 1 ); ii++)
      {
        for (int jj = 0 ; jj < nn - ii - 1; jj++)
        {
          if ( this->query(this->my_sorted_ids.at(jj))->getPopularity() > this->query(this->my_sorted_ids.at(jj+1))->getPopularity()) /* For decreasing order use < */
          {
              //std::cout << this->query(this->my_sorted_ids.at(jj))->getPopularity() << std::endl;
            string swap = this->my_sorted_ids.at(jj);
            this->my_sorted_ids.at(jj)   = this->my_sorted_ids.at(jj+1);
            this->my_sorted_ids.at(jj+1) = swap;
          }
        }
      }

   /* // Just for debugging purposes
    *  for(int kk = 0; kk < nn; kk++){
        std::cout << this->query(this->my_sorted_ids.at(kk))->getPopularity() << std::endl;
    }*/

}

void Playlist_Container::update_song_popularities(){
    // iterate through all pairs of the playlist
    for(map<string, Playlist* >::const_iterator it = pl_backend.begin();it != pl_backend.end(); ++it){
        // for each playlist go through all its songs add the playlist's popularity to it
        for(int ii = 0 ; ii < it->second->my_songs.size(); ii++){
            // add playlist's pop to each song it is associated with
            sng_c->query(it->second->my_songs.at(ii))->song_add_playlist(it->second->getId());
        }
    }
}

// should be called after each add() after the inital load
void Playlist_Container::refine(){
    // sort all the objects by their ID
    this->sort_me();
    //access the least popular playlist
    string weakest_pl_id = this->my_sorted_ids.at(0);

    //remove the pair from the container,
    //iterate through the songs in the pl & adjust their popularities

    this->query(weakest_pl_id)->remove(); // remove the songs' pop from this playlist
    this->erase(weakest_pl_id); // remove the actual object
}

