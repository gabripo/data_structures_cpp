#include "../List/List.cpp"
#include <iostream>

const int defaultSize = 10;

template <typename T>
class AList : public List<T>
{
private:
    int maxSize;
    int listSize;
    int curr;
    T *listArray;

public:
    AList(const int size = defaultSize);
    ~AList();

    void clear();
    void insert(const T &itemToInsert);
    void append(const T &itemToAppend);
    T remove();
    void moveToStart();
    void moveToEnd();
    void prev();
    void next();
    int length() const;
    int currentPos() const;
    void moveToPos(const int pos);
    const T &getValue() const;
};