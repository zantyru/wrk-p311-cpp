#include <string>
#include <iostream>
#include <algorithm>
#include <functional> // Для std::bind1st
using std::cout;
using std::cin;
using std::string;


template <typename Ch, typename Tr, typename Al>
void ToUpper(
        std::basic_string<Ch, Tr, Al>& str,
        const std::locale& loc = std::locale()
)
{
    std::transform(
        str.begin(),
        str.end(),
        str.begin(),
        std::bind1st(
            std::mem_fun<Ch, std::ctype<Ch>, Ch>(&std::ctype<Ch>::toupper),
            &std::use_facet<std::ctype<Ch> >(loc)
        )
    );
}


int main()
{
    string s;
    cout << "Input text: ";
    std::getline(cin, s);

    cout << s << "\n";

    // Перевод в верхний регистр
    ToUpper(s);
    cout << s << "\n";

    return 0;
}