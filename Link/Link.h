template<typename T>
class Link
{
    public:
        T element;
        Link* next;
        Link(const T& elementValue, Link* nextValue = 0);
        Link(Link* nextValue = 0);
};