#include <random>
#include <vector>
#include <string>  // Для to_string
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
    std::random_device rd{};
    std::mt19937 rnd{ rd() };

    std::vector<Base*> objects;

    // Генерация объектов

    for (size_t i = 0; i < 12; ++i)
    {
        if (rnd() % 2 == 0)
        {
            objects.push_back(
                new Base(std::string("Base_") + std::to_string(i))
            );
        }
        else
        {
            objects.push_back(
                new Derived(std::string("Derived_") + std::to_string(i))
            );
        }
    }

    // Распечатка имени объектов

    cout << "\n--------\n\n";

    for (const Base* p_object : objects)
    {
        cout << p_object->GetName() << "\n";
    }

    cout << "\n--------\n\n";

    // Освобождение ресурсов

    while (objects.size() > 0)
    {
        Base* p_objects = objects[objects.size() - 1];
        delete p_objects;
        objects.pop_back();
    }
   
    return 0;
}
 