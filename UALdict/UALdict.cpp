#include "UALdict.h"

template<typename Key, typename T>
UALdict<Key, T>::UALdict(int size)
{
    list = new AList<KVpair<Key, T> >(size);
}

template<typename Key, typename T>
UALdict<Key, T>::~UALdict()
{
    delete list;
}

template<typename Key, typename T>
void UALdict<Key, T>::clear()
{
    list->clear();
}

template<typename Key, typename T>
void UALdict<Key, T>::insert(const Key& keyToInsert, const T& valueToInsert)
{
    KVpair<Key, T> pairToAppend(keyToInsert, valueToInsert);
    list->append(pairToAppend);
}

template<typename Key, typename T>
T UALdict<Key, T>::remove(const Key& keyToRemove)
{
    T tempValue = find(keyToRemove);    // the list position is set by "find"
    if (tempValue != NULL)
    {
        list->remove();
    }
    return tempValue;
}

template<typename Key, typename T>
T UALdict<Key, T>::removeAny()
{
    if (size() == 0)
    {
        std::cout << "Impossible to remove the last element, the list is empty!" << std::endl;
        return (T) 0;
    }
    list->moveToEnd();
    list->prev();
    KVpair<Key, T> tempPair = list->remove();
    return tempPair.value();
}

template<typename Key, typename T>
T UALdict<Key, T>::find(const Key& keyToFind) const
{
    for (list->moveToStart(); list->currentPos() < list->length(); list->next())
    {
        KVpair<Key, T> tempPair = list->getValue();
        if (keyToFind == tempPair.key())
        {
            return tempPair.value();
        }
    }
    return NULL;
}

template<typename Key, typename T>
int UALdict<Key, T>::size()
{
    return list->length();
}