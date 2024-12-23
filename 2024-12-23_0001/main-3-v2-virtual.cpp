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

    virtual ~Base()  //@NOTE Добавлено ключевое слово virtual
    {
        cout << "Base::Destructor() <" << this << "|" << _name << ">\n";
    }

    const std::string& GetName() const
    {
        return _name;
    }

private:
    std::string _name;
};


class Derived : public Base
{
public:
    Derived(const std::string& name = "")
        : Base{ name }
    {
        cout << "Derived::Constructor() <" << this << "|" << GetName() << ">\n";
    }

    virtual ~Derived()
    {
        cout << "Derived::Destructor() <" << this << "|" << GetName() << ">\n";
    }

    void DoNothing() const
    {}
};


int main()
{
    Derived d("Test");
    Base* p_b = &d;
    //p_b->DoNothing();  // Через указатель базового типа метод недоступен
    Derived* p_d = &d;
    p_d->DoNothing();

    cout << "\n-------------\n\n";

    Derived* v = new Derived("Object (derived)");
    delete v;

    cout << "\n-------------\n\n";

    Base* p = new Derived("Object");
    delete p;  // Вот теперь деструктор у класса Derived работает как надо

    cout << "\n-------------\n\n";
    
    return 0;
}
 