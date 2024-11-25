#include <string>
#include <iostream>
#include <algorithm>
using std::cout;
using std::cin;
using std::string;


int main()
{
    string s;
    cout << "Input text: ";
    std::getline(cin, s);

    cout << s << "\n";

    // Перевод в верхний регистр
    std::transform(s.begin(), s.end(), s.begin(), std::toupper);
    cout << s << "\n";

    return 0;
}