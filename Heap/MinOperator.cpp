template<typename T>
class MinOperator
{
public:
    MinOperator() {};
    static bool prior(T a, T b) { return (a<b); };
};