#include <iostream>
#include "list/List.hh"
#include "btree/BinaryTree.hh"

int main() {
    List<int> l;
    for (int i = 1; i <= 100; i++) 
    {
        l.insert(i);
    }
    
    l.print();

    if (l.contains(20)) 
    {
        std::cout << "List contains 20" << std::endl;
    }

    for (int j = 10; j <= 100; j += 10) 
    {
        l.remove(j);
    }

    l.print();
    
    if (!l.contains(20))
    {
        std::cout << "List does NOT contain 20" << std::endl;
    }

    l.insert(20);
    l.print();
    
    if (l.contains(20))
    {
        std::cout << "List contains 20" << std::endl;
    }

    BinaryTree<int> tree;
    tree.insert(1);
    tree.insert(2);

    tree.print();
	return 0;
}
