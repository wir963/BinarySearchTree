//
//  BinaryTree.h
//  BinarySearchTree
//
//  Created by Welles Robinson on 10/20/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef BinarySearchTree_BinaryTree_h
#define BinarySearchTree_BinaryTree_h

#include "BNode.h"

using namespace std;

template <typename TreeType>
class BinaryTree
{
public:
    BinaryTree();
    ~BinaryTree();
    void insert(TreeType t);
    void printInOrder();
    void printPreOrder();
    void printPostOrder();
    void delete_one(TreeType t);
    bool find(TreeType t);
    bool empty();
    int height();
private:
    void _delete_all(BNode<TreeType> *&_rt);
    void delete_node(BNode<TreeType> *&_rt);
    int _height(BNode<TreeType>* _rt);
    void _insert(BNode<TreeType>* &_rt, TreeType t);
    TreeType findPredecessor(BNode<TreeType>* _rt);
    void _printPostOrder(BNode<TreeType>* _rt);
    void _printPreOrder(BNode<TreeType>* _rt);
    void _printInOrder(BNode<TreeType>* _rt);
    bool _delete(BNode<TreeType>* &_rt, TreeType t);
    bool _find(BNode<TreeType>* _rt, TreeType t);
    
    BNode<TreeType> *_root, *_temp;
    int _nodeCount;
};

//default constructor
template <typename TreeType>
BinaryTree<TreeType>::BinaryTree()
{
    _root = _temp = NULL;
}

// insert function
template <typename TreeType>
void BinaryTree<TreeType>::insert(TreeType t)
{
    _insert(_root, t);
}

template <typename TreeType>
bool BinaryTree<TreeType>::empty()
{
    return _root == NULL;
}

template <typename TreeType>
void BinaryTree<TreeType>::_insert(BNode<TreeType>* &_rt,TreeType t)
{
    if (_rt == NULL) {
        _rt = new BNode<TreeType>;
        _rt->_node = new TreeType;
        _rt->setValue(t);
    }
    else if (*_rt->_node < t)
        _insert(_rt->_right, t);
    else
        _insert(_rt->_left, t);
}

template <typename TreeType>
void BinaryTree<TreeType>::printInOrder()
{
    cout << "Printing In Order" << endl;
    if (empty()) {
        cout << "This tree is empty" << endl;
    }
    else {
        _printInOrder(_root);
        cout << '\n';
    }
}

template <typename TreeType>
void BinaryTree<TreeType>::_printInOrder(BNode<TreeType>* _rt)
{
    if (_rt->_left != NULL) {
        _printInOrder(_rt->_left);
    }
    cout << *_rt->_node << endl;
    if (_rt->_right != NULL) {
        _printInOrder(_rt->_right);
    }
}

template <typename TreeType>
void BinaryTree<TreeType>::printPreOrder()
{
    cout << "Printing Pre Order" << endl;
    if (empty()) {
        cout << "This tree is empty" << endl;
    }
    else {
        _printPreOrder(_root);
        cout << '\n';
    }
}

template <typename TreeType>
void BinaryTree<TreeType>::_printPreOrder(BNode<TreeType>* _rt)
{
    cout << *_rt->_node << endl;
    if (_rt->_left != NULL) {
        _printPreOrder(_rt->_left);
    }
    if (_rt->_right != NULL) {
        _printPreOrder(_rt->_right);
    }
}

template <typename TreeType>
void BinaryTree<TreeType>::printPostOrder()
{
    cout << "Printing Post Order" << endl;
    if (empty()) {
        cout << "This tree is empty" << endl;
    }
    else {
        _printPostOrder(_root);
        cout << '\n';
    }
}

template <typename TreeType>
void BinaryTree<TreeType>::_printPostOrder(BNode<TreeType>* _rt)
{
    if (_rt->_left != NULL) {
        _printPostOrder(_rt->_left);
    }
    if (_rt->_right != NULL) {
        _printPostOrder(_rt->_right);
    }
    cout << *_rt->_node << endl;
}

template <typename TreeType>
int BinaryTree<TreeType>::height()
{
    return _height(_root) - 1;
}

template <typename TreeType>
int BinaryTree<TreeType>::_height(BNode<TreeType>* _rt)
{
    if (_rt == NULL)
        return 0;
    
    return 1 + max(_height(_rt->_right), _height(_rt->_left));
}

template <typename TreeType>
bool BinaryTree<TreeType>::find(TreeType t)
{
    return (_find(_root, t));
}

template <typename TreeType>
bool BinaryTree<TreeType>::_find(BNode<TreeType> *_rt, TreeType t)
{
    if (_rt == NULL)
        return false;
    if (_rt->getValue() == t)
        return true;
    if (_rt->getValue() > t) // look in the left side of the tree
        return _find(_rt->_left, t);
    //else look in the right side of the tree
    return _find(_rt->_right, t);
}

/* The goal of this method is to find the T value in the tree that comes immediately prior to
 * the node specified by _rt in the tree and return it
 * It does this by finding the right-most descendant of the node's left child
 */
template <typename TreeType>
TreeType BinaryTree<TreeType>::findPredecessor(BNode<TreeType> *_rt)
{
    // unnecessary safeguard b/c must have a left (and right) child for this method to even be called
    if (_rt->_left != NULL){
        _rt = _rt->_left;
    }
    else {
        return NULL;
    }
    
    while (_rt->_right != NULL) {
        _rt = _rt->_right;
    }
    return _rt->getValue();
}

template <typename TreeType>
void BinaryTree<TreeType>::delete_node(BNode<TreeType> *&_rt)
{
    TreeType data;
    _temp = _rt;
    // if one or fewer child nodes, simply change the pointer to the child and delete the node
    if (_rt->_left == NULL) {
        _rt = _rt->_right;
        delete _temp;
    }
    else if (_rt->_right == NULL) {
        _rt = _rt->_left;
        delete _temp;
    }
    else {
        // this is the case of deleting a node with two (both) children
        data = findPredecessor(_rt);
        _rt->setValue(data);
        _delete(_rt->_left, data);
    }
}

template <typename TreeType>
void BinaryTree<TreeType>::delete_one(TreeType t)
{
    if(_delete(_root, t) == false){
        cout << "Error: value not found" << endl;
    }
}


template <typename TreeType>
bool BinaryTree<TreeType>::_delete(BNode<TreeType> *&_rt, TreeType t)
{
    if (_rt == NULL){
        return false;
    }
    if (_rt->getValue() == t) {
        delete_node(_rt);
        return true;
    }
    if (t < _rt->getValue()) {
        // search through the left tree
        return _delete(_rt->_left, t);
    } else
        return _delete(_rt->_right, t);
}

template <typename TreeType>
void BinaryTree<TreeType>::_delete_all(BNode<TreeType> *&_rt)
{
    if (_rt->_left != NULL) {
        _delete_all(_rt->_left);
    }
    if (_rt->_right != NULL) {
        _delete_all(_rt->_right);
    }
    delete _rt;
}

template <typename TreeType>
BinaryTree<TreeType>::~BinaryTree()
{
    if (!empty()) {
        _delete_all(_root);
    }
}

#endif
