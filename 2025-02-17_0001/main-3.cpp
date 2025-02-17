#include <iostream>
using std::cout;
using std::cin;


void print(const std::string& text)
{
    cout
        << "---\n"
        << text << "\n"
        << "---\n"
    ;;
}


int main()
{
    setlocale(LC_ALL, "Russian");

    auto lambdaPrint = [](const std::string& text)
    {
        cout
            << "---\n"
            << text << "\n"
            << "---\n"
        ;;
    };

    print("print");
    lambdaPrint("lambdaPrint");

    return 0;
}
