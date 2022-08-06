#ifndef CUSTOM_STACK
#define CUSTOM_STACK

template<typename T>
class Stack
{
    private:
        void operator=(const Stack&);
        Stack(const Stack&);
    public:
        Stack();
        virtual ~Stack();

        virtual void clear() = 0;
        virtual void push(const T& itemToPush) = 0;
        virtual T pop() = 0;
        virtual const T& topValue() const = 0;
        virtual int length() const = 0;
};

#endif