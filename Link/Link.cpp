#include "Link.h"

template<typename T>
Link<T>::Link(const T& elementValue, Link* nextValue)
{
    element = elementValue;
    next = nextValue;
}

template<typename T>
Link<T>::Link(Link* nextValue)
{
    next = nextValue;
}