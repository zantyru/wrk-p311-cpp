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

    //

    char answer{};

    do
    {
        // Тут зациклится программа
        cout << "Введите один символ (`!` - выход): ";
        cin >> answer;
        cout << "Вы ввели: " << answer << "\n";
    }
    while (answer != '!');
    
    return 0;
}
