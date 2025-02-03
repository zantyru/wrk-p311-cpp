#include <limits>
#include <string>
#include <iostream>
using std::cout;
using std::cin;


char GetChar()
{
    char result{};
    std::string rawInput{};

    cin.clear();  // ДОБАВЛЕНО
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
    cin.clear(std::ios::eofbit);  // ИЗМЕНЕНО
    
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

    if (!cin.eof())
    {
        // При пустом буфере потока ввода эта команда останавливает
        // выполнение программы и ждёт ввода пользовател. Поэтому
        // обернули её в блок if
        cout << "Код следующего символа: " << cin.peek() << "\n";
    }
    
    //

    cout << "Следующий ввод данных.\n";

    //

    char answer{};

    do
    {
        // Если на прошлом этапе ввели много символов (больше
        // или равно SYMBOL_COUNT), то тут случится автоматический
        // ввод первого символа из оставшихся в буфере
        cout << "Введите один символ (`!` - выход): ";
        answer = GetChar();
        cout << "Вы ввели: " << answer << "\n";
    }
    while (answer != '!');
    
    return 0;
}
