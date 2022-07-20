template<typename T>
class Link
{
    public:
        T element;
        Link* next;
        Link(const T& elementValue, Link* nextValue = NULL );
        Link(Link* nextValue = NULL);
};