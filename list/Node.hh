#ifndef __NODE_H_INCLUDED__
#define __NODE_H_INCLUDED__

template <class T>
class Node
{
    public:
        Node(T value);
        std::shared_ptr<Node<T>> next;
        T value() const;
    private:
        T val;
};

template <typename T>
using NodePtr = std::shared_ptr<Node<T>>;

template <class T>
Node<T>::Node(T value)
{
    val = value;
    next = nullptr;
}

template <class T>
T Node<T>::value() const
{
    return val;
}

#endif // __NODE_H_INCLUDED__
