#ifndef __BTREENODE_H_INCLUDED__
#define __BTREENODE_H_INCLUDED__

#include <memory>

template <class T>
class BTreeNode
{
    public:
        BTreeNode(T value);
        std::unique_ptr<BTreeNode<T>> left;
        std::unique_ptr<BTreeNode<T>> right;
        T value() const;
    private:
        T val;
};

template <typename T>
using BTreeNodePtr = std::unique_ptr<BTreeNode<T>>;

template <class T>
BTreeNode<T>::BTreeNode(T value)
{
    val = value;
    left = nullptr;
    right = nullptr;
}

template <class T>
T BTreeNode<T>::value() const
{
    return val;
}

#endif // __NODE_H_INCLUDED__
