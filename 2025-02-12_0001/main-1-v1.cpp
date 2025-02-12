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

    std::shared_ptr<int> p_number = gp_number.lock();

    cout
        << "[После gp_number.lock()] gp_number.use_count() == "
        << gp_number.use_count()
        << "\n"
    ;;
    
    if (p_number)
    {
        cout << "Значение по указателю: " << *p_number << "\n";
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
