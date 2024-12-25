/*
* В этом примере есть виртуальные функции-
* члены.
* 
* При выводе на экран результата каждое
* животное обозначает себя верно.
*/


#include <vector>
#include <iostream>
using std::cout;
using std::cin;


#define AsText(x) (#x)


class Pet
{
public:
    Pet(const std::string &name)
        : _name{ name }
    {}

    const std::string &GetName() const
    {
        return _name;
    }

    virtual const std::string Vocalize() const  //@NOTE Добавили virtual
    {
        return "...";
    }

    virtual const std::string GetType() const  //@NOTE Добавили virtual
    {
        return AsText(Pet);
    }

private:
    std::string _name;
};


class Cat : public Pet
{
public:
    Cat(const std::string& name)
        : Pet{ name }
    {}

    const std::string Vocalize() const
    {
        return "Mew!";
    }

    const std::string GetType() const
    {
        return AsText(Cat);
    }

};


class Dog : public Pet
{
public:
    Dog(const std::string &name)
        : Pet{ name }
    {}

    const std::string Vocalize() const
    {
        return "Woof!";
    }

    const std::string GetType() const
    {
        return AsText(Dog);
    }

};


int main()
{
    std::vector<Pet*> pets;  //@NOTE Изменился тип хранимых данных

    pets.push_back(new Cat("Barsik"));
    pets.push_back(new Cat("Pulya"));
    pets.push_back(new Dog("Reks"));
    pets.push_back(new Cat("Manya"));
    pets.push_back(new Dog("Belysh"));

    for (const Pet* pet : pets)  //@NOTE Здесь теперь указатель
    {
        cout << "Type: " << pet->GetType() << "\n";
        cout << "Name: " << pet->GetName() << "\n";
        cout << "Voice: \"" << pet->Vocalize() << "\"\n";
    }

    return 0;
}

