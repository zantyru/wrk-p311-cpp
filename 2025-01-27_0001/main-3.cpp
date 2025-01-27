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

        int GetSomeValue() const
        {
            // ¬ложенный класс может в своЄм коде
            // ссылатьс€ на закрытые члены внешнего
            // класса (статические пол€)
            return X + Base::BX;
        }

        int GetModifiedValue(const Base& base) const
        {
            // ¬ложенный класс может в своЄм коде
            // ссылатьс€ на закрытые члены переданного
            // экземпл€ра внешнего класса 
            return X + base._value;
        }
    };

    void IncreaseValue()
    {
        ++_value;
    }

    void DecreaseValue()
    {
        --_value;
    }

    int GetValue() const
    {
        return _value;
    }

private:
    int _value = 1;
    static const int BX = -3;
};


int main()
{
    Base b;
    Base::InnerClass bic;

    cout << "bic.GetSomeValue() " << bic.GetSomeValue() << "\n";
    cout << "Base::InnerClass::X " << Base::InnerClass::X << "\n";

    b.IncreaseValue();
    b.IncreaseValue();
    cout << "b.GetValue() " << b.GetValue() << "\n";
    cout << "bic.GetModifiedValue(b) " << bic.GetModifiedValue(b) << "\n";

    return 0;
}
