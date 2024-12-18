#include <iostream>
using std::cout;
using std::cin;


class Base
{
public:
    int x{};
    int y{};
};


class Derived : Base
{
public:
    Derived() : Base{}
    {}

    int z{};
    int x{};
};


int main()
{
    Derived d;

    d.x = 12;
    d.Base::x = -2;  // Нельзя так.
    d.y = 2;  // ???

    cout << "d.x: " << d.x << "\n";

    return 0;
}
