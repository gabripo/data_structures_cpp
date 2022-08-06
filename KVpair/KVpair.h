template<typename Key, typename T>
class KVpair
{
    private:
        Key keyValue;
        T elementValue;
    public:
        KVpair();
        KVpair(Key keyValueToSet, T valueToSet);
        ~KVpair();
        KVpair(const KVpair& original);
        void operator=(const KVpair& rightHandSideElement);

        Key key() const;
        void setKey(Key keyToSet);
        T value() const;
};