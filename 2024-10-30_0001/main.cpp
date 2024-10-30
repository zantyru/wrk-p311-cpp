#include <iostream>


class Bottle
{
public:
    Bottle(int totalVolume = 3)
        : _totalVolume{ totalVolume }
        , _liquidVolume{ 0 }
    {
        if (_totalVolume < 0) _totalVolume = 0;
    }

    int GetTotalVolume()
    {
        return _totalVolume;
    }

    int GetLiquidVolume()
    {
        return _liquidVolume;
    }

    void Pour(int volume)
    {
        if (volume < 0) volume = 0;

        _liquidVolume += volume;

        if (_liquidVolume > _totalVolume) _liquidVolume = _totalVolume;
    }

    void Drain(int volume)
    {
        if (volume < 0) volume = 0;

        _liquidVolume -= volume;

        if (_liquidVolume < 0) _liquidVolume = 0;
    }

private:
    int _totalVolume;
    int _liquidVolume;
};


int main()
{
    Bottle b;

    

    return 0;
}