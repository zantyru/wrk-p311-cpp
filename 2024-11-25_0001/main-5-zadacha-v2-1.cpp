/*
Компьютер получает от пользователя строку
и перемешивает в ней символы, не создавая
копии строки. После завершения операции
компьютер выводит результат на экран.
*/
#include <iostream> 
#include <string> 

int main() {
    setlocale(LC_ALL, "Russian");
    std::string str;
    std::cout << "Введите строку: ";

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

    std::cout << "Перемешанная строка: " << str << std::endl;

    return 0;
}
