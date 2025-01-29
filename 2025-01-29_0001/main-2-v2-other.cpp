#include <iostream>
using std::cout;
using std::cin;


class Base
{
public:
    void Run() const
    {
        cout << "Base.Run()\n";
    }
};


class D : public Base  // Сменили на public
{};


int main()
{
    Base* p_b = new D;

    D* p1_d = (D*)p_b;
    D* p2_d = static_cast<D*>(p_b);

    p1_d->Run();  // Продупреждает, о возможно неинициализированном указателе.
    p2_d->Run();

    delete p_b;
    p_b = nullptr;

    return 0;
}
