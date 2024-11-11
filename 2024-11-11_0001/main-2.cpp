#include <iostream>
using std::cout;
using std::cin;


class Bottle
{
public:
    explicit Bottle(int totalVolume = 3)
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

    int TransfuseFrom(Bottle& other)
    {
        int availableVolume{ _totalVolume - _liquidVolume };
        int transfusedVolume{
            (other._liquidVolume < availableVolume)
            ? other._liquidVolume
            : availableVolume
        };

        other._liquidVolume -= transfusedVolume;
        _liquidVolume += transfusedVolume;

        return transfusedVolume;
    }

    int TransfuseTo(Bottle& other)
    {
        return other.TransfuseFrom(*this);
    }

    int operator<<(Bottle& other)
    {
        return TransfuseFrom(other);
    }

    int operator>>(Bottle& other)
    {
        return other << *this;
    }

private:
    int _totalVolume;
    int _liquidVolume;
};


int main()
{
    Bottle b1(10);
    Bottle b2(3);

    b1.Pour(7);
    b2.Pour(1);

    // 1
    cout
        << "\n\n----\n"
        << "b1: " << b1.GetLiquidVolume() << "/" << b1.GetTotalVolume() << "\n"
        << "b2: " << b2.GetLiquidVolume() << "/" << b2.GetTotalVolume() << "\n"
    ;
    int trasfusedVolume = b1 << b2;
    cout << "b1 << b2: " << trasfusedVolume << "\n";

    // 2
    cout
        << "\n\n----\n"
        << "b1: " << b1.GetLiquidVolume() << "/" << b1.GetTotalVolume() << "\n"
        << "b2: " << b2.GetLiquidVolume() << "/" << b2.GetTotalVolume() << "\n"
    ;
    trasfusedVolume = b1 >> b2;
    cout << "b1 >> b2: " << trasfusedVolume << "\n";

    // 3
    cout
        << "\n\n----\n"
        << "b1: " << b1.GetLiquidVolume() << "/" << b1.GetTotalVolume() << "\n"
        << "b2: " << b2.GetLiquidVolume() << "/" << b2.GetTotalVolume() << "\n"
    ;

    return 0;
};