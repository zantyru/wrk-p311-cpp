/*
��������� �������� �� ������������ ������
� ������������ � ��� �������, �� ��������
����� ������. ����� ���������� ��������
��������� ������� ��������� �� �����.
*/
#include <iostream>  // � ���� �� ���������� ������� ������������������������� � � ��������� ��� � ���������
#include <string>
#include <algorithm>
#include <random>
using namespace std;

int main() {
    string str;
    cout << "������� ������: ";
    getline(cin, str);

    // ��������� ���������� ����� ��� ������������� ���������� ��������� �����
    random_device rd;
    mt19937 rnd(rd());

    // ������������� ������ �� �����
    shuffle(str.begin(), str.end(), rnd);   // � �� ����� ���� ������

    cout << "������������ ������: " << str << endl;
    return 0;
}
