//
//  BNode.h
//  BinarySearchTree
//
//  Created by Welles Robinson on 10/20/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef BinarySearchTree_BNode_h
#define BinarySearchTree_BNode_h

template <typename T>
class BNode
{
public:
    BNode();
    T getValue();
    void setValue(T val);
    ~BNode();
private:
    T *_node;
    BNode *_left;
    BNode *_right;
    template <typename TreeType>
    friend class BinaryTree;
};

template <typename T>
BNode<T>::BNode()
{
    _left = _right = NULL;
    _node = NULL;
}

template <typename T>
T BNode<T>::getValue()
{
    return *_node;
}

template <typename T>
void BNode<T>::setValue(T val)
{
    *_node = val;
}


template <typename T>
BNode<T>::~BNode()
{
    delete _node;
}

#endif
