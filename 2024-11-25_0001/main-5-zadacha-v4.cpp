/*
��������� �������� �� ������������ ������
� ������������ � ��� �������, �� ��������
����� ������. ����� ���������� ��������
��������� ������� ��������� �� �����.
*/
#include <iostream> 
#include <string> 
#include <cstdlib> 
#include <ctime> 

void shuffleString(std::string& str) {
    std::srand(static_cast<unsigned int>(std::time(nullptr))); // ������������� 
    for (size_t i = 0; i < str.size(); ++i) {
        // ��������� ������� 
        size_t randIndex = std::rand() % str.size();
        std::swap(str[i], str[randIndex]); // ����� �������� 
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    std::string input;

    std::cout << "������� ������: ";
    std::getline(std::cin, input);

    shuffleString(input); // ������������� ������ 

    std::cout << "������������ ������: " << input << std::endl; // ����� �� ����� 

    return 0;
}
