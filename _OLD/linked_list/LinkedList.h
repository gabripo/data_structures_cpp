// Linked list implementation
#include <iostream>

#define MAX_CHARACTERS 100

template <typename T>
class LinkedList
{
private:
    T *values;
    size_t size;
    char **keys;

public:
    LinkedList();
    LinkedList(size_t input_size);
    LinkedList(const LinkedList &original);             // Copy constuctor
    LinkedList<T> &operator=(const LinkedList<T> &rhs); // Asignment operator

    bool empty();
    void print();
    void clear();
    void insert(const char *key, const T value);
    size_t keyIsThere(const char *key);
    void replace(const char *oldKey, const char *newKey, const T value);
    T fetch(const char *key);

    ~LinkedList();
};