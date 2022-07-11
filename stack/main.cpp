#include "Stack.cpp"
#include <iostream>

int main()
{
    Stack<int> s0;
    if (s0.empty())
    {
        std::cout << "The stack is empty." << std::endl;
    }
    s0.pop();
    s0.print();
    std::cout << "--------------------" << std::endl;

    Stack<int> sNull(0);
    sNull.print();
    std::cout << "--------------------" << std::endl;

    Stack<int> s1(5);
    std::cout << "Size " << s1.getSize() << " and current position " << s1.getCurrentPosition() << std::endl;
    s1.print();
    std::cout << "--------------------" << std::endl;

    s1.push(10);
    s1.push(5);
    std::cout << "Size " << s1.getSize() << " and current position " << s1.getCurrentPosition() << std::endl;
    s1.print();
    std::cout << "--------------------" << std::endl;

    s1.push(10);
    s1.push(5);
    s1.push(10);
    s1.push(5);
    s1.print();
    std::cout << "--------------------" << std::endl;

    int poppedElemend = s1.pop();
    std::cout << "Popped element is " << poppedElemend << std::endl;
    s1.print();
    std::cout << "--------------------" << std::endl;

    s1.swap(s0);
    if (!s0.empty() && s1.empty())
    {
        std::cout << "The stack has been swapped successfully." << std::endl;
    }
    s0.print();
    s1.print();

    return 0;
}
