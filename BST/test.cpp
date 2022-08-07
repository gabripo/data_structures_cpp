#include "BST.cpp"
#include <iostream>

int main(int argc, char const *argv[])
{
    BST<char, int> bst;

    bst.print();
    std::cout << "-------" << std::endl;

    bst.insert('a', 10);
    bst.insert('b', 100);
    bst.insert('c', 20);
    bst.print();
    std::cout << "-------" << std::endl;

    bst.remove('b');
    bst.print();
    std::cout << "-------" << std::endl;

    bst.remove('a');
    bst.print();
    std::cout << "-------" << std::endl;

    return 0;
}