#include "LinkedList.cpp"

int main(int argc, char const *argv[])
{
    LinkedList<int> l0;
    l0.print();
    std::cout << "--------------------" << std::endl;

    LinkedList<int> l1(5);
    l1.print();
    std::cout << "-" << std::endl;
    l0 = l1;
    l0.print();
    std::cout << "--------------------" << std::endl;

    LinkedList<int> l2 = l0;
    l2.print();
    std::cout << "--------------------" << std::endl;

    l2.clear();
    l2.print();
    std::cout << "--------------------" << std::endl;

    l2.replace("(null)", "newValue", 6);
    l2.print();
    std::cout << "-" << std::endl;
    l2.replace("(null)", "newValueToNotBeInserted", 5);
    l2.print();
    std::cout << "--------------------" << std::endl;

    l2.insert("freshNewValue", 1000);
    l2.print();
    std::cout << "--------------------" << std::endl;

    int fetchedValue1 = l2.fetch("newValue");
    std::cout << "Fetched value 1: " << fetchedValue1 << std::endl;
    std::cout << "-" << std::endl;
    int fetchedValue2 = l2.fetch("freshNewValue");
    std::cout << "Fetched value 2: " << fetchedValue2 << std::endl;
    std::cout << "--------------------" << std::endl;

    return 0;
}