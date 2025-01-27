#include <vector>
#include <iostream>
using std::cout;
using std::cin;


class Summator
{
public:
    class Summand  // Слагаемое
    {
    public:
        Summand(int value)
            : _value{ value }
        {}

        operator int() const
        {
            return _value;
        }

    private:
        int _value;
    };

    void AddSummand(const Summand& summand)
    {
        _summands.push_back(summand);
    }

    void Clear()
    {
        _summands.clear();
    }

    operator int() const
    {
        int summa{};

        for (int x : _summands)
        {
            summa += x;
        }

        return summa;
    }

private:
    std::vector<Summand> _summands{};
};


int main()
{
    Summator summator;

    summator.AddSummand(Summator::Summand(3));
    summator.AddSummand(Summator::Summand(-4));
    summator.AddSummand(Summator::Summand(-2));
    summator.AddSummand(Summator::Summand(100));

    cout << "summator: " << summator << "\n";

    return 0;
}
