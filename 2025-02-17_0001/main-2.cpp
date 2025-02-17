#include <iostream>
using std::cout;
using std::cin;


int main()
{
    setlocale(LC_ALL, "Russian");

    // ��� ��������������, �� �� ����������
    //-------------------------------------

    []() { cout << "������ �� ��������!\n"; };

    []()
    {
        cout << "������ ����� �� ��������!\n";
    }; // <--- ����� � ������� �����!


    // ��� �������������� � ����������
    //-------------------------------------

    []() { cout << "������ ��������!\n"; }();

    []()
    {
        cout << "������ ����� ��������!\n";
    }();  // <--- ��������� ( � )


    // ���� ��� �������������� � ���������� ����
    //------------------------------------------

    [] { cout << "������ �������� �������!\n"; }();

    []
    {
        cout << "������ ����� �������� �������!\n";
    }();  // <--- ��������� ( � )


    // � ���� ��� �������������� � ���������� ����
    //--------------------------------------------

    auto lambdaFnOne = [] { cout << "������ ��������.\n"; };

    auto lambdaFnTwo{
        [] { cout << "������ �������� �����.\n"; }
    };

    lambdaFnOne();
    lambdaFnTwo();

    return 0;
}
