#include "LinkedList.h"

template <typename T>
LinkedList<T>::LinkedList() : size(1)
{
    std::cout << "Default constructor with no arguments called. The default size will be 1." << std::endl;
    this->values = new T[this->size];
    this->values[0] = 0;
    this->keys = new char *[1];
    this->keys[0] = new char[MAX_CHARACTERS];
    std::strcpy(this->keys[0], "(null)");
}

template <typename T>
LinkedList<T>::LinkedList(size_t input_size) : size(input_size)
{
    std::cout << "A new list with initial size " << this->size << " will be created." << std::endl;
    this->values = new T[this->size];
    this->keys = new char *[this->size];
    for (size_t idxKey = 0; idxKey < this->size; idxKey++)
    {
        this->keys[idxKey] = new char[MAX_CHARACTERS];
        std::strcpy(this->keys[idxKey], "(null)");
    }
}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList &original)
{
    std::cout << "Copy of ctor of LinkedList called..." << std::endl;
    // 1. Copy the non-pointer members
    this->size = original.size;
    // 2. Allocate a new heap memory segment
    this->values = new T[this->size];
    this->keys = new char *[this->size];
    // 3. Copy from original heap memory to the new heap memory segment
    for (size_t idxKeys = 0; idxKeys < this->size; idxKeys++)
    {
        this->keys[idxKeys] = original.keys[idxKeys];
        std::strcpy(this->keys[idxKeys], original.keys[idxKeys]);
    }
}

template <typename T>
LinkedList<T> &LinkedList<T>::operator=(const LinkedList<T> &rhs)
{
    std::cout << "Assignment operator of Queue called..." << std::endl;
    if (this != &rhs)
    {
        // 1. Delete the heap memory segment of the left-hand-side operand
        delete[] this->values;
        delete[] this->keys;
        // 2. Copy the non-pointer members
        this->size = rhs.size;
        // 3. Allocate memory for the left-hand-side and copy content
        this->values = new T[this->size];
        this->keys = new char *[this->size];
        for (size_t idxData = 0; idxData < this->size; idxData++)
        {
            this->values[idxData] = rhs.values[idxData];
            this->keys[idxData] = new char[MAX_CHARACTERS];
            std::strcpy(this->keys[idxData], rhs.keys[idxData]);
        }
    }
    // Return a reference to the left-hand-side - Needed for operator concatenation (chain of equalities)
    return *this;
}

template <typename T>
bool LinkedList<T>::empty()
{
    return (this->size == 0);
}

template <typename T>
void LinkedList<T>::print()
{
    std::cout << "Printing list..." << std::endl;
    if (this->empty())
    {
        std::cout << "The list is empty, nothing to print!" << std::endl;
    }
    else
    {
        std::cout << "Keys | Values: " << std::endl;
        for (size_t idxKeys = 0; idxKeys < this->size; idxKeys++)
        {
            std::cout << this->keys[idxKeys] << " | " << this->values[idxKeys] << std::endl;
        }
    }
    std::cout << "Printing done." << std::endl;
}

template <typename T>
void LinkedList<T>::clear()
{
    std::cout << "Clearing the object values (default is a list of 1 element)..." << std::endl;
    this->size = 1;
    delete[] this->values;
    this->values = new T[this->size];
    delete[] this->keys;
    this->keys = new char *[this->size];
    this->keys[0] = new char[MAX_CHARACTERS];
    std::strcpy(this->keys[0], "(null)");
}

template <typename T>
void LinkedList<T>::insert(const char *key, const T value)
{
    T *newValues = new T[this->size + 1];
    char **newKeys = new char *[this->size + 1];
    for (size_t idxValue = 0; idxValue < this->size; idxValue++)
    {
        newValues[idxValue] = this->values[idxValue];
        newKeys[idxValue] = new char[std::strlen(this->keys[idxValue]) + 1];
        std::strcpy(newKeys[idxValue], this->keys[idxValue]);
    }
    newValues[this->size] = value;
    newKeys[this->size] = new char[std::strlen(key) + 1];
    std::strcpy(newKeys[this->size], key);

    delete[] this->values;
    delete[] this->keys;
    this->size++;
    this->values = new T[this->size];
    this->keys = new char *[this->size];
    for (size_t idxValue = 0; idxValue < this->size; idxValue++)
    {
        this->values[idxValue] = newValues[idxValue];
        this->keys[idxValue] = new char[strlen(newKeys[idxValue]) + 1];
        std::strcpy(this->keys[idxValue], newKeys[idxValue]);
    }
    delete[] newValues;
    delete[] newKeys;
}

template <typename T>
size_t LinkedList<T>::keyIsThere(const char *key)
{
    bool keyFound = false;
    size_t idxKey = 0;
    while (!keyFound && idxKey < this->size)
    {
        if (*(this->keys[idxKey]) == *key)
        {
            keyFound = true;
        }
        else
        {
            idxKey++;
        }
    }
    if (keyFound)
    {
        return idxKey;
    }
    else
    {
        return 0;
    }
}

template <typename T>
void LinkedList<T>::replace(const char *oldKey, const char *newKey, const T value)
{
    size_t idxKey = this->keyIsThere(oldKey);
    if (idxKey != 0)
    {
        this->values[idxKey] = value;
        if (std::strlen(this->keys[idxKey]) < std::strlen(newKey))
        {
            this->keys[idxKey] = new char[MAX_CHARACTERS];
        }
        std::strcpy(this->keys[idxKey], newKey);
    }
    else
    {
        std::cout << "Key " << oldKey << " not found in list's keys, impossible to assign the value!" << std::endl;
    }
}

template <typename T>
T LinkedList<T>::fetch(const char *key)
{
    size_t idxKey = this->keyIsThere(key);
    if (idxKey != 0)
    {
        return this->values[idxKey];
    }
    else
    {
        std::cout << "Key " << key << " is missing among available ones! No element can be fetched from the list." << std::endl;
        return (T) NULL;
    }
}

template <typename T>
LinkedList<T>::~LinkedList()
{
    std::cout << "Destructor called..." << std::endl;
    delete[] this->values;
    delete[] this->keys;
}