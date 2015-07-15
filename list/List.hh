#ifndef __LIST_H_INCLUDED__
#define __LIST_H_INCLUDED__

#include "Node.hh"
#include <iostream>

template <class T>
class List;

template <class T>
std::ostream& operator<<(std::ostream& os, const List<T> &list);

template <class T>
class List
{
    public:
        List();
        bool contains(const T value) const;
        void insert(const T value);
        void remove(const T value);
        int size() const;
        friend std::ostream& operator<< <>(std::ostream& os, const List &list);

    private:
        int l_size;
        NodePtr<T> head;
        void insertRec(const T value, NodePtr<T> &node);
        void removeRec(const T value, NodePtr<T> &node);
};

template <class T>
List<T>::List()
{
    l_size = 0;
    head = nullptr;
}

template <class T>
bool List<T>::contains(const T value) const
{
    auto temp = head.get();
    while (temp)
    {
        if (temp->value() == value)
        {
            return true;
        }
        temp = temp->next.get();
    }
    return false; 
}

template <class T>
void List<T>::insertRec(const T value, NodePtr<T> &node)
{
    if (!node->next)
    {
        node->next = std::make_unique<Node<T>>(value);
        l_size++;
        return;
    }
    else
    {
        insertRec(value, node->next);
    }
}

template <class T>
void List<T>::insert(const T value)
{
    if (!head)
    {
        head = std::make_unique<Node<T>>(value);
        l_size++;
        return;
    }
    else
    {
        insertRec(value, head);
    }
}

template <class T>
void List<T>::removeRec(T value, NodePtr<T> &node)
{
    // If we are out of values simply return
    if (!node->next)
    {
        return;
    }
    if (node->next->value() == value)
    {
        auto temp = std::move(node->next->next);
        node->next.release();
        node->next = std::move(temp);
        l_size--;
        return;
    }
    else
    {
        removeRec(value, node->next);
    }
}

template <class T>
void List<T>::remove(T value)
{
    // If head contains the value simply remove it
    if (head->value() == value)
    {
        auto temp = std::move(head->next);
        head.release();
        head = std::move(temp);
        l_size++;
        return;
    }
    else
    {
        removeRec(value, head);
    }
}

template <class T>
int List<T>::size() const
{
    return l_size;
}

template <class T>
std::ostream& operator<<(std::ostream& os, const List<T> &list)
{
    auto temp = list.head.get();
    while (temp)
    {
        os << temp->value() << " ";
        temp = temp->next.get();
    }
    return os;
}
#endif // __LIST_H_INCLUDED__
