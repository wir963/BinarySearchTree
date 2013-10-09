//
//  CHAR.h
//  BinarySearchTree
//
//  Created by Welles Robinson on 10/21/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef BinarySearchTree_CHAR_h
#define BinarySearchTree_CHAR_h

using namespace std;

struct CHAR
{
    friend ostream& operator<<(ostream& out, const CHAR i);//overload out
    CHAR();
    CHAR( const char *c);
    CHAR( const CHAR &C);
    void operator= (const CHAR &C);
    bool operator< (const CHAR &C);
    bool operator== (const CHAR &C);
    char *_data;
    ~CHAR();
};

#endif
