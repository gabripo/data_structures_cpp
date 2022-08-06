#include "../Queue/Queue.cpp"
#include "../Link/Link.cpp"
#include <iostream>

template<typename T>
class LQueue : public Queue<T>
{
    private:
        Link<T>* front;
        Link<T>* rear;
        int size;
    public:
        LQueue();
        ~LQueue();

        void clear();
        void enqueue(const T& itemToEnqueue);
        T dequeue();
        const T& frontValue() const;
        virtual int length() const;
};