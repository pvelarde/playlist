//
//  try.h
//  try
//
//  Created by Nick Maresco on 6/24/15.
//  Copyright (c) 2015 ___Marss___. All rights reserved.
//

#ifndef __try__try__
#define __try__try__

#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define BEGIN_CHAR 0
#define ASCII_NUM 256

class Try{
    
public:
    
    /* Default Constructor */
    Try();
    
    /* Initial constructor -- used for establishing the root try*/
    Try(int acceptLength);
    
    /* Insertion constructor -- used for adding new trys*/
    Try(char newChar, bool endOfWord, int level, Try * parent, int acceptLength);
    
    /* Be sure to free up that memory*/
    ~Try();
    
    /* Used to add words to the try data structure.
     * Can only insert into the ROOT node/try
     * based off root insertion then take the individual
     * characters of the insertion string and create children
     * trys.
     */
    void insert(string newWord);
    
    /* Returns the first string the prefix matches (Similar to hasPrefix function but has an actual return value) */
    string auto_complete(string inn);
    
    /* Returns whether or not a node has children */
    bool hasChildren();
    
    /* Allows the user to check if a certain word exists or not already in the try*/
    int check(string checkStr);
    
    /* User friendly way to view the contents within the try tree*/
    void print();
    
    /* Sets all the children of the current try/node to NULL*/
    void setChildren();
    
    /* Will print out every word in the try structure*/
    void getAllWords();
    
    /* Pass in a string and will print all the strings with that prefix */
    void hasPrefix(string inn);
    
    vector<string>* hasPrefixAsVector(string inn);

    /* Recursive call that allows the current try traverse the structure upwards*/
    string goToParent();
    
    /* Returns a pointer to a vector that houses a count-based distribution*/
    void getDistribution();
    
    /* From any child node, will return pointer to the root parent*/
    Try * returnRoot();
    
    /* return the first word formed with inn as starting letter */
    string find_one(string inn = "");
    
    /* Overload in the case you want prefixes */
    string find_one(string prefix, string inn = "");
    
    
    /* This will tell you in total how many words are in the entire structure.
     * Perhaps only the root try should just keep track every time it is
     * inserted into to minimize confusion
     */
    int overallTotal;
    
    /* If the node is the end of a word, endWordFlag will be set*/
    bool endWordFlag;
    
    /* At the end nodes, this will keep track of how many times it has been s"inserted"*/
    int count;
    
    /* With the root try/node at level 0, this will indicate the depth at which a try/node is at*/
    int level;
    
    /* Each try will correspond to a value/char except the root node/try*/
    char nodeValue;
    
    /* Each try off of the initial root will have a parentNode value*/
    Try* parentNode;
    
    /* Houses the children of the current node/try*/
    Try* children[ASCII_NUM];
    
    /* This houses a constant used for trie storage/computation*/
    int acceptLength;
        
    /* will print out all words in the Try */
    void print_all(string inn = "");
    
    /* Overload in the case you want prefixes */
    void print_all(string prefix, string inn = "");
    
    /* Houses the entire distribution as a count of integers*/
    vector<int> distribution;
    
    /* Houses suggestions based on the prefix function.
     * Cannot use until the hasPrefixAsVector has been called*/
    vector<string>* temp_suggests;

private:
    
protected:
    
};


#endif /* defined(__try__try__) */
