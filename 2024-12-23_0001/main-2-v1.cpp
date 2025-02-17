#include <iostream>
using std::cout;
using std::cin;


class Base
{
public:
    Base(const std::string& name = "")
        : _name{ name }
    {
        cout << "Base::Constructor() <" << this << "|" << _name <<  ">\n";
    }

    ~Base()
    {
        cout << "Base::Destructor() <" << this << "|" << _name << ">\n";
    }

private:
    std::string _name;
};


Base g_b("Global");


void ExecuteExample()
{
    cout << "\nExecuteExample() has begun\n";

    Base b1("Local 1");
    static Base b2("Local 2 (static)");
    Base b3("Local 3");

    cout << "ExecuteExample() has ended\n\n";
}


int main()
{
    ExecuteExample();
    ExecuteExample();
    ExecuteExample();
    
    return 0;
}
 