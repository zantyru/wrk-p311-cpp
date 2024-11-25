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

    std::srand(static_cast<unsigned int>(std::time(0)));
    for (size_t i = str.size() - 1; i > 0; --i) {

        size_t j = std::rand() % (i + 1);

        std::swap(str[i], str[j]);
    }
}

int main() {
    std::string userInput;
    std::cout << "Enter a string: ";
    std::getline(std::cin, userInput);

    shuffleString(userInput);

    std::cout << "Shuffled string: " << userInput << std::endl;

    return 0;
}

