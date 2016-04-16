//
//  try.cpp
//  try
//
//  Created by Nick Maresco on 6/24/15.
//  Copyright (c) 2015 ___Marss___. All rights reserved.
//

#include "Try.h"
#include "string.h"

/* non-constrained Try*/
Try::Try(){
    this->setChildren();
    this->nodeValue = '\0';
    this->endWordFlag = false;
    this->count = 0;
    this->level = 0;
    this->overallTotal = 0;
    this->parentNode = NULL;
    // This is being set to 10 at default to avoid potential breakage
    this->acceptLength = 10;
}

/* Default/Initial constructor*/
Try::Try(int acceptLength){
    this->setChildren();
    this->nodeValue = '\0';
    this->endWordFlag = false;
    this->count = 0;
    this->level = 0;
    this->overallTotal = 0;
    this->parentNode = NULL;
    this->acceptLength = acceptLength;
}

/* Insertion constructor*/
Try::Try(char newChar, bool endOfWord, int level, Try * parent, int acceptLength){
    this->setChildren();
    this->nodeValue = newChar;
    this->count = 0;
    this->level = level;
    this->endWordFlag = endOfWord;
    this->parentNode = parent;
    this->acceptLength = acceptLength;
}

Try::~Try(){}

void Try::insert(string newWord){
    if(this->level == 0){this->overallTotal++;}
    if(newWord == ""){this->count++; /* Do nothing*/}
    else if(this->children[((int)(newWord[0]))] == NULL){
        bool endLetter = (newWord.length() == 1)?true:false;
        
        Try *  newTry = new Try(newWord[0],endLetter,(this->level + 1),this,this->acceptLength);
        this->children[(int)(newWord[0])] = newTry;
        this->children[(int)(newWord[0])]->insert(newWord.substr(1,newWord.length() - 1));
    }
    else if(this->children[((int)(newWord[0]))] != NULL){
        /* Need a way to get to the bottom try to increment its count*/
        this->children[(int)(newWord[0])]->insert(newWord.substr(1,newWord.length() - 1));
    }
    
    if(newWord.length() == 0){
        this->endWordFlag = true;
    }
}

int Try::check(string checkStr){
    int result;
    
    if((this->children[((int)(checkStr[0]))] != NULL) && (checkStr != "")){
        result = this->children[((int)(checkStr[0]))]->check(checkStr.substr(1,checkStr.length() - 1));
    }
    else if(this->endWordFlag){
        result = this->count;
    }
    else{
        /*indicating that there have been no insertions of the check string into the structure*/
        result = 0;
    }

    return result;
}

void Try::print(){
    if(this->level == 0){;
        cout << "Root: words inserted: " << this->overallTotal << ' ' << endl;
    }

    cout << "level: " << this->level << " node-value: " << this->nodeValue << " end-of-word: " << this->endWordFlag  << " children: ";
    
    for(int ii = 0; ii < ASCII_NUM; ii++){
        if(this->children[ii] != NULL){
            cout << this->children[ii]->nodeValue << ' ';
        }
    } if(this->endWordFlag == false){cout << endl;}
    
    for(int jj = 0; jj < ASCII_NUM; jj++){
        if(this->children[jj] != NULL){
            this->children[jj]->print();
        }
    } if(this->endWordFlag == true){cout << " count: " << this->count << endl << endl;}
    
}


/* Sets all the children to NULL pointers*/
void Try::setChildren(){
    for(int ii = BEGIN_CHAR; ii < ASCII_NUM; ii++){
        this->children[ii] = NULL;
    }
}

void Try::print_all(string inn){ // default: inn == ""
    
    if(this->endWordFlag && this->hasChildren()){
        cout << inn << endl;
    }
    if(this->endWordFlag && this->hasChildren() == false){
        cout << inn << endl;
    }
    
    for(int ii = 0; ii < ASCII_NUM; ii++){
        char next = ii;
        
        if(this->children[ii]){
            inn = inn + next;
            this->children[ii]->print_all("",inn);
            inn.erase(strlen(inn.c_str())-1, 1);
        }
    }
}

