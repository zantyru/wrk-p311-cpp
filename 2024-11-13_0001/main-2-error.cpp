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
        cout << "Конструктор | " << GetName() << "\n";
    }

    A(const A& other) = delete;  // Запрет конструктора копий

    A(const string& name)
        : _name{ name }
    {
        cout << "Конструктор с параметром | " << GetName() << "\n";
    }

    ~A()
    {
        cout << "Деструктор | " << GetName() << "\n";
    }

    A& operator=(const A& other) = delete;  // Запрет присваивания

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
    return A();  //@NOTE error
}


void ReceiveInstance(A copyInstance)
{  
}


A globalInstance("globalInstance");


int main()
{
    setlocale(LC_ALL, "Russian");

    //
    cout << "\nФаза 1\n";

    A firstInstance("firstInstance");
    //A secondInstance = firstInstance;  //@NOTE error

    {
        A thirdInstance("thirdInstance");
    }

    A fourthInstance("fourthInstance");

    //
    cout << "\nФаза 2\n";

    //firstInstance = fourthInstance;  //@NOTE error
    //firstInstance = A("newFirstInstance");  //@NOTE error

    //
    cout << "\nФаза 3\n";

    DoNothing();
    DoNothing();
    DoNothing();

    //
    cout << "\nФаза 4\n";

    //A oneMoreInstance = CreateInstance();  //@NOTE error

    //
    cout << "\nФаза 5\n";

    //ReceiveInstance(firstInstance);  //@NOTE error

    //
    cout << "\nЗавершение...\n";

    return 0;
}