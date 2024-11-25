#include <string>
#include <iostream>
using std::cout;
using std::cin;


int main()
{
    std::string text;

    cout << "Input text: ";
    std::getline(cin, text);
    
    cout << "Input: " << text << "\n";
}