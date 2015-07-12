#ifndef __DLLLIST_H_INCLUDED__
#define __DLLLIST_H_INCLUDED__

#include "DLNode.hh"
#include <iostream>

template <class T>
class DLList
{
    public:
        DLList();
        DLList(const T &value);
        bool contains(const T &value) const;
        const DLNodePtr<T> front() const;
        void insert(const T &value);
        void insert_back(const T &value);
        void insert_front(const T &value);
        void print() const;
        void remove(const T &value);
        int size() const;

    private:
        int l_size;
        DLNodePtr<T> head;
        DLNodePtr<T> tail;
};

template <class T>
DLList<T>::DLList()
{
    l_size = 0;
    head = nullptr;
    tail = nullptr;
}

template <class T>
DLList<T>::DLList(const T &value)
{
    l_size = 1;
    head = std::make_shared<DLNode<T>>(value);
    tail = head;
}

template <class T>
bool DLList<T>::contains(const T &value) const
{
    auto temp = head;
    while (temp)
    {
        if (temp->value() == value)
        {
            return true;
        }
        temp = temp->get_next();
    }
    return false;
}

template <class T>
void DLList<T>::insert(const T &value)
{
    insert_back(value);
}

template <class T>
void DLList<T>::insert_back(const T &value)
{
    if ((head == nullptr) && (tail == nullptr))
    {
        head = std::make_shared<DLNode<T>>(value);
        tail = head;
        l_size++;
    }
    else
    {
        auto new_node = std::make_shared<DLNode<T>>(value);
        new_node->set_prev(tail);
        tail->set_next(new_node);
        tail = new_node;
        l_size++;
    }
}

template <class T>
void DLList<T>::insert_front(const T &value)
{
    if ((head == nullptr) && (tail == nullptr))
    {
        head = std::make_shared<DLNode<T>>(value);
        tail = head;
        l_size = 1;
    }
    else
    {
        auto new_node = std::make_shared<DLNode<T>>(value);
        new_node->set_next(head);
        head->set_prev(new_node);
        head = new_node;
        l_size++;
    }
}

template <class T>
int DLList<T>::size() const
{
    return l_size;
}

#endif // __DLLLIST_H_INCLUDED__
