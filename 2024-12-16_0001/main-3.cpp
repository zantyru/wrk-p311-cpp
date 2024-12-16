#include <iostream>
using std::cout;
using std::cin;


class LightBulb
{
public:
    LightBulb()
        : _isEmittingLight{ false }
        , _durability{ 100 }
    {}

    void TurnPowerOn()
    {
        if (_durability <= 0 || _isEmittingLight) return;

        --_durability;
        _isEmittingLight = true;
    }

    void TurnPowerOff()
    {
        _isEmittingLight = false;
    }

    bool IsEmittingLight() const
    {
        return _isEmittingLight;
    }

private:
    bool _isEmittingLight;
    int _durability;
};


class Battary
{
    //...
};


class BattaryStorage
{
/*
* Экземпляры этого класса могут агрегировать в себе
* экземпляры класса Battary.
*/

public:

    BattaryStorage()
        : _insertedBattaryCount{ 0 }
        , _battaries{ nullptr, nullptr, nullptr }
    {}

    void InsertBattary(Battary* p_battary)
    {
        if (p_battary == nullptr) return;

        if (_insertedBattaryCount == 3) return;

        _battaries[_insertedBattaryCount++] = p_battary;
    }

    Battary* RemoveBattary()
    {
        if (_insertedBattaryCount == 0) return nullptr;

        Battary* p_battary = _battaries[--_insertedBattaryCount];
        _battaries[_insertedBattaryCount] = nullptr;

        return p_battary;
    }

    bool IsProvidingPowerSupply() const
    {
        return _insertedBattaryCount == 3;
    }

private:
    int _insertedBattaryCount;
    Battary* _battaries[3];
};


class Flashlight
{
/*
* Этот класс компонует в себе классы LightBulb
* и BattaryStorage. Тут как раз отношение "Композиция".
* При создании экземпляра данного класса создаются
* экземпляры классов LightBulb и BattaryStorage.
* Без них не может быть фонаря.
*/

public:

    void TurnOn()
    {
        if (!_battaryStorage.IsProvidingPowerSupply()) return;

        _lightbulb.TurnPowerOn();
    }

    void TurnOff()
    {
        _lightbulb.TurnPowerOff();
    }

    const LightBulb& GetLightBulb() const
    {
        return _lightbulb;
    }

    BattaryStorage& GetBattaryStorage()
    {
        return _battaryStorage;
    }

private:
    LightBulb _lightbulb;
    BattaryStorage _battaryStorage;
};



int main()
{
    setlocale(LC_ALL, "Russian");

    Flashlight fl;

    ///

    cout << "fl.TurnOn();\n";
    fl.TurnOn();
    
    ///

    cout
        << "fl.GetLightBulb().IsEmittingLight(): "
        << fl.GetLightBulb().IsEmittingLight() << "\n"
    ;;

    ///

    cout << "fl.GetBattaryStorage().InsertBattary(&battary); ...\n";
    Battary battary;
    fl.GetBattaryStorage().InsertBattary(&battary);
    fl.GetBattaryStorage().InsertBattary(&battary);  //@NOTE Обманка! Та же самая батарейка
    fl.GetBattaryStorage().InsertBattary(&battary);  //@NOTE Обманка! Та же самая батарейка

    ///

    cout << "fl.TurnOn();\n";
    fl.TurnOn();

    ///

    cout
        << "fl.GetLightBulb().IsEmittingLight(): "
        << fl.GetLightBulb().IsEmittingLight() << "\n"
    ;;

    ///

    cout << "fl.TurnOff();\n";
    fl.TurnOff();

    ///

    cout
        << "fl.GetLightBulb().IsEmittingLight(): "
        << fl.GetLightBulb().IsEmittingLight() << "\n"
    ;;

    return 0;
}

