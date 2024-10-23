#include <iostream>
using std::cout;
using std::cin;


class Number
{
public:
    int GetValue()
    {
        return _value;
    }

    void SetValue(int value)
    {
        if (value >= 0) _value = value;
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