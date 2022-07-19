#include "AList.cpp"

int main(int argc, char const *argv[])
{
    AList<int> list;

    std::cout << "List length: " << list.length() << std::endl;
    std::cout << "Current value: " << list.getValue() << std::endl;

    list.clear();
    list.append(10);
    list.append(11);
    list.print();
    std::cout << "List length: " << list.length() << std::endl;
    std::cout << "Current value: " << list.getValue() << std::endl;

    list.moveToEnd();
    list.insert(1);
    list.append(2);
    list.print();
    std::cout << "List length: " << list.length() << std::endl;
    std::cout << "Current value: " << list.getValue() << std::endl;
    
    list.moveToStart();
    list.print();
    std::cout << "List length: " << list.length() << std::endl;
    std::cout << "Current value: " << list.getValue() << std::endl;
    
    list.moveToEnd();
    list.print();
    std::cout << "List length: " << list.length() << std::endl;
    std::cout << "Current value: " << list.getValue() << std::endl;

    list.moveToEnd();
    list.next();
    std::cout << "Current position: " << list.currentPos() << std::endl;

    list.moveToStart();
    list.prev();
    std::cout << "Current position: " << list.currentPos() << std::endl;

    list.clear();
    list.remove();
    list.print();
    std::cout << "List length: " << list.length() << std::endl;
    std::cout << "Current position: " << list.currentPos() << std::endl;
    std::cout << "Current value: " << list.getValue() << std::endl;

    list.moveToPos(2);
    list.insert(10);
    list.insert(11);
    list.insert(13);
    list.moveToPos(2);
    list.print();

    return 0;
}