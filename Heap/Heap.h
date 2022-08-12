#include <iostream>

template<typename T, typename Comparator>
class Heap {
    private:
        T* heapArray;
        int numElements;
        int maxSize;
        void siftdown(int nodePosition);
    public:
        Heap(T* inputArray, int inputNumElements, int inputMaxSize);
        
        int size() const;
        bool isLeaf(int nodePosition) const;
        int leftChild(int nodePosition) const;
        int rightChild(int nodePosition) const;
        int parent(int nodePosition) const;
        void buildHeap();
        void insert(const T& elementToInsert);
        T removeFirst();
        T remove(int positionToRemove);
};