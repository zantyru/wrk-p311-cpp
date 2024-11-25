#include <string>
#include <iostream>
using std::cout;
using std::string;


int main()
{
    string s = "Hello, world! 1 2 3 ()";

    if (s.empty()) cout << "String is empty.\n";
    else cout << "String is not empty.\n";

    cout << "String is " << (s.empty() ? "" : "not") << " empty.\n";

    return 0;
}