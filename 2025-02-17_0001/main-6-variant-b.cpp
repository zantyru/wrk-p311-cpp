#include <array>
#include <vector>
#include <algorithm>
#include <iostream>
using std::cout;
using std::cin;


int main()
{
    setlocale(LC_ALL, "Russian");

    std::array<int, 12> numbersArray = {2, 4, 8, -1, 14, 3, 0, 3, 14, 65, 1, 7};
    std::vector<int> numbersVector = {2, 4, 8, -1, 14, 3, 0, 3, 14, 65, 1, 7};
    int bias = 4;

    // -- 1 --

    cout << "numbersArray:\n";
    
    std::for_each(
        numbersArray.begin(), numbersArray.end(),
        [&bias](int n)
        {
            if ((n + bias) % 7 == 0) cout << n << "\n";
        }
    );
    
    cout << "\n";

    // -- 2 --

    cout << "numbersVector:\n";

    std::for_each(
        numbersVector.begin(), numbersVector.end(),
        [&bias](int n)
        {
            if ((n + bias) % 7 == 0) cout << n << "\n";
        }
    );

    cout << "\n";

    return 0;
}
