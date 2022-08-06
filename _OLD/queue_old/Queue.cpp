#include "Queue.h"

template <typename T>
Queue<T>::Queue() : size(0)
{
    std::cout << "Default constructor is called: queue of 0 element." << std::endl;
    this->data = new T[1];
}

template <typename T>
Queue<T>::Queue(size_t input_size) : size(input_size)
{
    if (input_size == 0)
    {
        std::cout << "Invalid input size 0 . A queue of 1 element will be created instead." << std::endl;
        this->size = 1;
    }

    std::cout << "Constructor called: a queue of initial size " << this->size << " will be created." << std::endl;
    this->data = new T[this->size];
}

template <typename T>
Queue<T>::Queue(const Queue &original)
{
    std::cout << "Copy of ctor of Queue called..." << std::endl;
    // 1. Copy the non-pointer members
    this->size = original.size;
    // 2. Allocate a new heap memory segment
    this->data = new T[this->size];
    // 3. Copy from original heap memory to the new heap memory segment
    for (size_t idxData = 0; idxData < this->size; idxData++)
    {
        this->data[idxData] = original.data[idxData];
    }
}

template <typename T>
Queue<T> &Queue<T>::operator=(const Queue<T> &rhs)
{
    std::cout << "Assignment operator of Queue called..." << std::endl;
    if (this != &rhs)
    {
        // 1. Delete the heap memory segment of the left-hand-side operand
        delete[] this->data;
        // 2. Copy the non-pointer members
        this->size = rhs.size;
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
T Queue<T>::front()
{
    return this->data[this->size-1];
}

template <typename T>
T Queue<T>::rear()
{
    return this->data[0];
}

template <typename T>
bool Queue<T>::empty()
{
    return (this->getSize() == 0);
}

template <typename T>
void Queue<T>::enqueue(T elementToEnqueue)
{
    T *oldQueueData = new T[this->size];
    for (size_t idxCurrentData = 0; idxCurrentData < this->size; idxCurrentData++)
    {
        oldQueueData[idxCurrentData] = this->data[idxCurrentData];
    }
    delete[] this->data;
    this->data = new T[this->size + 1];
    this->data[0] = elementToEnqueue;
    for (size_t idxOldQueueData = 0; idxOldQueueData < this->size; idxOldQueueData++)
    {
        this->data[idxOldQueueData + 1] = oldQueueData[idxOldQueueData];
    }
    this->size++;
    std::cout << "Element added to the queue. New size is " << this->size << std::endl;
}

template <typename T>
T Queue<T>::dequeue()
{
    if (this->empty())
    {
        std::cout << "Queue is empty, impossible to dequeue elements!" << std::endl;
        return (T) NULL;
    }
    else
    {
        T *oldQueueData = new T[this->size];
        for (size_t idxCurrentData = 0; idxCurrentData < this->size; idxCurrentData++)
        {
            oldQueueData[idxCurrentData] = this->data[idxCurrentData];
        }
        delete[] this->data;
        T elementToReturn = oldQueueData[this->size - 1];
        this->data = new T[this->size - 1];
        for (size_t idxOldQueueData = 0; idxOldQueueData < this->size - 1; idxOldQueueData++)
        {
            this->data[idxOldQueueData] = oldQueueData[idxOldQueueData];
        }
        this->size--;
        std::cout << "Element removed from the queue. New size is " << this->size << std::endl;
        return elementToReturn;
    }
}

template <typename T>
size_t Queue<T>::getSize()
{
    return sizeof(*(this->data)) / sizeof(T);
}

template <typename T>
void Queue<T>::print()
{
    std::cout << "Printing queue..." << std::endl;
    if (this->empty())
    {
        std::cout << "Queue is empty, nothing to print!" << std::endl;
    }
    else
    {
        for (size_t i = 0; i < this->size; i++)
        {
            std::cout << this->data[i] << std::endl;
        }
    }
    std::cout << "Printing done." << std::endl;
}

template <typename T>
Queue<T>::~Queue()
{
    std::cout << "Destructor is called..." << std::endl;
    delete[] this->data;
}