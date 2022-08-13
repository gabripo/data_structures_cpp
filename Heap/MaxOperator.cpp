template<typename T>
class MaxOperator
{
public:
    MaxOperator() {};
    static bool prior(T a, T b) { return (a>b); };
};