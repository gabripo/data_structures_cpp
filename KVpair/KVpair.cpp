#include "KVpair.h"

template<typename Key, typename T>
KVpair<Key, T>::KVpair() : keyValue(0), elementValue(0) {}

template<typename Key, typename T>
KVpair<Key, T>::KVpair(Key keyValueToSet, T valueToSet)
{
    keyValue = keyValueToSet;
    elementValue = valueToSet;
}

template<typename Key, typename T>
KVpair<Key, T>::~KVpair() {}

template<typename Key, typename T>
KVpair<Key, T>::KVpair(const KVpair& original)
{
    keyValue = original.key();
    elementValue = original.value();
}

template<typename Key, typename T>
void KVpair<Key, T>::operator=(const KVpair& rightHandSideElement)
{
    keyValue = rightHandSideElement.key();
    elementValue = rightHandSideElement.value();
}

template<typename Key, typename T>
Key KVpair<Key, T>::key() const
{
    return keyValue;
}

template<typename Key, typename T>
void KVpair<Key, T>::setKey(Key keyToSet)
{
    keyValue = keyToSet;
}

template<typename Key, typename T>
T KVpair<Key, T>::value() const
{
    return elementValue;
}