#include <iostream>
#include <string>
using std::cin;
using std::cout;


class CountdownCounter
{
public:
    CountdownCounter(int initialValue = 10)
        : _tick{ initialValue }
    {
        _instanceCount++;

        // Нестатический (обычный) метод
        // может обращаться к статическим
        // полям и статическим методам
    }

    ~CountdownCounter()
    {
        _instanceCount--;
    }

    static int GetInstanceCount() // Не может быть const
    {
        // Сюда указатель this НЕ ПЕРЕДАЁТСЯ!
        // Соответственно нельзя обратиться
        // к нестатическим (обычным) полям данных.
        // Как следствие статический метод
        // не может вызвать нестатический метод
        return _instanceCount;
    }

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
    static int _instanceCount;
    int _tick;
};

int CountdownCounter::_instanceCount = 0;


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


void DoDoubleTickAndShow(CountdownCounter& c)
{
    c.DoTick();
    c.DoTick();
    int v = c.GetValue();
    cout << "___***\n";
    ShowCountdownCounter(c);
    cout << "^^^***\n";
}


int main()
{
    cout << "---\n";
    cout << CountdownCounter::GetInstanceCount() << '\n';

    {
        cout << "---\n";
        CountdownCounter c1;
        cout << c1.GetInstanceCount() << '\n';

        {
            cout << "---\n";
            CountdownCounter c2, c3;
            cout << c1.GetInstanceCount() << '\n';
            cout << c2.GetInstanceCount() << '\n';
            cout << c3.GetInstanceCount() << '\n';
        }

        cout << "---\n";
        cout << c1.GetInstanceCount() << '\n';

        cout << "---\n";
        CountdownCounter c4;
        cout << c1.GetInstanceCount() << '\n';
        cout << c4.GetInstanceCount() << '\n';
    }

    cout << "---\n";
    cout << CountdownCounter::GetInstanceCount() << '\n';

    return 0;
}