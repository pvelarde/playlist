//
//  Top8_Playlist_Container.hpp
//  prac_PlayList
//
//  Created by Nick Maresco on 4/5/16.
//  Copyright © 2016 ___Marss___. All rights reserved.
//

#ifndef Top8_Playlist_Container_h
#define Top8_Playlist_Container_h

#include "Playlist_Container.h"
#include <vector>

class Top8_Playlist_Container: public Playlist_Container{
public:
    
    Top8_Playlist_Container();
    ~Top8_Playlist_Container();
    
    // Pass in the index of the desired playlist
    bool add(string _id);
    
    bool erase(string _id);
    
    bool erase_least_popular();
    
    void sort();
    
    vector<string> top8_backend;

    static short int instance_count;
    
private:
    
protected:
    
    
};







#endif /* Top8_Top8_Playlist_Container_hpp */
