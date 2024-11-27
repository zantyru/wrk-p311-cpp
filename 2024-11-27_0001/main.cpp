#include <iostream>
using std::cout;


int main()
{
    std::string s = "(Hello, class!)";

    for (const auto& e : s)
    {
        cout << e << "  ";
    }
    
    cout << "\n";


    for (char e : s)
    {
        cout << e << "  ";
    }

    cout << "\n";

    //

    for (auto& e : s)
    {
        e = '-';
    }

    for (const auto& e : s)
    {
        cout << e << "  ";
    }

    cout << "\n";
}



