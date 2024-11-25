#include <string>
#include <iostream>
using std::cout;
using std::string;


int main()
{
    string s = "Hello, world! 1 2 3 ()";

    // 1

    for (const char& c : s)
    {
        cout << c << "\n";
    }

    cout << string(12, '-') << "\n\n";

    // 2

    for (size_t i = 0; i < s.length(); i++)
    {
        cout << s[i] << "\n";
    }

    cout << string(12, '-') << "\n\n";

    // 3

    for (auto it = s.begin(); it < s.end(); it++)
    {
        cout << *it << "\n";
    }


    return 0;
}