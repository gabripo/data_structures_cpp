template<typename T>
class List
{
    private:
        void operator=(const List&);
        List(const List&);
    public:
        List();
        ~List();

        virtual void clear() = 0;
        virtual void insert(const T& itemToInsert) = 0;
        virtual void append(const T& itemToAppend) = 0;
        virtual T remove() = 0;
        virtual void moveToStart() = 0;
        virtual void moveToEnd() = 0;
        virtual void prev() = 0;
        virtual void next() = 0;
        virtual int length() const = 0;
        virtual int currentPos() const = 0;
        virtual void moveToPos(const int pos) = 0;
        virtual const T& getValue() const = 0;
};