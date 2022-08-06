#include "LQueue.h"

template<typename T>
LQueue<T>::LQueue() : size(0)
{
    front = new Link<T>();
    rear = front;
}

template<typename T>
LQueue<T>::~LQueue()
{
    clear();
    delete front();
}

template<typename T>
void LQueue<T>::clear()
{
    while (front->next == nullptr)
    {
        rear = front;
        delete rear;
    }
    rear = front;
    size = 0;
}

template<typename T>
void LQueue<T>::enqueue(const T& itemToEnqueue)
{
    rear->next = new Link<T>(itemToEnqueue, nullptr);
    rear = rear->next;
    size++;
}

template<typename T>
T LQueue<T>::dequeue()
{
    if (size == 0)
    {
        std::cout << "Impossible to dequeue, the queue is empty!" << std::endl;
        return (T) 0;
    }
    T itemToReturn = front->next->element;
    Link<T>* tempLink = front->next;
    front->next = tempLink->next;
    if (rear == tempLink)
    {
        rear = front;
    }
    delete tempLink;
    size--;
    return itemToReturn;
}

template<typename T>
const T& LQueue<T>::frontValue() const
{
    if (size == 0)
    {
        std::cout << "Impossible to dequeue, the queue is empty!" << std::endl;
        return (T) 0;
    }
    return front->next->element;
}

template<typename T>
int LQueue<T>::length() const
{
    return size;
}