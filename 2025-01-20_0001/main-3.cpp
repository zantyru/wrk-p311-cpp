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
    catch (const char* errorText)  // �������� ���� ����������. ��� ������ �� �����
    {
        cout << "�����-�� ������: " << errorText << "\n";
    }

    return 0;
}
