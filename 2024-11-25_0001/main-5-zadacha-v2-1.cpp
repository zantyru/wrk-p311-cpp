/*
��������� �������� �� ������������ ������
� ������������ � ��� �������, �� ��������
����� ������. ����� ���������� ��������
��������� ������� ��������� �� �����.
*/
#include <iostream> 
#include <string> 

int main() {
    setlocale(LC_ALL, "Russian");
    std::string str;
    std::cout << "������� ������: ";

    char ch;
    while (std::cin.get(ch) && ch != '\n') {
        str += ch;
    }

    const int length = str.length();
    for (int i = 0; i < length; ++i) {
        int j = (i + 1 + i * 7) % length;

        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }

    std::cout << "������������ ������: " << str << std::endl;

    return 0;
}
