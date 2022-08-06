// LIFO (last-in, first-out) implementation of stack
#include <iostream>

#pragma once
template <typename T>
class Stack
{
    private:
        size_t size;
        T* data;
        size_t currentPosition;
    public:
        Stack();
        Stack(size_t input_size);
        Stack(const Stack& original); // Copy constructor
        Stack<T>& operator=(const Stack<T>& rhs); // Assignment operator

        T top();
        bool empty();
        bool full();
        size_t getSize();
        size_t getCurrentPosition();
        void push(T elementToPush);
        T pop();
        void swap(Stack& otherToSwapWith);
        void print();

        ~Stack();
};