#include <iostream>
using std::cout;
using std::cin;


int main()
{
    setlocale(LC_ALL, "Russian");

    // Блок обработки исключений try-catch

    try
    {
        cout << "Перед выбросом исключения.\n";
        throw "Exception demonstration.";
        cout << "Это текст мы не увидим.\n";
    }
    catch (...)  // Перехват всех исключений. Так писать не стоит
    {
        cout << "Какая-то ошибка\n";
    }

    return 0;
}
