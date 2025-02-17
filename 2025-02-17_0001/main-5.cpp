#include <iostream>
using std::cout;
using std::cin;


using FnPtr = void (*)(int);


void CallWith10(FnPtr p_bar)
{
    p_bar(10);
}


int main()
{
    setlocale(LC_ALL, "Russian");

    struct
    {
    public:
        void operator()(int s) const { return call(s); }

        operator FnPtr() const { return &call; }

    private:
        static void call(int s) { cout << "(struct) " << s << "\n"; }

    } baz;

    baz(999);

    CallWith10(baz);

    CallWith10(
        [](int x) -> void
        {
            cout << "(lambda) " << x << "\n";
        }
    );

    /*
    // Так не получится. Функция CallWith10 не работает
    // с настоящими лямбда-функциями
     
    int y = 100;

    CallWith10(
        [&y](int x) -> void
        {
            cout << "(lambda &y) " << x + y << "\n";
        }
    );
    */

    return 0;
}
