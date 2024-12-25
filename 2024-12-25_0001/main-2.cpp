#include <string>
#include <vector>
#include <iostream>
using std::cout;
using std::cin;


class AudioSource
{
public:
    AudioSource(const std::string& sound, int period)
        : _period{ period }
        , _tickCount{ 0 }
        , _sound{ sound }
    {
        if (_period < 1) _period = 1;
    }

    const std::string &GetSound() const
    {
        if (_tickCount == 0) return _sound;

        return "";
    }

    int GetPeriod() const
    {
        return _period;
    }

    virtual void Update()
    {
        _tickCount += (_tickCount + 1) % _period;
    }

protected:
    void SetPeriod(int period)
    {
        _period = period;

        if (_period < 1) _period = 1;

        _tickCount = _tickCount % _period;
    }

private:
    int _period;
    int _tickCount;
    std::string _sound;
};


class ChangingPeriodAudioSource : public AudioSource
{
public:
    ChangingPeriodAudioSource(const std::string &sound, int period)
        : AudioSource{ sound, period }
    {}

    virtual void Update() override
    {
        int currentPeriod = GetPeriod();
        AudioSource::Update();

        if (currentPeriod > 1) SetPeriod(currentPeriod - 1);
    }
};


class FizzleAudioSource : public AudioSource
{
public:
    FizzleAudioSource(const std::string &sound, int period)
        : AudioSource{ sound, period }
        , _wasPeriodChanged{ false }
    {}

    virtual void Update() override
    {
        AudioSource::Update();

        if (GetSound() != "")
        {
            if (_wasPeriodChanged)
            {
                SetPeriod(GetPeriod() - 2);
                _wasPeriodChanged = false;
            }
            else
            {
                SetPeriod(GetPeriod() + 2);
                _wasPeriodChanged = true;
            }
        }
    }

private:
    bool _wasPeriodChanged;
};


int main()
{
    setlocale(LC_ALL, "Russian");

    std::vector<AudioSource *> instruments = {
        new AudioSource("Bum!", 3),
        new ChangingPeriodAudioSource("Tukk...", 7),
        new AudioSource("Ts!", 5),
        new FizzleAudioSource("Whipp-whipp.", 4),
    };

    std::string answer;

    do
    {
        cout << std::string(100, '\n');

        for (size_t i = 0; i < instruments.size(); ++i)
        {
            AudioSource *p_instrument = instruments[i];
            cout << i << ": " << p_instrument->GetSound() << "\n";
            p_instrument->Update();
        }

        cout
            << "\n"
            << "Нажмите ENTER для продолжения или введите\n"
            << "без кавычек \"exit\", чтобы выйти из програмы.\n"
            << "\n"
            << ">>> "
        ;;
        std::getline(cin, answer);
    }
    while (answer != "exit");

    return 0;
}

