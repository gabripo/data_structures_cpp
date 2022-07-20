#include "LList.cpp"

int main(int argc, char const *argv[])
{
    LList<int> list;
    list.print();
    std::cout << "List length: " << list.length() << std::endl;
    std::cout << "Current value: " << list.getValue() << std::endl;
    std::cout << "Current position: " << list.currentPos() << std::endl;
    std::cout << "-----------" << std::endl;

    return 0;
}
