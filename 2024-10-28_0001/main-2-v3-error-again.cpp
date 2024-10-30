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

    Number(const Number& other)
        : _p_number{ nullptr }
        , _name{ other._name }
    {
        _p_number = new float;
        *_p_number = *(other._p_number);
        cout << _name << " | Number::CopyConstructor()\n";
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


int main()
{
    Number n1{ "n1" };
    Number n2{ "n2" };

    n1.Set(100);
    n2.Set(-78);

    cout << "n1: " << n1.Get() << "\n";
    cout << "n2: " << n2.Get() << "\n";

    Number n3 = n2;  // Тут работает конструктор копий

    cout << "n3: " << n3.Get() << " (created as n2 copy)\n";

    n3 = n1;  // Тут работает оператор присваивания

    cout << "n3: " << n3.Get() << " (it is n1 copy now)\n";

    return 0;
}
