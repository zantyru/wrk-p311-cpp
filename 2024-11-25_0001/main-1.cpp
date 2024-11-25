#include <iostream>
using std::cout;


int main()
{
    // cout << "abc" + "xyz";

    std::string s1 = "abc";
    cout << s1 + "xyz\n";
    cout << "ttt" + s1 + "\n";

    std::string s2("text");
    std::string s3{'5', '6', '7', '#', '5'};
    std::string s4 = { 'v', 'b', 'n', 'm', '<', '>'};
    
    cout << s2 << "\n";
    cout << s2 + s1 << "\n";
    cout << s3 << "\n";
    cout << s4 << "\n";

    std::string s5 = s4;
    cout << s5 << "\n";
}