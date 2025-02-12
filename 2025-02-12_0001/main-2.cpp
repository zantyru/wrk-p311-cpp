#include <memory>
#include <iostream>
using std::cout;
using std::cin;


// Тут с weak_ptr не будет проблем с циклическими ссылками


struct Player
{
    std::weak_ptr<Player> P_Companion;
    
    ~Player()
    {
        cout << "~Player()\n";
    }
};


int main()
{
    setlocale(LC_ALL, "Russian");

    std::shared_ptr<Player> p_jasmine = std::make_shared<Player>();
    std::shared_ptr<Player> p_albert = std::make_shared<Player>();

    p_jasmine->P_Companion = p_albert;
    p_albert->P_Companion = p_jasmine;

    return 0;
}
