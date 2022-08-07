#include "../BinNode/BinNode.cpp"
#include <stddef.h>

template<typename Key, typename T>
class BSTNode : public BinNode<T>
{
    private:
        Key keyValue;
        T elementValue;
        BSTNode* leftChild;
        BSTNode* rightChild;
    public:
        BSTNode();
        BSTNode(Key inputKey, T inputElement, BSTNode* inputLeftChild = NULL, BSTNode* inputRightChild = NULL);
        ~BSTNode();

        T& element();
        void setElement(const T& elementToSet);
        Key& key();
        void setKey(const Key& keyToSet);

        inline BSTNode* left() const;
        void setLeft(BinNode<T>* nodeToSet);
        inline BSTNode* right() const;
        void setRight(BinNode<T>* nodeToSet);

        bool isLeaf();
};