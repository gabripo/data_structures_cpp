#ifndef CUSTOM_QUEUE
#define CUSTOM_QUEUE

template<typename T>
class Queue
{
    private:
        void operator=(const Queue&);
        Queue(const Queue&);
    public:
        Queue();
        virtual ~Queue();

        virtual void clear() = 0;
        virtual void enqueue() = 0;
        virtual void dequeue() = 0;
        virtual const T& frontValue() = 0;
        virtual int length() const = 0;
};

#endif