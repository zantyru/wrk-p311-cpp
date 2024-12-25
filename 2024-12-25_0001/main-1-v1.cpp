/*
* В этом примере нет никакой виртуальности.
* 
* Поэтому при выводе на экран результата
* все животные обезличены и представляются
* просто как домашнее животное.
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

    const std::string Vocalize() const
    {
        return "...";
    }

    const std::string GetType() const
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
    std::vector<Pet> pets;

    pets.push_back(Cat("Barsik"));
    pets.push_back(Cat("Pulya"));
    pets.push_back(Dog("Reks"));
    pets.push_back(Cat("Manya"));
    pets.push_back(Dog("Belysh"));

    for (const Pet &pet : pets)
    {
        cout << "Type: " << pet.GetType() << "\n";
        cout << "Name: " << pet.GetName() << "\n";
        cout << "Voice: \"" << pet.Vocalize() << "\"\n";
    }

    return 0;
}

