/*
Компьютер получает от пользователя строку
и перемешивает в ней символы, не создавая
копии строки. После завершения операции
компьютер выводит результат на экран.
*/
#include <iostream> 
#include <string> 
#include <cstdlib> 
#include <ctime> 

void shuffleString(std::string& str) {
    std::srand(static_cast<unsigned int>(std::time(nullptr))); // инициализация 
    for (size_t i = 0; i < str.size(); ++i) {
        // генерация индекса 
        size_t randIndex = std::rand() % str.size();
        std::swap(str[i], str[randIndex]); // обмен символов 
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    std::string input;

    std::cout << "Введите строку: ";
    std::getline(std::cin, input);

    shuffleString(input); // перемешивание строки 

    std::cout << "Перемешанная строка: " << input << std::endl; // Вывод на экран 

    return 0;
}
