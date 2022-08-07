#include "../BSTNode/BSTNode.cpp"
#include "../Dictionary/Dictionary.cpp"
#include <stddef.h>
#include <iostream>

template<typename Key, typename T>
class BST : public Dictionary<Key, T>
{
    private:
        BSTNode<Key, T>* root;
        int nodeCount;
        void clearNodes(BSTNode<Key, T>* startingNode);
        BSTNode<Key, T>* insertInTree(BSTNode<Key, T>* startingNode, const Key& inputKey, const T& inputElement);
        T findElementByKey(BSTNode<Key, T>* startingNode, const Key& keyToFind) const;
        BSTNode<Key, T>* removeNodeByKey(BSTNode<Key, T>* startingNode, const Key& keyToRemove);
        BSTNode<Key, T>* getNodeWithMinKey(BSTNode<Key, T>* startingNode);
        BSTNode<Key, T>* deleteMinChild(BSTNode<Key, T>* startingNode);
        void printFromNodeToLevel(BSTNode<Key, T>* startingNode, int level) const;
    public:
        BST();
        ~BST();

        void clear();
        void insert(const Key& inputKey, const T& inputElement);
        T remove(const Key& keyToRemove);
        T removeAny();
        T find(const Key& keyToFind) const;
        int size();
        void print() const;
};