#include <string>
#include <exception>
#include <iostream>
using std::cout;
using std::cin;


class A
{
public:
    A()
    {
        cout << "A::Constructor()\n";
    }

    ~A()
    {
        cout << "A::Destructor()\n";
    }

    void DoSomethingBad()
    {
        throw std::runtime_error("Просто ошибка во время исполнения программы.");
    }
};


int main()
{
    setlocale(LC_ALL, "Russian");

    try
    {
        A a;
        a.DoSomethingBad();
        // Деструктор будет вызван в любом случае
        cout << "Уф. Всё хорошо.\n";
    }
    catch (const std::runtime_error& e)
    {
        cout << e.what() << "\n";
    }

    return 0;
}
