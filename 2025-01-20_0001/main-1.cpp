#include <iostream>
using std::cout;
using std::cin;


int main()
{
    setlocale(LC_ALL, "Russian");

    cout << "Перед выбросом исключения.\n";
    throw "Exception demonstration.";
    cout << "Это текст мы не увидим.\n";

    return 0;
}
