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

private:
    int _value;  //! Плохо! Поле не инициализировано!
};


int main()
{
    int x = 9;
    int y(9);
    int z{ 9 };

    Number n;

    cout << n.GetValue() << "\n";

    return 0;
}