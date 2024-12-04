#include <iostream>
using std::cout;
using std::cin;


template <class T>
class Stack
{
public:
    Stack()
        : _elementCount{ 0 }
    {}

    bool Push(const T &element)
    {
        if (_elementCount == SIZE) return false;

        _elements[_elementCount] = element;
        ++_elementCount;

        return true;
    }

    bool Pop(T* p_element)
    {
        if (_elementCount == 0) return false;

        --_elementCount;
        *p_element = _elements[_elementCount];

        return true;
    }

private:
    const size_t SIZE = 12;
    T _elements[SIZE];
    size_t _elementCount;
};


int main()
{
    Stack<int> stackOfIntegers;

    return 0;
}