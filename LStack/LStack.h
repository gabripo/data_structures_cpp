#include "../Stack/Stack.cpp"
#include "../Link/Link.cpp"
#include <iostream>

template<typename T>
class LStack : public Stack<T>
{
    private:
        Link<T>* top;
        int size;
    public:
        LStack();
        ~LStack();

        void clear();
        void push(const T& itemToPush);
        T pop();
        const T& topValue() const;
        int length() const;
        void print() const;
};