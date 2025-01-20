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
    // ��������� ������ ������� ���������� ��� ������������
    // ����� (����� ������ ����)
    cin.exceptions(std::istream::failbit);

    int result{};

    cout << "������� ����� �� " << from << " �� " << to << ":\n";
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
        cout << "������: ����� " << e.wrongNumber << " ������ ��������\n";
        cout << "����������� �������� ��� ������ ������...\n";
        // ��� ���� ����� ��������
    }
    catch (const NumberGreaterThanMaximumException& e)
    {
        cout << "������: ����� " << e.wrongNumber << " ������ ���������\n";
        cout << "��������������� ���� �� ���������� ������...\n";
        // � ��� ���� ����� ��������
    }
    catch (const std::istream::failure& e)  // ������ ������������ ���� ����� ����������
    {
        cout << "������ ����� ������ �����: " << e.what() << "\n";
    }

    cout << "�����: " << number << "\n";

    return 0;
}
