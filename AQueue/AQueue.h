#include "../Queue/Queue.cpp"
#include <iostream>

const int defaultSize = 10;

template<typename T>
class AQueue : public Queue<T>
{
    private:
        int maxSize;
        int front;
        int rear;
        T* listArray;
    public:
        AQueue(int size = defaultSize);
        ~AQueue();

        void clear();
        void enqueue(const T& itemToEnqueue);
        T dequeue();
        const T& frontValue() const;
        virtual int length() const;
};