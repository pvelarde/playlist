//
//  main.cpp
//  auto-complete_prac
//
//  Created by Nick Maresco on 2/13/16.
//  Copyright (c) 2016 ___Marss___. All rights reserved.
//

#include <iostream>
#include "Try.h"

int main(int argc, const char * argv[]) {

    Try * temp = new Try();
    
    temp->insert("hi");
    temp->insert("hire me");
    temp->insert("hello its me");
    temp->insert("hello");
    temp->insert("howdy");
    temp->insert("harry");
    temp->insert("heyo");
    temp->insert("heya");
    temp->insert("heee");
    temp->insert("heir");
    temp->insert("how are you");
    temp->insert("the duck");
    temp->insert("there");
    temp->insert("there I was");
    temp->insert("what am I doing");
    
    cout << temp->auto_complete("how ") << endl;
    
    //temp->hasPrefix("hi");
    
    //temp->print_all();
    
    
    
    
    return 0;
}
