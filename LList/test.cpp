#include "LList.cpp"

int main(int argc, char const *argv[])
{
    LList<int> list;
    list.print();
    std::cout << "List length: " << list.length() << std::endl;
    std::cout << "Current value: " << list.getValue() << std::endl;
    std::cout << "Current position: " << list.currentPos() << std::endl;
    std::cout << "-----------" << std::endl;

    list.append(10);
    list.append(11);
    list.print();
    std::cout << "List length: " << list.length() << std::endl;
    std::cout << "Current value: " << list.getValue() << std::endl;
    std::cout << "Current position: " << list.currentPos() << std::endl;
    std::cout << "-----------" << std::endl;

    list.insert(0);
    list.insert(1);
    list.print();
    std::cout << "List length: " << list.length() << std::endl;
    std::cout << "Current value: " << list.getValue() << std::endl;
    std::cout << "Current position: " << list.currentPos() << std::endl;
    std::cout << "-----------" << std::endl;

    list.moveToEnd();
    list.print();
    std::cout << "List length: " << list.length() << std::endl;
    std::cout << "Current value: " << list.getValue() << std::endl;
    std::cout << "Current position: " << list.currentPos() << std::endl;
    std::cout << "-----------" << std::endl;

    list.moveToStart();
    list.print();
    std::cout << "List length: " << list.length() << std::endl;
    std::cout << "Current value: " << list.getValue() << std::endl;
    std::cout << "Current position: " << list.currentPos() << std::endl;
    std::cout << "-----------" << std::endl;

    list.moveToPos(2);
    list.print();
    std::cout << "List length: " << list.length() << std::endl;
    std::cout << "Current value: " << list.getValue() << std::endl;
    std::cout << "Current position: " << list.currentPos() << std::endl;
    std::cout << "-----------" << std::endl;

    return 0;
}
