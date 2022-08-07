template<typename T>
class BinNode
{
    public:
        virtual ~BinNode();

        virtual T& element() = 0;
        virtual void setElement(const T&) = 0;
        virtual BinNode* left() const = 0;
        virtual void setLeft(BinNode*) = 0;
        virtual BinNode* right() const = 0;
        virtual void setRight(BinNode*) = 0;
        virtual bool isLeaf() = 0;
};