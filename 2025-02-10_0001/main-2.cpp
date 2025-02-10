#include <memory>
#include <string>  // Для std::to_string
#include <iostream>
using std::cout;
using std::cin;


class Battary
{
public:
    Battary(int energy)
        : _energy{ energy }
    {
        if (_energy < 0) energy = 0;
    }

    int UseEnergy()
    {
        if (_energy == 0) return 0;

        --_energy;

        return 1;
    }

    int GetEnergy() const
    {
        return _energy;
    }

private:
    int _energy;
};


class Flashlight
{
public:
    Flashlight()
        : _p_battary{}
    {}

    ~Flashlight() = default;

    void Enable()
    {
        if (_p_battary == nullptr) return;

        if (_p_battary->GetEnergy() == 0) return;

        _isEnabled = true;
    }

    void Disable()
    {
        _isEnabled = false;
    }

    bool IsEnabled() const
    {
        return _isEnabled;
    }

    bool HasBattary() const
    {
        return _p_battary != nullptr;
    }

    void Use()
    {
        if (!_isEnabled) return;

        _p_battary->UseEnergy();

        if (_p_battary->GetEnergy() == 0) Disable();
    }

    std::unique_ptr<Battary> SetupBattary(std::unique_ptr<Battary>& p_newBattary)
    {
        std::unique_ptr<Battary> p_oldBattary = std::move(_p_battary);
        _p_battary = std::move(p_newBattary);

        return p_oldBattary;
    }

private:
    bool _isEnabled;
    std::unique_ptr<Battary> _p_battary;
};


int main()
{
    setlocale(LC_ALL, "Russian");

    std::unique_ptr<Battary> p_battary = std::make_unique<Battary>(10);

    Flashlight flOne;
    Flashlight flTwo;

    cout << "1.\n";
    cout << "flOne.HasBattary(): " << flOne.HasBattary() << "\n";
    cout << "flTwo.HasBattary(): " << flTwo.HasBattary() << "\n";
    cout << "\n";

    //

    flOne.SetupBattary(p_battary);
    flTwo.SetupBattary(p_battary);  // На этом шаге p_battary уже не ссылается на батарейку
    flOne.Enable();
    flTwo.Enable();

    cout << "2.\n";
    cout << "flOne.HasBattary(): " << flOne.HasBattary() << "\n";
    cout << "flOne.IsEnabled(): " << flOne.IsEnabled() << "\n";
    cout << "flTwo.HasBattary(): " << flTwo.HasBattary() << "\n";
    cout << "flTwo.IsEnabled(): " << flTwo.IsEnabled() << "\n";
    cout << "\n";
    

    return 0;
}
