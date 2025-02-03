#include <limits>
#include <string>
#include <iostream>
using std::cout;
using std::cin;


char GetChar()
{
    char result{};
    std::string rawInput{};
    std::getline(cin, rawInput);

    if (rawInput.length() > 0)
    {
        result = rawInput[0];
    }

    return result;
}


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
    cout << "Было прочитано символов: " << cin.gcount() << "\n";
    cout << "Код следующего символа: " << cin.peek() << "\n";

    //

    cout << "Следующий ввод данных.\n";

    //

    char answer{};

    do
    {
        cout << "Введите один символ (`!` - выход): ";
        answer = GetChar();
        cout << "Вы ввели: " << answer << "\n";
    }
    while (answer != '!');
    
    return 0;
}
