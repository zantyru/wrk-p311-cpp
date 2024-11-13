#include <cstdint>
#include <string>
#include <iostream>
using std::cin;
using std::cout;
using std::string;


class A
{
public:
    A()
        : _name{ "noname" }
    {
        cout << "����������� | " << GetName() << "\n";
    }

    A(const A& other)
        : _name{ other._name }
    {
        cout << "����������� ����� | " << GetName() << "\n";
    }

    A(const string& name)
        : _name{ name }
    {
        cout << "����������� � ���������� | " << GetName() << "\n";
    }

    ~A()
    {
        cout << "���������� | " << GetName() << "\n";
    }

    A& operator=(const A& other)
    {
        if (this == &other)
        {
            cout << "������������ (������ ���� ����) | " << GetName() << "\n";
            return *this;
        }

        _name = other._name;
        cout << "������������ | " << GetName() << "\n";

        return *this;
    }

    string GetName() const
    {
        return _name + "@" + std::to_string(reinterpret_cast<std::uintptr_t>(this));
    }

private:
    string _name;
};


void DoNothing()
{
    static A staticInstance("staticInstance");
}


A CreateInstance()
{
    return A();
}


void ReceiveInstance(A copyInstance)
{  
}


A globalInstance("globalInstance");


int main()
{
    setlocale(LC_ALL, "Russian");

    //
    cout << "\n���� 1\n";

    A firstInstance("firstInstance");
    A secondInstance = firstInstance;

    {
        A thirdInstance("thirdInstance");
    }

    A fourthInstance("fourthInstance");

    //
    cout << "\n���� 2\n";

    firstInstance = fourthInstance;
    firstInstance = A("newFirstInstance");

    //
    cout << "\n���� 3\n";

    DoNothing();
    DoNothing();
    DoNothing();

    //
    cout << "\n���� 4\n";

    A oneMoreInstance = CreateInstance();

    //
    cout << "\n���� 5\n";

    ReceiveInstance(firstInstance);

    //
    cout << "\n����������...\n";

    return 0;
}