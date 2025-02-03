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

    cout << "������� ��������� ��������: ";
    cin.getline(symbols, SYMBOL_COUNT);
    
    //

    for (char c : symbols)
    {
        cout << c;
    }

    cout << '\n';

    cout
        << "��� ���������� ������� � �������: "
        << int(symbols[SYMBOL_COUNT - 1])
        << "\n"
    ;

    //

    cout << "'������' �� �����: " << cin.bad() << "\n";
    cout << "��������� �� ����� ������: " << cin.eof() << "\n";
    cout << "���� ��������� ��������: " << cin.gcount() << "\n";  // ���������

    //
        
    cin.clear();    
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    //

    cout << "��������� ���� ������.\n";

    //

    char answer{};

    do
    {
        cout << "������� ���� ������ (`!` - �����): ";
        cin >> answer;
        cout << "�� �����: " << answer << "\n";
    }
    while (answer != '!');
    
    return 0;
}
