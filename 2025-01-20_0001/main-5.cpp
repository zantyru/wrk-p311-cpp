#include <iostream>
using std::cout;
using std::cin;


struct NumberLessThanMinimumException
{
    int wrongNumber;
};


struct NumberGreaterThanMaximumException
{
    int wrongNumber;
};


int GetNumber(int from, int to)
{
    int result{};

    cout << "Введите число от " << from << " до " << to << ":\n";
    cin >> result;

    if (result < from) throw NumberLessThanMinimumException{result};
    else if (result > to) throw NumberGreaterThanMaximumException{result};

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
    catch (const NumberLessThanMinimumException& e)
    {
        cout << "Ошибка: число " << e.wrongNumber << " меньше минимума\n";
        cout << "Выполняются операции для такого случая...\n";
        // Тут свой набор действий
    }
    catch (const NumberGreaterThanMaximumException& e)
    {
        cout << "Ошибка: число " << e.wrongNumber << " больше максимума\n";
        cout << "Предпринимаются шаги по устранению ошибки...\n";
        // И тут свой набор действий
    }

    cout << "Число: " << number << "\n";

    return 0;
}
