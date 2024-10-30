#include <iostream>
using std::cout;


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

    int Pour(int volume)
    {
        int pouredVolume{};
        int availableVolume{ _totalVolume - _liquidVolume };

        if (volume < 0) volume = 0;

        pouredVolume = (volume < availableVolume) ? volume : availableVolume;
        _liquidVolume += pouredVolume;

        return pouredVolume;
    }

    int Drain(int volume)
    {
        int drainedVolume{};

        if (volume < 0) volume = 0;

        drainedVolume = (volume < _liquidVolume) ? volume : _liquidVolume;
        _liquidVolume -= drainedVolume;

        return drainedVolume;
    }

private:
    int _totalVolume;
    int _liquidVolume;
};


int main()
{
    Bottle b{ 10 };

    cout << "\n[1]\n";
    cout << "b total volume: " << b.GetTotalVolume() << "\n";
    cout << "b liquid volume: " << b.GetLiquidVolume() << "\n";

    int pouredVolume = b.Pour(7);

    cout << "\n[2]\n";
    cout << "b total volume: " << b.GetTotalVolume() << "\n";
    cout << "b liquid volume: " << b.GetLiquidVolume() << "\n";
    cout << "b poured volume: " << pouredVolume << "\n";

    pouredVolume = b.Pour(4);

    cout << "\n[3]\n";
    cout << "b total volume: " << b.GetTotalVolume() << "\n";
    cout << "b liquid volume: " << b.GetLiquidVolume() << "\n";
    cout << "b poured volume: " << pouredVolume << "\n";

    int drainedVolume = b.Drain(1);

    cout << "\n[4]\n";
    cout << "b total volume: " << b.GetTotalVolume() << "\n";
    cout << "b liquid volume: " << b.GetLiquidVolume() << "\n";
    cout << "b drained volume: " << drainedVolume << "\n";

    drainedVolume = b.Drain(100);

    cout << "\n[5]\n";
    cout << "b total volume: " << b.GetTotalVolume() << "\n";
    cout << "b liquid volume: " << b.GetLiquidVolume() << "\n";
    cout << "b drained volume: " << drainedVolume << "\n";

    

    return 0;
}