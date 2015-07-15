#include <iostream>
#include "list/List.hh"
#include "list/DLList.hh"
#include "btree/BinaryTree.hh"
#include "stack/Stack.hh"

void testList()
{
    List<int> l;
    for (int i = 1; i <= 30; i++)
    {
        l.insert(i);
        if (i % 5 == 0)
        {
            std::cout << "List Size: " << l.size() << std::endl;
        }
    }
    
    std::cout << l << std::endl;

    if (l.contains(20))
    {
        std::cout << "List contains 20" << std::endl;
        std::cout << "List Size: " << l.size() << std::endl;
    }

    for (int j = 10; j <= 30; j += 10)
    {
        l.remove(j);
    }

    std::cout << l << std::endl;
    
    if (!l.contains(20))
    {
        std::cout << "List does NOT contain 20" << std::endl;
        std::cout << "List Size: " << l.size() << std::endl;
    }

    l.insert(20);
    std::cout << l << std::endl;
    
    if (l.contains(20))
    {
        std::cout << "List contains 20" << std::endl;
        std::cout << "List Size: " << l.size() << std::endl;
    }
}

void testBTree()
{
    BinaryTree<int> tree;
    tree.insert(5);
    tree.insert(1);
    tree.insert(2);
    tree.insert(8);
    tree.insert(9);
    tree.print();
}

void testDLList()
{
    DLList<int> list;
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(4);
    if (list.contains(3))
    {
        std::cout << "Linked List contains 1" << std::endl;
    }
    std::cout << list << std::endl;
    list.insert_front(7);
    std::cout << list << std::endl;
    std::cout << "List size: " << list.size() << std::endl;
}

int main() {
    testList();
    testBTree();
    testDLList();

	return 0;
}
