#include "AStack.cpp"

int main(int argc, char const *argv[])
{
    AStack<int> s;
    s.print();
    std::cout << "------------------" << std::endl;

    s.push(10);
    s.print();
    std::cout << "------------------" << std::endl;

    s.pop();
    s.print();
    std::cout << "------------------" << std::endl;

    s.push(100);
    s.push(5);
    s.print();
    std::cout << "Top element: " << s.topValue() << std::endl;
    std::cout << "Popped element: " << s.pop() <<std::endl;
    std::cout << "Top element: " << s.topValue() << std::endl;
    std::cout << "------------------" << std::endl;

    s.clear();
    s.print();
    std::cout << "------------------" << std::endl;

    

    return 0;
}
