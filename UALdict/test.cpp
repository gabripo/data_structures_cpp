#include "UALdict.cpp"

int main(int argc, char const *argv[])
{
    UALdict<char, int> dict;
    dict.insert('a', 10);
    dict.insert('b', 20);
    std::cout << "Dictionary size: " << dict.size() << std::endl;

    std::cout << "Removed last element: " << dict.removeAny() << std::endl;
    std::cout << "Dictionary size: " << dict.size() << std::endl;

    return 0;
}
