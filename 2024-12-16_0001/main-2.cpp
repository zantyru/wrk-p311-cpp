#include <iostream>
using std::cout;
using std::cin;


struct Data
{
    int value;
    float part;
    std::string text;
};


Data& CreateData()
{
    Data data;
    data.value = 10;
    data.part = 0.5f;
    data.text = "This is a message.";

    return data;  // Ой-ой-ой. Возврат ссылка на локальную переменную
}


int main()
{
    setlocale(LC_ALL, "Russian");

    Data d = CreateData();

    cout << "d.value: " << d.value << "\n";
    cout << "d.part: " << d.part << "\n";
    cout << "d.text: " << d.text << "\n";  // Нет текста :^(

    return 0;
}

