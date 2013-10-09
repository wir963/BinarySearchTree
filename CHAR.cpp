//
//  CHAR.cpp
//  BinarySearchTree
//
//  Created by Welles Robinson on 10/21/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "CHAR.h"

CHAR::CHAR()
{
    _data = NULL;
}

CHAR::CHAR( const char *c)
{
    _data = new char[(strlen(c)+1)];
    strcpy(_data, c);
}

CHAR::CHAR(const CHAR &C)
{
    _data = new char[(strlen(C._data)+1)];
    strcpy(_data, C._data);
}

void CHAR::operator=(const CHAR &C)
{
    delete [] _data;
    _data = new char[(strlen(C._data)+1)];
    strcpy(_data, C._data);
}

/* Overloads the < operator
 *
 */
bool CHAR::operator<(const CHAR &C)
{
    const long minLength = min(strlen(C._data), strlen(_data));

    for (int i = 0; i < minLength; i++) {
        if (_data[i] < C._data[i]) {
            return true;
        }
        if (_data[i] > C._data[i]) {
            return false;
        }
        // ith indices are equal, check the (i+1)th index
    }
    if (strlen(_data) >= strlen(C._data))// meaning this is longer than or the same size as C so this >= C
        return false;
    return true;
}

bool CHAR::operator==(const CHAR &C)
{
    if (strlen(C._data) == strlen(_data)) {
        for (int i = 0; i < strlen(_data); i++) {
            if (_data[i] != C._data[i]) {
                return false;
            }
        }
        return true;
    }
    return false;
}

CHAR::~CHAR()
{
    delete[] _data;
}

ostream& operator<<(ostream& out, const CHAR c)//overload out
{
    out << c._data;
    return out;
}




