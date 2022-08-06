#include "AQueue.h"

template<typename T>
AQueue<T>::AQueue(int size) : maxSize(size+1), front(1), rear(0)
{
    listArray = new T[maxSize];
}
        
template<typename T>
AQueue<T>::~AQueue()
{
    delete[] listArray;
}

template<typename T>
void AQueue<T>::clear()
{
    front = 1;
    rear = 0;
}

template<typename T>
void AQueue<T>::enqueue(const T& itemToEnqueue)
{
    if (((rear + 2) % maxSize) == front)
    {
        std::cout << "The queue is full!" << std::endl;
        return;
    }
    rear = (rear + 1) % maxSize;
    listArray[rear] = itemToEnqueue;
}

template<typename T>
T AQueue<T>::dequeue()
{
    if (((rear + maxSize) - front + 1) % maxSize == 0)
    {
        std::cout << "The queue is empty!" << std::endl;
        return (T) 0;
    }
    T itemToReturn = listArray[front];
    front = (front + 1) % maxSize;
    return itemToReturn;
}

template<typename T>
const T& AQueue<T>::frontValue() const
{
    if (((rear + maxSize) - front + 1) % maxSize == 0)
    {
        std::cout << "The queue is empty!" << std::endl;
        return (T) 0;
    }
    return listArray[front];
}

template<typename T>
int AQueue<T>::length() const
{
    return (((rear + maxSize) - front + 1) % maxSize);
}