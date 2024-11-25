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
    std::wstring str;
    std::wcout << L"������� ������: ";

    wchar_t ch;
    while (std::wcin.get(ch) && ch != L'\n') {
        str += ch;
    }

    const int length = str.length();
    for (int i = 0; i < length; ++i) {
        int j = (i + 1 + i * 7) % length;

        wchar_t temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }

    std::wcout << L"������������ ������: " << str << std::endl;

    return 0;
}
