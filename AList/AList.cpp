#include "AList.h"

template <typename T>
AList<T>::AList(const int size)
{
    std::cout << "Constructor of AList called" << std::endl;
    maxSize = size;
    listSize = 0;
    curr = 0;
    listArray = new T[maxSize];
}

template <typename T>
AList<T>::~AList()
{
    std::cout << "Destructor of AList called" << std::endl;
    delete[] listArray;
}

// Theta(1) time
template <typename T>
void AList<T>::clear()
{
    std::cout << "Clear function of AList called" << std::endl;
    delete[] listArray;
    listSize = 0;
    curr = 0;
    listArray = new T[maxSize];
}

// Theta(n) time
template <typename T>
void AList<T>::insert(const T &itemToInsert)
{
    if (listSize > maxSize)
    {
        std::cout << "Impossible to insert element, the AList is full!" << std::endl;
        return;
    }
    for (int i = listSize; i > curr; i--)
    {
        listArray[i] = listArray[i - 1];
    }
    listArray[curr] = itemToInsert;
    listSize++;
    std::cout << "Element inserted at position " << curr << std::endl;
}

// Theta(1) time
template <typename T>
void AList<T>::append(const T &itemToAppend)
{
    if (listSize > maxSize)
    {
        std::cout << "Impossible to append element, the AList is full!" << std::endl;
        return;
    }
    listArray[listSize] = itemToAppend;
    listSize++;
    std::cout << "Element appended at the tail " << std::endl;
}

// Theta(n) time
template <typename T>
T AList<T>::remove()
{
    if ((curr < 0) || (listSize < curr) || (listSize == 0))
    {
        std::cout << "Impossible to remove element, the AList is empty!" << std::endl;
        return (T)0;
    }
    T itemToReturn = listArray[curr];
    for (int i = curr; i < listSize - 1; i++)
    {
        listArray[i] = listArray[i + 1];
    }
    listSize--;
    std::cout << "Element removed at position " << curr << std::endl;
    return itemToReturn;
}

// Theta(1) time
template <typename T>
void AList<T>::moveToStart()
{
    std::cout << "Moving to the start of AList..." << std::endl;
    curr = 0;
}

// Theta(1) time
template <typename T>
void AList<T>::moveToEnd()
{
    std::cout << "Moving to the end of AList..." << std::endl;
    curr = listSize - 1;
}

// Theta(1) time
template <typename T>
void AList<T>::prev()
{
    std::cout << "Moving to the previous..." << std::endl;
    if (curr <= 0)
    {
        std::cout << "Impossible to move to previous: the current position in AList is at the head" << std::endl;
        return;
    }
    curr--;
}

// Theta(1) time
template <typename T>
void AList<T>::next()
{
    std::cout << "Moving to the next..." << std::endl;
    if (curr == listSize - 1)
    {
        std::cout << "Impossible to move to the next: the current position in AList is at the tail" << std::endl;
        return;
    }
    curr++;
}

// Theta(1) time
template <typename T>
int AList<T>::length() const
{
    return listSize;
}

// Theta(1) time
template <typename T>
int AList<T>::currentPos() const
{
    return curr;
}

// Theta(1) time
template <typename T>
void AList<T>::moveToPos(const int pos)
{
    if (pos > listSize)
    {
        std::cout << "Impossible to move to position " << pos << " in AList, as it is greater than list size " << listSize << std::endl;
        return;
    }
    std::cout << "Moving to the position " << pos << " of AList..." << std::endl;
    curr = pos;
}

// Theta(1) time
template <typename T>
const T &AList<T>::getValue() const
{
    if ((curr > listSize) || (curr < 0) || (listSize == 0))
    {
        std::cout << "Impossible to get current element: current position is invalid!" << std::endl;
        return (T)0;
    }
    return listArray[curr];
}

// Theta(n) time
template <typename T>
void AList<T>::print() const
{
    std::cout << "Printing list: { ";
    for (int i = 0; i < listSize; i++)
    {
        if (i == curr)
        {
            std::cout << "|";
        }
        std::cout << listArray[i] << " ";
    }
    std::cout << "} with current position " << curr << std::endl;
}