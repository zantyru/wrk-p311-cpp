#include <iostream>
using std::cout;
using std::cin;


int main()
{
    setlocale(LC_ALL, "Russian");

    int x = 5;
    cout << "x: " << x << "\n";

    [&x]() { ++x; }();  // ������-������� ����������� `x` �� ������
    cout << "x: " << x << "\n";

    return 0;
}
