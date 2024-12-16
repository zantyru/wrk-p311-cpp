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


int main()
{
    setlocale(LC_ALL, "Russian");

    

    return 0;
}

