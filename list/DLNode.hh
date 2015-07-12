#ifndef __DLNODE_H_INCLUDED__
#define __DLNODE_H_INCLUDED__

#include <memory>

template <class T>
class DLNode
{
    public:
        DLNode(T value);
        T value() const;
        void set_next(std::unique_ptr<DLNode<T>> &value);
        void set_prev(std::unique_ptr<DLNode<T>> &value);
    private:
        T val;
        std::unique_ptr<DLNode<T>> next;
        std::unique_ptr<DLNode<T>> previous;
};

template <typename T>
using DLNodePtr = std::unique_ptr<DLNode<T>>;

template <class T>
DLNode<T>::DLNode(T value)
{
    val = value;
    next = nullptr;
    previous = nullptr;
}

template <class T>
T DLNode<T>::value() const
{
    return val;
}

template <class T>
void DLNode<T>::set_next(std::unique_ptr<DLNode<T>> &value)
{
    next = value;
}

template <class T>
void DLNode<T>::set_prev(std::unique_ptr<DLNode<T>> &value)
{
    previous = value;
}
#endif // __DLNODE_H_INCLUDED__
