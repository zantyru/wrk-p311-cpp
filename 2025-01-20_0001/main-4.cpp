#include <iostream>
using std::cout;
using std::cin;


int GetNumber(int from, int to)
{
    int result{};

    cout << "Введите число от " << from << " до " << to << ":\n";
    cin >> result;

    if (result < from) throw "Введённое число меньше минимального.";
    else if (result > to) throw "Введённое число больше минимального.";

    return result;
}


int main()
{
    setlocale(LC_ALL, "Russian");

    int number{};

    try
    {
        number = GetNumber(3, 7);
    }
    catch (const char* errorText)
    {
        // Вроде бы всё хорошо. Все необходимые исключения
        // перехватываются. Но есть одно "но": неудобно
        // описывать различные реакции на разные исключения.
        // В данном случае придётся писать блок if-else
        // и сравнивать си-строки.

        cout << "Ошибка: " << errorText << "\n";
    }

    cout << "Число: " << number << "\n";

    return 0;
}
