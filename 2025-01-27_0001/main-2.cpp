#include <iostream>
using std::cout;
using std::cin;


class Base
{
public:
    class InnerClass
    {
    public:
        static const int X = 12;

        int GetSomeValue()
        {
            // Вложенный класс может в своём коде
            // ссылаться на закрытые члены внешнего
            // класса (статические поля)
            return X + Base::BX;
        }
    };

private:
    static const int BX = -3;
};


int main()
{
    Base b;
    Base::InnerClass bic;

    cout << "bic.GetSomeValue() " << bic.GetSomeValue() << "\n";
    cout << "Base::InnerClass::X " << Base::InnerClass::X << "\n";

    return 0;
}
