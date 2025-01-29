#include <bitset>
#include <iostream>
using std::cout;
using std::cin;


int main()
{
    unsigned int value = 0;
    char password[4] = {'c', '0', '1', 'a'};

    value = *reinterpret_cast<unsigned int*>(password);

    cout << "value: " << value << "\n";

    return 0;
}
