#include <iostream>
using std::cout;
using std::cin;


class Worker  // Этот класс абстрактный, потому что...
{
public:
    Worker(const std::string& name)
        : _name{ name }
    {}

    virtual ~Worker() = default;

    const std::string& GetName() const
    {
        return _name;
    }

    virtual void DoWork() = 0;  // ... есть чистая виртуальная функция-член (чистая, так как = 0)

private:
    std::string _name;
};


int main()
{
    //Worker w;  // Если раскомментироват, то будет ошибка при компиляции

    Worker* p_w{};  // Так можно

    return 0;
}
