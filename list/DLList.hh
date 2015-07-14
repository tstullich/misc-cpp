#ifndef __DLLLIST_H_INCLUDED__
#define __DLLLIST_H_INCLUDED__

#include "DLNode.hh"
#include <iostream>

template <class T>
class DLList;

template <class T>
std::ostream& operator<<(std::ostream& os, const DLList<T> &list);

template <class T>
class DLList
{
    public:
        DLList();
        DLList(const T &value);
        const DLNode<T>* back() const;
        bool contains(const T &value) const;
        const DLNodePtr<T> front() const;
        void insert(const T &value);
        void insert_back(const T &value);
        void insert_front(const T &value);
        void remove(const T &value);
        int size() const;
        friend std::ostream& operator<< <>(std::ostream& os, const DLList &list);

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
    head = std::make_unique<DLNode<T>>(value);
    head = std::make_unique<DLNode<T>>();
    tail->set_prev(head);
}

template <class T>
const DLNode<T>* DLList<T>::back() const
{
    if (!tail)
    {
        return head.get();
    }
    return tail->get_previous();
}

template <class T>
bool DLList<T>::contains(const T &value) const
{
    auto temp = head.get();
    while (temp)
    {
        if (temp->value() == value)
        {
            return true;
        }
        temp = temp->get_next().get();
    }
    return false;
}

template <class T>
const DLNodePtr<T> DLList<T>::front() const
{
    return head;
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
        head = std::make_unique<DLNode<T>>(value);
        tail = std::make_unique<DLNode<T>>();
        tail->set_previous(head.get());
        l_size++;
    }
    else
    {
        auto prev = tail->get_previous();
        auto owning_ptr = std::make_unique<DLNode<T>>(value);
        prev->set_next(owning_ptr);
        auto new_node = std::make_unique<DLNode<T>>();
        new_node->set_previous(prev->get_next().get());
        tail.release();
        tail = std::move(new_node);
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
void DLList<T>::remove(const T &value)
{
    auto temp = head;
    while (temp)
    {
        if (temp->value() == value)
        {
            // TODO need to do removal here
        }
        temp = temp->get_next();
    }
}

template <class T>
int DLList<T>::size() const
{
    return l_size;
}

template <class T>
std::ostream& operator<<(std::ostream& os, const DLList<T> &list)
{
    auto temp = list.head.get();
    while (temp)
    {
        os << temp->value() << " ";
        temp = temp->get_next().get();
    }
    return os;
}

#endif // __DLLLIST_H_INCLUDED__
