#ifndef __LIST_H_INCLUDED__
#define __LIST_H_INCLUDED__

#include <iostream>
#include "Node.hh"

template <class T>
class List
{
    public:
        List();
        bool contains(const T value) const;
        void insert(const T value);
        void print() const;
        void remove(const T value);

    private:
        NodePtr<T> head;
        void insertRec(const T value, NodePtr<T> &node);
        void removeRec(const T value, NodePtr<T> &node);
};

template <class T>
bool List<T>::contains(const T value) const
{
    NodePtr<T> temp = head;
    while (temp != nullptr)
    {
        if (temp->value() == value)
        {
            return true;
        }
        temp = temp->next;
    }
    return false; 
}

template <class T>
List<T>::List()
{
    head = nullptr;
}

template <class T>
void List<T>::insertRec(T value, NodePtr<T> &node)
{
    if (node->next == nullptr)
    {
        auto newNode = std::make_shared<Node<T>>(value);
        node->next = newNode;
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
    if (head == nullptr)
    {
        head = std::make_shared<Node<T>>(value);
        return;
    }
    else
    {
        NodePtr<T> temp = head;
        insertRec(value, temp);
    }
}

template <class T>
void List<T>::print() const
{
    NodePtr<T> temp = head;
    while (temp != nullptr)
    {
        std::cout << temp->value() << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

template <class T>
void List<T>::removeRec(T value, NodePtr<T> &node)
{
    // If we are out of values simply return
    if (node->next == nullptr)
    {
        return;
    }
    if (node->next->value() == value)
    {
        node->next = node->next->next;
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
        head = head->next;
        return;
    }
    else
    {
        NodePtr<T> temp = head;
        removeRec(value, temp);
    }
}

#endif // __LIST_H_INCLUDED__
