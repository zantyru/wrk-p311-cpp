#include <iostream>
using std::cout;
using std::cin;


int main()
{
    setlocale(LC_ALL, "Russian");

    // ���� ��������� ���������� try-catch

    try
    {
        cout << "����� �������� ����������.\n";
        throw "Exception demonstration.";
        cout << "��� ����� �� �� ������.\n";
    }
    catch (...)  // �������� ���� ����������. ��� ������ �� �����
    {
        cout << "�����-�� ������\n";
    }

    return 0;
}
