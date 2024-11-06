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
    {
        cout << "\n___[1]___\n";

        CountdownCounter counter(3);

        do
        {
            ShowCountdownCounter(counter);
            counter.DoTick();
        } while (counter.GetValue() != 0);

        ShowCountdownCounter(counter);
    }

    {
        cout << "\n___[2]___\n";

        CountdownCounter counter(-4);

        do
        {
            ShowCountdownCounter(counter);
            counter.DoTick();
        } while (counter.GetValue() != 0);

        ShowCountdownCounter(counter);
    }


    return 0;
}