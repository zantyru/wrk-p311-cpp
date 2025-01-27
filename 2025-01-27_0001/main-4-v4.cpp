#include <iostream>
using std::cout;
using std::cin;


int main()
{
    float x = 2.3f;
    int t1 = x;
    int t2{ static_cast<int>(x) };  // Преобразование в стиле Си++ (вариант Б)

    cout << "x: " << x << "\n";
    cout << "t1: " << t1 << "\n";
    cout << "t2: " << t2 << "\n";

    return 0;
}
