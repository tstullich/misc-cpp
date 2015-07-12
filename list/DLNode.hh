#ifndef __DLNODE_H_INCLUDED__
#define __DLNODE_H_INCLUDED__

#include <memory>

template <class T>
class DLNode
{
    public:
        DLNode(T value);
        T value() const;
        std::shared_ptr<DLNode<T>> get_next();
        std::shared_ptr<DLNode<T>> get_previous();
        void set_next(std::shared_ptr<DLNode<T>> &value);
        void set_prev(std::shared_ptr<DLNode<T>> &value);
        void set_value(const T &value);

    private:
        T val;
        std::shared_ptr<DLNode<T>> next;
        std::shared_ptr<DLNode<T>> previous;
};

template <typename T>
using DLNodePtr = std::shared_ptr<DLNode<T>>;

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
std::shared_ptr<DLNode<T>> DLNode<T>::get_next()
{
    return next;
}

template <class T>
std::shared_ptr<DLNode<T>> DLNode<T>::get_previous()
{
    return previous;
}

template <class T>
void DLNode<T>::set_next(std::shared_ptr<DLNode<T>> &value)
{
    next = value;
}

template <class T>
void DLNode<T>::set_prev(std::shared_ptr<DLNode<T>> &value)
{
    previous = value;
}

template <class T>
void DLNode<T>::set_value(const T &value)
{
    val = value;
}

#endif // __DLNODE_H_INCLUDED__
