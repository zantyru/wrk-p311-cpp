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

    bool IsEmpty() const
    {
        return _elementCount == 0;
    }

    bool IsFull() const
    {
        return _elementCount == SIZE;
    }

private:
    static const size_t SIZE = 12;
    T _elements[SIZE];
    size_t _elementCount;
};


int main()
{
    Stack<int> stackOfIntegers;

    stackOfIntegers.Push(90);
    stackOfIntegers.Push(-1);
    stackOfIntegers.Push(5);
    stackOfIntegers.Push(7);

    while (!stackOfIntegers.IsEmpty())
    {
        int e{};
        stackOfIntegers.Pop(&e);
        cout << e << "  ";
    }
    
    cout << '\n';

    return 0;
}