// FIFO (first-in, first-out) implementation of queue
#include <iostream>

template <typename T>
class Queue
{
    private:
        size_t size;
        T* data;
    public:
        Queue();
        Queue(size_t input_size);
        Queue(const Queue& original); // Copy constructor
        Queue<T>& operator=(const Queue<T>& rhs); // Assignment operator

        T front();
        T rear();
        bool empty();
        void enqueue(T elementToEnqueue);
        T dequeue();
        size_t getSize();
        void print();

        ~Queue();
};