#include "Heap.cpp"
#include "MaxOperator.cpp"
#include <iostream>

const int maximumSize = 10;

int main(int argc, char const *argv[])
{
    int array[] = { 4, 10, 1, 2, 0 };
    int arraySize = sizeof(array) / sizeof(array[0]);

    Heap<int, MaxOperator<int> > maxHeap(array, arraySize, maximumSize);
    maxHeap.print();

    return 0;
}
