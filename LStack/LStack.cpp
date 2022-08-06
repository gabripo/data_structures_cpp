#include "LStack.h"

template<typename T>
LStack<T>::LStack()
{
    top = nullptr;
}

template<typename T>
LStack<T>::~LStack()
{
    clear();
}

template<typename T>
void LStack<T>::clear()
{
    while (top != nullptr)
    {
        Link<T>* tmp = top;
        top = top->next;
        delete tmp;
    }
    size = 0;
}

template<typename T>
void LStack<T>::push(const T& itemToPush)
{
    top = new Link<T>(itemToPush, top);
    size++;
}

template<typename T>
T LStack<T>::pop()
{
    if (top == nullptr)
    {
        std::cout << "Impossible to pop element, the stack is empty!" << std::endl;
        return (T) 0;
    }
    T itemToReturn = top->element;
    Link<T>* tempLink = top->next;
    delete top;
    top = tempLink;
    size--;
    return itemToReturn;
}

template<typename T>
const T& LStack<T>::topValue() const
{
    if (top == nullptr)
    {
        std::cout << "Impossible to return the top element, the stack is empty!" << std::endl;
        return (T) 0;
    }
    return top->element;
}

template<typename T>
int LStack<T>::length() const
{
    return size;
}

template<typename T>
void LStack<T>::print() const
{
    std::cout << "Printing stack: " << std::endl;
    Link<T>* tempLink = top;
    std::cout << "[ ";
    while (tempLink != nullptr)
    {
        std::cout << tempLink->element << " ";
        tempLink = tempLink->next;
    }
    std::cout << "]" << std::endl;
}