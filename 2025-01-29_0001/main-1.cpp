#include <iostream>
using std::cout;
using std::cin;


struct S
{
    virtual ~S() = default;

    virtual void DoSomething() = 0;
};


struct F : public S
{
    virtual void DoSomething() override
    {
        cout << "It works.\n";
    }
};


int main()
{
    F f;
    S& rs = f;

    rs.DoSomething();

    return 0;
}
