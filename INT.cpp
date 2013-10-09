//
//  INT.cpp
//  BinarySearchTree
//
//  Created by Welles Robinson on 10/21/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "INT.h"

INT::INT()
{
    _data = NULL;
}

INT::INT(int a)
{
    _data = new int;
    *_data = a;
}

INT::INT(INT const &i)
{
    _data = new int;
    *_data = *i._data;
}

void INT::operator=(const INT &i)
{
    if (_data == NULL)
        _data = new int;
    *_data = *i._data;// . binds before *
}

bool INT::operator==(const INT &i)
{
    return *_data == *i._data;
}

bool INT::operator<(const INT &i)
{
    return *_data < *i._data;
}

INT::~INT()
{
    delete _data;
}

ostream& operator<<(ostream& out, const INT i)//overload out
{
    out << *i._data;
    return out;
}
