#include <vector>
#include <iostream>
using std::cout;
using std::cin;
using std::string;
using std::vector;


class Object
{
public:
    Object() = default;
    
    Object(const Object& other) = delete;
    
    virtual ~Object() = default;

    Object& operator=(const Object& other) = delete;

    virtual string GetType() const = 0;

    virtual void DoAction() = 0;
};


class Cup : public Object
{
public:
    Cup() = default;

    virtual string GetType() const override
    {
        return string("Cup");
    }

    virtual void DoAction() override
    {
        cout << "+.+.+.+.+.+.+.+.+.+.+.+.+\n";
    }
};


class Chocolate : public Object
{
public:
    Chocolate() = default;

    virtual string GetType() const override
    {
        return string("Chocolate");
    }

    virtual void DoAction() override
    {
        cout << "* * * *\n*     *\n* * * *\n";
    }

    void DoChocolateWork() const
    {
        cout << "choco-choco-choco...\n";
    }
};


int main()
{
    vector<Object*> objects = {
        new Cup(),
        new Cup(),
        new Chocolate(),
        new Cup(),
        new Chocolate(),
        new Chocolate(),
        new Chocolate(),
        new Chocolate(),
    };

    // 1

    for (Object* p : objects)
    {
        p->DoAction();
    }

    cout << "\n- - - - - - -\n\n";

    // 2

    for (Object* p : objects)
    {
        Chocolate* p_ch = dynamic_cast<Chocolate*>(p);

        if (p_ch)
        {
            p_ch->DoChocolateWork();
        }
        else
        {
            cout << "x\n";
        }
    }

    cout << "\n- - - - - - -\n\n";

    // 3

    for (Object* p : objects)
    {
        string objectType = p->GetType();

        if ("Cup" == objectType)
        {
            dynamic_cast<Cup*>(p)->DoAction();
        }
        else if ("Chocolate" == objectType)
        {
            dynamic_cast<Chocolate*>(p)->DoAction();
            dynamic_cast<Chocolate*>(p)->DoChocolateWork();
        }
        else
        {
            cout << "x\n";
        }

    }

    cout << "\n- - - - - - -\n\n";

    // 4

    Cup cup;
    Object* p = dynamic_cast<Object*>(&cup);

    cout << p->GetType() << "\n";
    p->DoAction();


    return 0;
}
