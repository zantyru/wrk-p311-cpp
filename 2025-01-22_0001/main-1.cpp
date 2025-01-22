#include <string>
#include <exception>
#include <iostream>
using std::cout;
using std::cin;


class WrongMenuItemNumberException : public std::exception
{
public:
    WrongMenuItemNumberException(const std::string& message)
        : exception{}
        , _message{ message }
    {}

    virtual const char* what() const override
    {
        return _message.c_str();
    }

private:
    std::string _message;
};


int ProcessMenu()
{
    cin.exceptions(std::istream::failbit);

    int result{};

    cout
        << "1 - Операция А\n"
        << "2 - Операция Б\n"
        << "3 - Операция В\n"
        << "0 - Выход\n"
    ;;
    cin >> result;

    if (result < 0 || result > 3)
    {
        throw WrongMenuItemNumberException(
            std::string("Несуществующий пункт меню номер ")
            + std::to_string(result) + "."
        );
    }

    return result;
}


int main()
{
    setlocale(LC_ALL, "Russian");

    try
    {
        int menuItemNumber = ProcessMenu();
        cout << "Выбран пункт меню номер " << menuItemNumber << ".\n";
    }
    catch (const std::exception& e)
    {
        cout << "Ошибка (общая): " << e.what() << "\n";
    }
    catch (const WrongMenuItemNumberException& e)
    {
        cout << "Ошибка: " << e.what() << "\n";
    }

    return 0;
}
