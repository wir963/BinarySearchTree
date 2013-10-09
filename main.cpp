//
//  main.cpp
//  BinarySearchTree
//
//  Created by Welles Robinson on 10/20/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include "CHAR.h"
#include "INT.h"
#include "BinaryTree.h"

using namespace std;

int main (int argc, const char * argv[])
{
    ifstream inFile;
    string lineFromFile;
    
    if(argc != 2){
        cerr << "Usage: inputStream filename " << endl;
        exit(1);
    }
    
    inFile.open(argv[1]);
    if (!inFile.good()) {
        cerr << "Error opening file " << argv[1] << endl;
    } 
    char c;
    c = inFile.peek();
    if ( (c >= '0') && (c <= '9')) {
        BinaryTree<INT> bt;
        while( std::getline(inFile, lineFromFile) ){
            stringstream s(lineFromFile);
            std::string term;
            s >> term;
            bt.insert(INT(atoi(term.c_str())));
        }
        bt.printPreOrder();
    } else {
        BinaryTree<CHAR> ch;
        while( std::getline(inFile, lineFromFile) ){
            stringstream s(lineFromFile);
            std::string term;
            s >> term;
            char *a=new char[term.size()+1];
            a[term.size()]=0;
            memcpy(a,term.c_str(),term.size());
            ch.insert(CHAR(a));
            delete[] a;
        }
        ch.printPreOrder();
        char* s = new char[3];
        s[0] = 'b';
        s[1] = 'e';
        s[2] = 'd';
        
        CHAR t(s);
        ch.delete_one(t);
        ch.printInOrder();
    }
    
    
    
    return 0;
}

