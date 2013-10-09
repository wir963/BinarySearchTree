//
//  INT.h
//  BinarySearchTree
//
//  Created by Welles Robinson on 10/21/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef BinarySearchTree_INT_h
#define BinarySearchTree_INT_h

using namespace std;

struct INT
{
    friend ostream& operator<<(ostream& out, const INT i);//overload out
    int* _data;
    INT();
    INT(int a);
    INT(INT const &i);
    void operator=(const INT &i);
    bool operator<(const INT &i);
    bool operator==(const INT &i);
    ~INT();
};

#endif
