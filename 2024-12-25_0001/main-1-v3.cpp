/*
* � ���� ������� ���� ����������� �������-
* �����.
* 
* ��� ������ �� ����� ���������� ������
* �������� ���������� ���� �����.
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

    virtual const std::string Vocalize() const  //@NOTE �������� virtual
    {
        return "...";
    }

    virtual const std::string GetType() const  //@NOTE �������� virtual
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

    virtual const std::string Vocalize() const override  //@NOTE ��������� �������� ����� virtual � override; ������ �������� � �������� ������ ��������������
    {
        return "Mew!";
    }

    virtual const std::string GetType() const override
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

    virtual const std::string Vocalize() const override
    {
        return "Woof!";
    }

    virtual const std::string GetType() const override
    {
        return AsText(Dog);
    }
};


int main()
{
    std::vector<Pet*> pets;  //@NOTE ��������� ��� �������� ������

    pets.push_back(new Cat("Barsik"));
    pets.push_back(new Cat("Pulya"));
    pets.push_back(new Dog("Reks"));
    pets.push_back(new Cat("Manya"));
    pets.push_back(new Dog("Belysh"));

    for (const Pet* pet : pets)
    {
        cout << "Type: " << pet->GetType() << "\n";
        cout << "Name: " << pet->GetName() << "\n";
        cout << "Voice: \"" << pet->Vocalize() << "\"\n";
    }

    return 0;
}

