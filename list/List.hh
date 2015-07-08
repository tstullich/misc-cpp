#ifndef __LIST_H_INCLUDED__
#define __LIST_H_INCLUDED__

#include "Node.hh"
#include <iostream>

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
    auto temp = head.get();
    while (temp != nullptr)
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
List<T>::List()
{
    head = nullptr;
}

template <class T>
void List<T>::insertRec(T value, NodePtr<T> &node)
{
    if (node->next == nullptr)
    {
        auto newNode = std::make_unique<Node<T>>(value);
        node->next = std::move(newNode);
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
        head = std::make_unique<Node<T>>(value);
        return;
    }
    else
    {
        insertRec(value, head);
    }
}

template <class T>
void List<T>::print() const
{
    auto temp = head.get();
    while (temp != nullptr)
    {
        std::cout << temp->value() << " ";
        temp = temp->next.get();
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
        auto temp = std::move(node->next->next);
        node->next.release();
        node->next = std::move(temp);
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
        return;
    }
    else
    {
        removeRec(value, head);
    }
}

#endif // __LIST_H_INCLUDED__
