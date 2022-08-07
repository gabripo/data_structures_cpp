#include "BST.h"

template<typename Key, typename T>
BST<Key, T>::BST()
{
    root = NULL;
    nodeCount = 0;
}

template<typename Key, typename T>
BST<Key, T>::~BST()
{
    clearNodes(root);
}

template<typename Key, typename T>
void BST<Key, T>::clearNodes(BSTNode<Key, T>* startingNode)
{
    if (startingNode == NULL)
    {
        return;
    }
    clearNodes(startingNode->left());
    clearNodes(startingNode->right());
    delete startingNode;
}

template<typename Key, typename T>
void BST<Key, T>::clear()
{
    clearNodes(root);
    root = NULL;
    nodeCount = 0;
}

template<typename Key, typename T>
void BST<Key, T>::insert(const Key& inputKey, const T& inputElement)
{
    root = insertInTree(root, inputKey, inputElement);
    nodeCount++;
}

template<typename Key, typename T>
BSTNode<Key, T>* BST<Key, T>::insertInTree(BSTNode<Key, T>* startingNode, const Key& inputKey, const T& inputElement)
{
    if (startingNode == NULL)
    {
        return new BSTNode<Key, T>(inputKey, inputElement, NULL, NULL);
    }

    // BST implies that key values on the left are less than the current one and right values are greater than, instead
    if (inputKey < startingNode->key())
    {
        startingNode->setLeft(insertInTree(startingNode->left(), inputKey, inputElement));
    }
    else
    {
        startingNode->setRight(insertInTree(startingNode->right(), inputKey, inputElement));
    }
    return startingNode;
}

template<typename Key, typename T>
T BST<Key, T>::remove(const Key& keyToRemove)
{
    T elementToReturn = findElementByKey(root, keyToRemove);
    if (elementToReturn != NULL)
    {
        root = removeNodeByKey(root, keyToRemove);
        nodeCount--;
    }
    return elementToReturn;
}

template<typename Key, typename T>
T BST<Key, T>::removeAny()
{
    if (root != NULL)
    {
        T elementToReturn = root->element();
        root = removeNodeByKey(root, root->key());
        nodeCount--;
        return elementToReturn;
    }
    else
    {
        return NULL;
    }
}

template<typename Key, typename T>
T BST<Key, T>::find(const Key& keyToFind) const
{
    return findElementByKey(root, keyToFind);
}

template<typename Key, typename T>
T BST<Key, T>::findElementByKey(BSTNode<Key, T>* startingNode, const Key& keyToFind) const
{
    if (startingNode == NULL)
    {
        return NULL;
    }
    if (keyToFind < startingNode->key())
    {
        return findElementByKey(startingNode->right(), keyToFind);
    }
    else if (keyToFind >= startingNode->key())
    {
        return findElementByKey(startingNode->left(), keyToFind);
    }
    else
    {
        return startingNode->element();
    }
}

template<typename Key, typename T>
BSTNode<Key, T>* BST<Key, T>::removeNodeByKey(BSTNode<Key, T>* startingNode, const Key& keyToRemove)
{
    if (startingNode == NULL)
    {
        return NULL;
    }
    else if (keyToRemove < startingNode->key())
    {
        startingNode->setLeft(removeNodeByKey(startingNode->left(), keyToRemove));
    }
    else if (keyToRemove >= startingNode->key())
    {
        startingNode->setRight(removeNodeByKey(startingNode->right(), keyToRemove));
    }
    else
    {
        BSTNode<Key, T>* nodeToRemove = startingNode;
        if (startingNode->left() == NULL)
        {
            startingNode = startingNode->right();
            delete nodeToRemove;
        }
        else if (startingNode->right() == NULL)
        {
            startingNode = startingNode->left();
            delete nodeToRemove;
        }
        else
        {
            nodeToRemove = getNodeWithMinKey(startingNode->right());
            startingNode->setElement(nodeToRemove->element());
            startingNode->setKey(nodeToRemove->key());
            startingNode->setRight(deleteMinChild(startingNode->right()));
            delete nodeToRemove;
        }
        return startingNode;
    }   
}

template<typename Key, typename T>
BSTNode<Key, T>* BST<Key, T>::getNodeWithMinKey(BSTNode<Key, T>* startingNode)
{
    if (startingNode->left() == NULL)
    {
        return startingNode;
    }
    else
    {
        return getNodeWithMinKey(startingNode->left());
    }
}

template<typename Key, typename T>
BSTNode<Key, T>* BST<Key, T>::deleteMinChild(BSTNode<Key, T>* startingNode)
{
    if (startingNode->left() == NULL)
    {
        return startingNode->right();
    }
    else
    {
        startingNode->setLeft(deleteMinChild(startingNode->left()));
        return startingNode;
    }   
}

template<typename Key, typename T>
int BST<Key, T>::size()
{
    return nodeCount;
}

template<typename Key, typename T>
void BST<Key, T>::print() const
{
    if (root == NULL)
    {
        std::cout << "The BST is empty, impossible to print it out!" << std::endl;
    }
    else
    {
        printFromNodeToLevel(root, 0);
    }
}

template<typename Key, typename T>
void BST<Key, T>::printFromNodeToLevel(BSTNode<Key, T>* startingNode, int level) const
{
    if (startingNode == NULL)
    {
        return;
    }
    printFromNodeToLevel(startingNode->left(), level+1);
    for (int i = 0; i < level; i++)
    {
        std::cout << "  ";
    }
    std::cout << startingNode->key() << std::endl;
    printFromNodeToLevel(startingNode->right(), level+1);
}