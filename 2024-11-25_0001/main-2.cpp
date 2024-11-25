#include <iostream>
using std::cout;


int main()
{
    std::string s1 = "abcdef";
    std::string s2 = "12345678";
    cout << s1 + s2 << "\n";

    cout << "----------------------\n\n";

    std::string s3 = s1 + s2;
    cout << s3 << " " << &s3 << "\n";

    std::string s3v2 = s1 + s2;
    cout << s3v2 << " " << &s3v2 << "\n";

    std::string s4 = s3;
    cout << s4 << " " << &s4 << "\n";

    cout << "s1: " << s1 << "\n";
    cout << "s2: " << s2 << "\n";

    cout << "----------------------\n\n";

    s1 += s2;
    s1 = s1 + s2;
    cout << "s1: " << s1 << "\n";
    cout << "s2: " << s2 << "\n";

    s1.append(s2);  // Ёффективнее +, если нужно изменить исходную строку
    cout << "s1: " << s1 << "\n";
    cout << "s2: " << s2 << "\n";
}