#include "../List/List.cpp"
#include "../Link/Link.cpp"
#include <iostream>

const int defaultSize = 10;

template<typename T>
class LList : public List<T>
{
    private:
        Link<T>* head;
        Link<T>* tail;
        Link<T>* curr;
        int cnt;
        void init();
        void removeall();

    public:
        LList(int size = defaultSize);
        ~LList();

        void print() const;
        void clear();
        void insert(const T& elementToInsert);
        void append(const T& elementToAppend);
        T remove();
        void moveToStart();
        void moveToEnd();
        void prev();
        void next();
        int length() const;
        int currentPos() const;
        void moveToPos(int pos);
        const T& getValue() const;

};