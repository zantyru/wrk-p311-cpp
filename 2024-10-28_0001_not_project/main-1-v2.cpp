#include <iostream>
using std::cout;


class Number
{
public:
    Number(std::string name)
        : _p_number{ nullptr }
        , _name{ name }
    {
        _p_number = new float;
        cout << _name << " | Number::Constructor()\n";
    }

    ~Number()
    {
        delete _p_number;
        _p_number = nullptr;
        cout << _name << " | Number::Destructor()\n";
    }

    float Get()
    {
        cout << _name << " | Number::Get()\n";
        return *_p_number;
    }

    void Set(float newValue)
    {
        *_p_number = newValue;
        cout << _name << " | Number::Set()\n";
    }

private:
    float* _p_number;
    std::string _name;
};


Number nGLobal{ "nGlobal" };


int main()
{
    Number n1{ "n1" };
    Number n2{ "n2" }, n3{ "n3" };

    {
        Number n4{ "n4" };
    }

    Number n5{ "n5" };

    return 0;
}
