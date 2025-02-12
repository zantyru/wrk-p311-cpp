#include <memory>
#include <iostream>
using std::cout;
using std::cin;


std::weak_ptr<int> gp_number;


void Observe()
{
    cout
        << "gp_number.use_count() == "
        << gp_number.use_count()
        << "\n"
    ;;
    
    if (!gp_number.expired())
    {
        cout << "Значение по указателю: " << *gp_number.lock() << "\n";
    }
    else
    {
        cout << "Данных больше нет.\n";
    }

    cout << "\n\n";
}


int main()
{
    setlocale(LC_ALL, "Russian");

    {
        std::shared_ptr<int> p = std::make_shared<int>(1000);
        gp_number = p;

        Observe();
    }

    Observe();

    return 0;
}