string Try::find_one(string prefix, string inn){
    string result = "";
    
    if(this->endWordFlag && this->hasChildren()){
        result = inn;//cout << inn << endl;
    }
    if(this->endWordFlag && this->hasChildren() == false){
        result = inn;//cout << inn << endl;
    }
    
    for(int ii = 0; ii < ASCII_NUM; ii++){
        char next = ii;
        
        if(this->children[ii]){
            inn = inn + next;
            result = this->children[ii]->find_one("",inn);
            inn.erase(strlen(inn.c_str())-1, 1);
        }
    }
    
    return result;
}

void Try::print_all(string prefix, string inn){ // default: inn == ""
    
    if(this->endWordFlag && this->hasChildren()){
        cout << prefix + inn << endl;
    }
    if(this->endWordFlag && this->hasChildren() == false){
        cout << prefix + inn << endl;
    }
    
    for(int ii = 0; ii < ASCII_NUM; ii++){
        char next = ii;
        
        if(this->children[ii]){
            inn = inn + next;
            this->children[ii]->print_all(prefix,inn);
            inn.erase(strlen(inn.c_str())-1, 1);
        }
    }
}

void Try::hasPrefix(string inn){
    string temp = inn;
    Try * pass = this->children[temp[0]];
    
    while(temp != "" && pass != NULL){
        // if its not null
        
        if(temp.length() == 1){
           pass->print_all(inn,"");
        }
        
        temp = temp.substr(1,temp.length()-1);
        pass = pass->children[temp[0]];
    }
}

string Try::auto_complete(string inn){
    string result = "";
    string temp = inn;
    Try * pass = this->children[temp[0]];
    
    while(temp != "" && pass != NULL){
        if(temp.length() == 1){
            return inn + pass->find_one(inn,"");
        }
        
        temp = temp.substr(1,temp.length()-1);
        pass = pass->children[temp[0]];
    }
    return result;
}

bool Try::hasChildren(){
    bool result = false;
    
    for(int ii = 0; ii < ASCII_NUM; ii++){
        if(this->children[ii] != NULL){
            result = true;
            break;
        }
    }
    
    return result;
}

/* Will return both the word and the amount of times it was inserted*/
/* Execute this only after the structure has beeen completely loaded*/
void Try::getAllWords(){
    /* Once inside the deepest try*/
    if(this->endWordFlag){
        string word = this->goToParent();
        string temp = "";
        for(int kk = 1; kk < this->acceptLength; kk++){
            temp += word[word.length() - kk];
            if(kk == this->acceptLength - 1){
                word = temp;
            }
        }
        
        cout << word << this->nodeValue;
        cout << " count " << this->count << endl;
    }
    else{
        /* Alows for traversial of all branches*/
        for(int ii = 0; ii < ASCII_NUM; ii++){
            if(this->children[ii] != NULL){
                this->children[ii]->getAllWords();
            }
        }
    }
}

/* This was written from the perspective of the bottom-most node*/
string Try::goToParent(){
    static string result = "";
    
    if(this->parentNode != NULL){
        if(this->parentNode->nodeValue != '\0'){
        
            result += this->parentNode->nodeValue;
            this->parentNode->goToParent();
        }
    }

    if((this-> level == 1) && result.length() > this->acceptLength){
        result = result.substr(this->acceptLength - 1,result.length() - this->acceptLength + 1);
    }
    
    return result;
}

/* Will return a vector with a count-based distribution */
void Try::getDistribution(){
    if(this->level == 0){
        vector<int> refresh;
        this->distribution = refresh;
    }
    
    /* Once inside the deepest try*/
    if(this->endWordFlag){
        string word = this->goToParent();
        string temp = "";
        for(int kk = 1; kk < this->acceptLength; kk++){
            temp += word[word.length() - kk];
            if(kk == this->acceptLength - 1){
                word = temp;
            }
        }
    
        /* Need some way of adding this count*/
        Try * root = this->returnRoot(); //NOTICE: at this point the program will be at a level n node
        root->distribution.push_back(this->count);
        
    }
    else{
        /* Alows for traversial of all branches*/
        for(int ii = 0; ii < ASCII_NUM; ii++){
            if(this->children[ii] != NULL){
                this->children[ii]->getDistribution();
            }
        }
    }
}

/* Returns the pointer to the Root*/
Try * Try::returnRoot(){
    if(this->parentNode->nodeValue != '\0'){
        return this->parentNode->returnRoot();
    }
    else{
        return this->parentNode;
    }
    
}
