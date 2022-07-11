// LIFO (last-in, first-out) implementation of stack
#include "Stack.h"

template <typename T>
Stack<T>::Stack() : size(1), currentPosition(0)
{
    std::cout << "Default constructor for an empty stack called: default size is 1." << std::endl;
    this->data = new T;
}

template <typename T>
Stack<T>::Stack(size_t input_size) : size(input_size), currentPosition(1)
{
    if (size == 0)
    {
        std::cout << "A 1-element stack will be created, as 0 was the input." << std::endl;
        this->size = 1;
        this->data = new T;
    }
    else
    {
        std::cout << "Stack with " << size << " elements will be created." << std::endl;
        this->data = new T[size];
    };
}

template <typename T>
Stack<T>::Stack(const Stack &original)
{
    std::cout << "Copy of ctor of Stack called..." << std::endl;
    // 1. Copy the non-pointer members
    this->size = original.size;
    this->currentPosition = original.currentPosition;
    // 2. Allocate a new heap memory segment
    this->data = new T[this->size];
    // 3. Copy from original heap memory to the new heap memory segment
    for (size_t idxData = 0; idxData < this->size; idxData++)
    {
        this->data[idxData] = original.data[idxData];
    }
}

template <typename T>
Stack<T> &Stack<T>::operator=(const Stack &rhs)
{
    std::cout << "Assignment operator of Stack called..." << std::endl;
    if (this != &rhs)
    {
        // 1. Delete the heap memory segment of the left-hand-side operand
        delete[] this->data;
        // 2. Copy the non-pointer members
        this->size = rhs.size;
        this->currentPosition = rhs.currentPosition;
        // 3. Allocate memory for the left-hand-side and copy content
        this->data = new T[this->size];
        for (size_t idxData = 0; idxData < this->size; idxData++)
        {
            this->data[idxData] = rhs.data[idxData];
        }
    }
    // Return a reference to the left-hand-side - Needed for operator concatenation (chain of equalities)
    return *this;
}

template <typename T>
T Stack<T>::top()
{
    if (Stack<T>::empty())
    {
        std::cout << "Impossible to get the top element, the stack is empty!" << std::cout;
    }
    else
    {
        return this->data[this->currentPosition];
    }
}

template <typename T>
bool Stack<T>::empty()
{
    return (this->currentPosition == 0);
}

template <typename T>
bool Stack<T>::full()
{
    return (this->currentPosition == this->size);
}

template <typename T>
size_t Stack<T>::getSize()
{
    return (sizeof(*this->data) / sizeof(T));
}

template <typename T>
size_t Stack<T>::getCurrentPosition()
{
    return this->currentPosition;
}

template <typename T>
void Stack<T>::push(T elementToPush)
{
    if (this->full())
    {
        std::cout << "Impossible to push element, the stack is full!" << std::endl;
    }
    else
    {
        this->data[this->currentPosition + 1] = elementToPush;
        this->currentPosition++;
        std::cout << "Element " << elementToPush << " added to the stack at position " << this->currentPosition << "." << std::endl;
    }
}

template <typename T>
T Stack<T>::pop()
{
    if (this->empty())
    {
        std::cout << "Stack is empty, impossible to pop out elements!" << std::endl;
        return (T) NULL;
    }
    else
    {
        T currValue = this->data[this->currentPosition];
        this->data[this->currentPosition] = (T) NULL;
        this->currentPosition--;
        return currValue;
    }
}

template <typename T>
void Stack<T>::swap(Stack<T> &otherToSwapWith)
{
    Stack<T> tempStack = otherToSwapWith;
    otherToSwapWith = *this;
    *this = tempStack;
}

template <typename T>
void Stack<T>::print()
{
    std::cout << "Printing..." << std::endl;
    if (!this->empty())
    {
        for (size_t i = 1; i <= this->size; i++)
        {
            if (this->currentPosition == i)
            {
                std::cout << this->data[i] << " <-" << std::endl;
            }
            else
            {
                std::cout << this->data[i] << std::endl;
            }
        }
    }
    else
    {
        std::cout << "Stack is empty, impossible to print!" << std::endl;
    }
    std::cout << "Printing done." << std::endl;
}

template <typename T>
Stack<T>::~Stack()
{
    std::cout << "Destructor called..." << std::endl;
    delete[] this->data;
}