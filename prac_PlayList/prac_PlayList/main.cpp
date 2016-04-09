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
#include "Try.h"
#include <string>

using namespace std;

int main(int argc, const char * argv[]) {
    Try* temp = new Try();
    
    temp->insert("hello");
    temp->insert("hi");
    temp->insert("how deep");
    
    temp->hasPrefix("h");
    
    delete temp;
    return 0;
}
