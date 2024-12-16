#include <iostream>
using std::cout;
using std::cin;


int main()
{
    setlocale(LC_ALL, "Russian");

    // 1

    int* p_numbers = new int[10];
    p_numbers[3] = 7654;
    cout << "Создан динамический массив.\n";
    
    // 2

    int& ref_value = p_numbers[3];
    cout << "ref_value: " << ref_value << "\n";

    // 3

    ref_value += 1000;
    cout << "ref_value += 1000;\n";
    cout << "ref_value: " << ref_value << "\n";

    // 4

    delete[] p_numbers;
    p_numbers = nullptr;
    cout << "Память из-под массива освобождена.\n";
    cout << "ref_value: " << ref_value << "\n";  // Здесь использовать ref_value уже некорректно

    return 0;
}
