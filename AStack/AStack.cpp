#include "AStack.h"

template<typename T>
AStack<T>::AStack(int size) : maxSize(size), top(0)
{
    listArray = new T[maxSize];
}

template<typename T>
AStack<T>::~AStack()
{
    delete[] listArray;
}

template<typename T>
void AStack<T>::clear()
{
    top = 0;
}

template<typename T>
void AStack<T>::push(const T& itemToPush)
{
    if (top >= maxSize)
    {
        std::cout << "Impossible to push element, the stack is full!" << std::endl;
        return;
    }
    listArray[top++] = itemToPush;
}

template<typename T>
T AStack<T>::pop()
{
    if (top == 0)
    {
        std::cout << "Impossible to pop element, the stack is empty!" << std::endl;
        return (T) 0;
    }
    return listArray[--top];
}

template<typename T>
const T& AStack<T>::topValue() const
{
    if (top == 0)
    {
        std::cout << "Impossible to return the top element, the stack is empty!" << std::endl;
        return (T) 0;
    }
    return listArray[top-1];
}

template<typename T>
int AStack<T>::length() const
{
    return top;
}

template<typename T>
void AStack<T>::print() const
{
    std::cout << "Printing stack:" << std::endl;
    if (top == 0)
    {
        std::cout << "Impossible to print the stack since it is empty!" << std::endl;
        return;
    }
    std::cout << "[ ";
    for (int i = 0; i < top; i++)
    {
        std::cout << listArray[i] << " ";
    }
    std::cout << "]" << std::endl;
}