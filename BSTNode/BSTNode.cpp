#include "BSTNode.h"

template<typename Key, typename T>
BSTNode<Key, T>::BSTNode()
{
    leftChild = NULL;
    rightChild = NULL;
}

template<typename Key, typename T>
BSTNode<Key, T>::BSTNode(Key inputKey, T inputElement, BSTNode* inputLeftChild, BSTNode* inputRightChild)
{
    keyValue = inputKey;
    elementValue = inputElement;
    leftChild = inputLeftChild;
    rightChild = inputRightChild;
}

template<typename Key, typename T>
BSTNode<Key, T>::~BSTNode() { }

template<typename Key, typename T>
T& BSTNode<Key, T>::element()
{
    return elementValue;
}

template<typename Key, typename T>
void BSTNode<Key, T>::setElement(const T& elementToSet)
{
    elementValue = elementToSet;
}

template<typename Key, typename T>
Key& BSTNode<Key, T>::key()
{
    return keyValue;
}

template<typename Key, typename T>
void BSTNode<Key, T>::setKey(const Key& keyToSet)
{
    keyValue = keyToSet;
}

template<typename Key, typename T>
inline BSTNode<Key, T>* BSTNode<Key, T>::left() const
{
    return leftChild;
}

template<typename Key, typename T>
void BSTNode<Key, T>::setLeft(BinNode<T>* nodeToSet)
{
    leftChild = (BSTNode*) nodeToSet;
}

template<typename Key, typename T>
inline BSTNode<Key, T>* BSTNode<Key, T>::right() const
{
    return rightChild;
}

template<typename Key, typename T>
void BSTNode<Key, T>::setRight(BinNode<T>* nodeToSet)
{
    rightChild = (BSTNode*) nodeToSet;
}

template<typename Key, typename T>
bool BSTNode<Key, T>::isLeaf()
{
    return ((leftChild == NULL) && (rightChild == NULL));
}