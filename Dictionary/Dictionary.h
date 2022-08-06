template<typename Key, typename T>
class Dictionary
{
    private:
        void operator=(const Dictionary&);
        Dictionary(const Dictionary&);
    public:
        Dictionary();
        virtual ~Dictionary();

        virtual void clear() = 0;
        virtual void insert(const Key& keyToInsert, const T& valueToInsert) = 0;
        virtual T remove(const Key& keyToRemove) = 0;
        virtual T removeAny() = 0;
        virtual T find(const Key& keyToFind) const = 0;
        virtual int size() = 0;
};