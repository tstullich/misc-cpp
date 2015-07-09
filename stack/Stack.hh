#ifndef __STACK_H_INCLUDED__
#define __STACK_H_INCLUDED__

#include <memory>

template <class T>
class Stack
{
    public:
        Stack();
    private:
        int size;
        std::unique_ptr<Stack<T>> head; // TODO This doesn't work
        std::unique_ptr<Stack<T>> tail; // TODO This doesn't work
};

template <typename T>
using StackPtr = std::unique_ptr<Stack<T>>;

template <class T>
Stack<T>::Stack()
{
    size = 0;
    head = nullptr;
    tail = nullptr;
}

#endif // __STACK_H_INCLUDED__
