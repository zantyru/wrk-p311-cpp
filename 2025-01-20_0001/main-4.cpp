#include <iostream>
using std::cout;
using std::cin;


int GetNumber(int from, int to)
{
    int result{};

    cout << "������� ����� �� " << from << " �� " << to << ":\n";
    cin >> result;

    if (result < from) throw "�������� ����� ������ ������������.";
    else if (result > to) throw "�������� ����� ������ ������������.";

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
        // ����� �� �� ������. ��� ����������� ����������
        // ���������������. �� ���� ���� "��": ��������
        // ��������� ��������� ������� �� ������ ����������.
        // � ������ ������ ������� ������ ���� if-else
        // � ���������� ��-������.

        cout << "������: " << errorText << "\n";
    }

    cout << "�����: " << number << "\n";

    return 0;
}
