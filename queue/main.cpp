#include "Queue.cpp"

int main(int argc, char const *argv[])
{
    Queue<int> q;
    q.print();
    std::cout << "--------------------" << std::endl;

    q.enqueue(10);
    q.enqueue(5);
    q.enqueue(20);
    q.print();
    std::cout << "--------------------" << std::endl;

    int dequeuedElement = q.dequeue();
    std::cout << "Element " << dequeuedElement << " has been dequeued." << std::endl;
    q.print();
    std::cout << "--------------------" << std::endl;

    int frontElement = q.front();
    int rearElement = q.rear();
    std::cout << "Front element is " << frontElement << " and rear element is " << rearElement << std::endl;
    std::cout << "--------------------" << std::endl;

    Queue<int> q1(5);
    q1.print();
    q1 = q;
    q1.print();
    std::cout << "--------------------" << std::endl;

    return 0;
}
