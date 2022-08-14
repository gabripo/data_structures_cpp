template<typename T>
class GTNode {
    public:
        T value();
        bool isLeaf();
        GTNode* parent();
        GTNode* leftMostChild();
        GTNode* rightSibling();
        void setValue(T& valueToSet);
        void insertFirst(GTNode<T>* firstChildToInsert);
        void insertNext(GTNode<T>* nextSiblingToInsert);
        void removeFirst();
        void removeNext();
};