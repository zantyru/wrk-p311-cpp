#include <limits>
#include <string>
#include <iostream>
using std::cout;
using std::cin;


char GetChar()
{
    char result{};
    std::string rawInput{};

    cin.clear();  // ���������
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

    cout << "������� ��������� ��������: ";
    cin.getline(symbols, SYMBOL_COUNT);
    cin.clear(std::ios::eofbit);  // ��������
    
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
    cout << "���� ��������� ��������: " << cin.gcount() << "\n";

    if (!cin.eof())
    {
        // ��� ������ ������ ������ ����� ��� ������� �������������
        // ���������� ��������� � ��� ����� �����������. �������
        // �������� � � ���� if
        cout << "��� ���������� �������: " << cin.peek() << "\n";
    }
    
    //

    cout << "��������� ���� ������.\n";

    //

    char answer{};

    do
    {
        // ���� �� ������� ����� ����� ����� �������� (������
        // ��� ����� SYMBOL_COUNT), �� ��� �������� ��������������
        // ���� ������� ������� �� ���������� � ������
        cout << "������� ���� ������ (`!` - �����): ";
        answer = GetChar();
        cout << "�� �����: " << answer << "\n";
    }
    while (answer != '!');
    
    return 0;
}
