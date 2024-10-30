#include <iostream>
using std::cout;


class Number
{
public:
    Number()
        : _p_number{ nullptr }
    {
        _p_number = new float;
        cout << "Number::Constructor()\n";
    }

    ~Number()
    {
        delete _p_number;
        _p_number = nullptr;
        cout << "Number::Destructor()\n";
    }

    float Get()
    {
        cout << "Number::Get()\n";
        return *_p_number;
    }

    void Set(float newValue)
    {
        *_p_number = newValue;
        cout << "Number::Set()\n";
    }

private:
    float* _p_number;
};


Number nGLobal;


int main()
{
    Number n1;
    Number n2, n3;

    {
        Number n4;
    }

    Number n5;

    return 0;
}
