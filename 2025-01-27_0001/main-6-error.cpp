#include <iostream>
using std::cout;
using std::cin;


class Counter
{
public:
    Counter(int startValue)
        : _value{ startValue }
    {}

    void Increase()
    {
        ++_value;
    }

    void Decrease()
    {
        --_value;
    }

    int GetValue() const
    {
        return _value;
    }

    // Обратите внимание, что
    // не указывается возвращаемый
    // тип, потому что он определяется
    // типом, в который производится
    // преобразование
    operator int() const
    {
        return _value;
    }

    operator double() const
    {
        return static_cast<double>(_value);
    }

private:
    int _value;
};


int main()
{
    Counter c(11);

    int x = 12 + c;  // Теперь компилятор не понимает, какую версию преобразования брать
    int y = c - 1;

    cout << "c:       " << c << "\n";
    cout << "12 + c:  " << x << "\n";
    cout << "c - 1:   " << y << "\n";

    double d = 2.1 * c;
    cout << "2.1 * c: " << d << "\n";

    return 0;
}
