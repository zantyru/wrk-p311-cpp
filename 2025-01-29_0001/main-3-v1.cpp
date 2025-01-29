#include <bitset>
#include <iostream>
using std::cout;
using std::cin;


int main()
{
    float x = 1201347018.0127f;
    int y = *reinterpret_cast<int*>(&x);
    float z = *reinterpret_cast<float*>(&y);

    cout << "x: " << x << "\n";
    cout << "x (bitset): " << std::bitset<sizeof(x) * 8>(x) << "\n";

    cout << "\n";

    cout << "y: " << y << "\n";
    cout << "y (bitset): " << std::bitset<sizeof(y) * 8>(y) << "\n";

    cout << "\n";

    cout << "z: " << z << "\n";
    cout << "z (bitset): " << std::bitset<sizeof(z) * 8>(z) << "\n";

    return 0;
}
