#ifndef __DLNODE_H_INCLUDED__
#define __DLNODE_H_INCLUDED__

#include <memory>

template <class T>
class DLNode
{
    public:
        DLNode();
        DLNode(T value);
        T value() const;
        std::unique_ptr<DLNode<T>>& get_next();
        DLNode<T>* get_previous();
        void set_next(std::unique_ptr<DLNode<T>> &value);
        void set_previous(DLNode<T>* value);
        void set_value(const T &value);

    private:
        T val;
        std::unique_ptr<DLNode<T>> next;
        DLNode<T> *previous;
};

template <typename T>
using DLNodePtr = std::unique_ptr<DLNode<T>>;

template <typename T>
using DLNodeObsPtr = std::shared_ptr<DLNode<T>>;

template <class T>
DLNode<T>::DLNode()
{
    val = -1;
    next = nullptr;
    previous = nullptr;
}

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
std::unique_ptr<DLNode<T>>& DLNode<T>::get_next()
{
    return next;
}

template <class T>
DLNode<T>* DLNode<T>::get_previous()
{
    return previous;
}

template <class T>
void DLNode<T>::set_next(std::unique_ptr<DLNode<T>> &value)
{
    next = std::move(value);
}

template <class T>
void DLNode<T>::set_previous(DLNode<T>* value)
{
    previous = value;
}

template <class T>
void DLNode<T>::set_value(const T &value)
{
    val = value;
}

#endif // __DLNODE_H_INCLUDED__
