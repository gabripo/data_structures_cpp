#include "../KVpair/KVpair.cpp"
#include "../Dictionary/Dictionary.cpp"
#include "../AList/AList.cpp"

template<typename Key, typename T>
class UALdict : public Dictionary<Key, T>
{
    private:
        AList<KVpair<Key, T> >* list;
    public:
        UALdict(int size = defaultSize);
        ~UALdict();

        void clear();
        void insert(const Key& keyToInsert, const T& valueToInsert);
        T remove(const Key& keyToRemove);
        T removeAny();
        T find(const Key& keyToFind) const;
        int size();
};