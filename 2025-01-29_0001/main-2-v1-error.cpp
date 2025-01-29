#include <iostream>
using std::cout;
using std::cin;


class Base
{
public:
    void Run() const
    {
        cout << "Base.Run()";
    }
};


class D : private Base  // Так как private, преобразование в main не пройдёт
{};


int main()
{
    D d;
    Base b1 = (Base)d;
    Base b2 = static_cast<Base>(d);

    return 0;
}
