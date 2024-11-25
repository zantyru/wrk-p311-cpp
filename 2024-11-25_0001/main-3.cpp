#include <iostream>
using std::cout;


int main()
{
    //                  0123456789...
    std::string text = "rfgju 1 efv";
    cout << text << "\n";
    cout << text[6] << "\n";

    char symbol = text[2];
    cout << symbol << "\n";

    cout << "------------------\n\n";

    text[1] = '!';
    cout << text << "\n";

    cout << "------------------\n\n";

    cout << text << "\n";
    cout << "text.size(): "  << text.size() << "\n";
    cout << "text.length(): " << text.length() << "\n";

    cout << "------------------\n\n";

    std::string message = "Да!";  // Не всегда длина = 3
    cout << message << "\n";
    cout << "message.size(): " << message.size() << "\n";
    cout << "message.length(): " << message.length() << "\n";
    
}