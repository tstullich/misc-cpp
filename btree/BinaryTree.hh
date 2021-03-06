#ifndef __BINARYTREE_H_INCLUDED__
#define __BINARYTREE_H_INCLUDED__

#include "BTreeNode.hh"
#include <iostream>

template <class T>
class BinaryTree 
{
    public:
        BinaryTree();
        void insert(const T value);
        void print();
        void remove(const T value);
    private:
        BTreeNodePtr<T> root;
        void insertRec(const T value, BTreeNodePtr<T> &node);
        void printRec(BTreeNodePtr<T> &node);
};

template <class T>
BinaryTree<T>::BinaryTree() 
{
    root = nullptr;
}

template <class T>
void BinaryTree<T>::insertRec(const T value, BTreeNodePtr<T> &node)
{
    // Reached an empty node. Create new one here
    if (!node)
    {
        node = std::make_unique<BTreeNode<T>>(value);
        return;
    }
    // Going to recurse left
    if (node->value() > value)
    {
        insertRec(value, node->left);
    }
    else
    {
        insertRec(value, node->right);
    }
}

template <class T>
void BinaryTree<T>::insert(const T value)
{
    if (!root)
    {
        root = std::make_unique<BTreeNode<T>>(value);
        return;
    }
    else
    {
        insertRec(value, root);
    }
}

template <class T>
void BinaryTree<T>::printRec(BTreeNodePtr<T> &node)
{
    if (!node)
    {
        return;
    }
    std::cout << node->value() << " ";
    printRec(node->left);
    printRec(node->right);
}

template <class T>
void BinaryTree<T>::print()
{
    printRec(root);
    std::cout << std::endl;
}

template <class T>
void BinaryTree<T>::remove(const T value)
{
    // TODO implement
}
#endif // __BINARYTREE_H_INCLUDED__
