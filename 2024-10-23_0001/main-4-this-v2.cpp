#include <iostream>
using std::cout;
using std::cin;


class Number
{
public:
    int GetValue()
    {
        return this->_value;  // Добавили явно this
    }

    void SetValue(int value)
    {
        if (value >= 0) this->_value = value;  // Добавили явно this
    }

private:
    int _value{ 0 };
};


int main()
{
    Number n1;
    Number n2;

    n1.SetValue(1000);

    cout << n1.GetValue() << "\n";
    cout << n2.GetValue() << "\n";

    return 0;
}