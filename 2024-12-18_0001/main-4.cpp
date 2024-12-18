#include <iostream>
using std::cout;
using std::cin;


class Militancy
{
public:
    Militancy(int attackPoints = 1)
        : _attackPoints{ attackPoints }
    {}

    int Kick() const
    {
        return _attackPoints;
    }

    int Dash() const
    {
        return _attackPoints * 2;
    }

protected:
    int _attackPoints;
};


class Spirituality
{
public:
    Spirituality(int prayPoints = 1)
        : _prayPoints{ prayPoints }
    {}

    int Encourage() const
    {
        return _prayPoints;
    }

    int Heal() const
    {
        return _prayPoints * 3 / 2 ;
    }
    
    int Undemonize() const
    {
        return _prayPoints / 2;
    }

protected:
    int _prayPoints;
};


class Wizardry
{
public:
    Wizardry(int manaPoints = 1)
        : _manaPoints{ manaPoints }
    {}

    int CastSpell() const
    {
        return _manaPoints;
    }

    int ThrowFireball() const
    {
        return _manaPoints / 5;
    }

protected:
    int _manaPoints;
};


class Paladin : public Militancy, public Spirituality
{
public:
    Paladin()
        : Militancy{ 3 }
        , Spirituality{ 5 }
    {}
};


class Admin : public Militancy, public Spirituality, public Wizardry
{
public:
    Admin()
        : Militancy{ 1000 }
        , Spirituality{ 1000 }
        , Wizardry{ 1000 }
    {}
};


class GrandPaladin : public Paladin
{
    //...
};


int main()
{

    return 0;
}
