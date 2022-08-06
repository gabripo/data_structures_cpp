#include "../Stack/Stack.h"
#include "../Stack/Stack.cpp"
#include <iostream>

const int defaultSize = 10;

template<typename T>
class AStack : public Stack<T>
{
    private:
        int maxSize;
        int top;
        T *listArray;
    public:
        AStack(int size = defaultSize);
        ~AStack();

        void clear();
        void push(const T& itemToPush);
        T pop();
        const T& topValue() const;
        int length() const;
        void print() const;
};