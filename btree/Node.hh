#ifndef __NODE_H_INCLUDED__
#define __NODE_H_INCLUDED__

#include <memory>

template <class T>
class Node
{
    public:
        Node(T value);
        std::unique_ptr<Node<T>> left;
        std::unique_ptr<Node<T>> right;
        T value() const;
    private:
        T val;
};

template <typename T>
using NodePtr = std::unique_ptr<Node<T>>;

template <class T>
Node<T>::Node(T value)
{
    val = value;
    left = nullptr;
    right = nullptr;
}

template <class T>
T Node<T>::value() const
{
    return val;
}

#endif // __NODE_H_INCLUDED__
