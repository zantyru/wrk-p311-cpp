#include <iostream>
using std::cout;
using std::cin;


int main()
{
    setlocale(LC_ALL, "Russian");

    cout << "����� �������� ����������.\n";
    throw "Exception demonstration.";
    cout << "��� ����� �� �� ������.\n";

    return 0;
}
