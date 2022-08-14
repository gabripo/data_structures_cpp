#include "../GTNode/GTNode.h"
#include <iostream>

template<typename T>
class GenTree {
    public:
        void clear();
        GTNode<T>* root();
        void newroot(T& , GTNode<T>* , GTNode<T>*);
        void print();
};