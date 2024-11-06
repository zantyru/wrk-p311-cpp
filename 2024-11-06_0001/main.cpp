#include <iostream>
#include <string>
using std::cin;
using std::cout;


class CountdownCounter
{
public:
    CountdownCounter(int initialValue = 10)
        : _tick{ initialValue }
    { }

    void DoTick()
    {
        if (_tick > 0) _tick--;
        else if (_tick < 0) _tick++;
    }

    int GetValue() const
    {
        return _tick;
    }

private:
    int _tick;
};


void ShowCountdownCounter(const CountdownCounter& c)
{
    std::string valueAsText = std::to_string(c.GetValue());
    std::string line = std::string(valueAsText.length() + 2, '-');

    cout
        << line << '\n'
        << '|' << valueAsText << '|' << '\n'
        << line << '\n'
    ;;
}


int main()
{
    CountdownCounter c1(3);

    do
    {
        ShowCountdownCounter(c1);
        c1.DoTick();
    }
    while (c1.GetValue() != 0);

    ShowCountdownCounter(c1);

    return 0;
}