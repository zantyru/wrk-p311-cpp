#include <iostream>
using std::cout;
using std::cin;


template <typename Lambda>
void DoAction(Lambda fn)
{
    int result = fn(1, 23);
    cout << "DoAction result: " << result << "\n";
}


int main()
{
    setlocale(LC_ALL, "Russian");

    DoAction(
        [](int x, int y) -> int
        {
            return 2 * x + y;
        }
    );

    int extra = 10;

    DoAction(
        [&exrta](int x, int y) -> int
        {
            return 2 * x + y * extra;
        }
    );

    return 0;
}
