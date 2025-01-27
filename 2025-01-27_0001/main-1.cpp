#include <iostream>
using std::cout;
using std::cin;


namespace garden
{
    int x{};
}


std::string x{"global"};


int main()
{
    garden::x = 12;
    cout << "garden::x " << garden::x << "\n";

    int x = -17;
    cout << "x " << x << "\n";

    // Обращение к глобальной переменной (или
    // имени вообще)
    cout << "::x " << ::x << "\n";

    return 0;
}
