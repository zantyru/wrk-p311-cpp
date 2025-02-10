#include <memory>
#include <string>  // Для std::to_string
#include <sstream>
#include <vector>
#include <iostream>
using std::cout;
using std::cin;


class A
{
public:
    using Ptr = std::shared_ptr<A>;

    A(const std::string& name)
        : _name{ name }
    {
        cout << "'" << _name << this << "' A::Constructor()\n";
    }

    A(const A& other) = default;

    ~A()
    {
        cout << "'" << _name << this << "' A::Destructor()\n";
    }

    A& operator=(const A& other) = default;

    std::string GetName() const
    {
        std::ostringstream name;
        name << _name << this;

        return name.str();
    }

private:
    std::string _name;
};


int main()
{
    setlocale(LC_ALL, "Russian");

    A::Ptr p_object{};
    cout << "*** Количество владельцев: " << p_object.use_count() << "\n";  // 0

    {
        std::vector<A::Ptr> objects;
        objects.push_back(A::Ptr(new A("One")));  // По стандарту C++11
        objects.push_back(A::Ptr(new A("Two")));  // По стандарту C++11
        objects.push_back(A::Ptr(new A("Three")));  // По стандарту C++11

        p_object = objects[1];
        cout << "*** Количество владельцев: " << p_object.use_count() << "\n";  // 2
    }

    cout << "*** Количество владельцев: " << p_object.use_count() << "\n";  // 1

    p_object.reset();
    cout << "*** Количество владельцев: " << p_object.use_count() << "\n";  // 0

    return 0;
}
