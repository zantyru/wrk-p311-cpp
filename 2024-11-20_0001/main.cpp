#include <iostream>
using std::cout;


template<class T>
class Array
{
public:
    Array(size_t length)
        : _length{ length }
        , _p_elements{ nullptr }
    {
        if (_length == 0) return;

        _p_elements = new T[_length];
    }

    Array(const Array &other)
        : _length{ other._length }
        , _p_elements{ nullptr }
    {
        if (_length == 0) return;

        _p_elements = new T[_length];

        // for (size_t n = 0; n < _length; n++)
        // {
        //     _p_elements[n] = other._p_elements[n];
        // }
    }

    ~Array()
    {
        if (_length == 0) return;

        delete[] _p_elements;
        _p_elements = nullptr;
        _lenght = 0;
    }

    const Array &operator=(const Array &other) const
    {
        if (this == &other) return *this;


    }

    size_t GetLength() const
    {
        return _length;
    }

private:
    size_t _length;
    T *_p_elements;
};


int main()
{
    

    return 0;
}
