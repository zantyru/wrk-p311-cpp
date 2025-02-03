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

    cout << "'Плохой' ли поток: " << cin.bad() << "\n";
    cout << "Достигнут ли конец потока: " << cin.eof() << "\n";
    cout << "Было прочитано символов: " << cin.gcount() << "\n";  // ДОБАВЛЕНО

    //
        
    cin.clear();    
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    //

    cout << "Следующий ввод данных.\n";

    //

    char answer{};

    do
    {
        cout << "Введите один символ (`!` - выход): ";
        cin >> answer;
        cout << "Вы ввели: " << answer << "\n";
    }
    while (answer != '!');
    
    return 0;
}
