#include <limits>
#include <iostream>
using std::cout;
using std::cin;


int main()
{
    setlocale(LC_ALL, "Russian");

    const size_t SYMBOL_COUNT{ 12 };
    char symbols[SYMBOL_COUNT]{};

    //

    cout << "Введите несколько символов: ";
    cin.getline(symbols, SYMBOL_COUNT);
    
    //

    for (char c : symbols)
    {
        cout << c;
    }

    cout << '\n';

    cout
        << "Код последнего символа в массиве: "
        << int(symbols[SYMBOL_COUNT - 1])
        << "\n"
    ;

    //

    char answer{};

    // Не всегда срабатывает очистка
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max());

    cout << "Следующий ввод данных.\n";

    do
    {
        cout << "Введите один символ (`!` - выход): ";
        cin.clear();
        cin >> answer;
        cout << "Вы ввели: " << answer << "\n";
    }
    while (answer != '!');
    
    return 0;
}
