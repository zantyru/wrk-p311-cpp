#include <bitset>
#include <iostream>
using std::cout;
using std::cin;


union IntAndFloat
{
    float x;
    int y;
};


int main()
{
    IntAndFloat data;
    data.x = 1201347018.0127f;

    cout << "x: " << data.x << "\n";
    cout << "x (bitset): " << std::bitset<sizeof(data.x) * 8>(data.x) << "\n";

    cout << "\n";

    cout << "y: " << data.y << "\n";
    cout << "y (bitset): " << std::bitset<sizeof(data.y) * 8>(data.y) << "\n";

    return 0;
}
