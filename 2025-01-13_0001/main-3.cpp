#include <iostream>
using std::cout;
using std::cin;


// Пример приёма/паттерна "Абстрактный метод"


class Worker
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

    std::string DoWork()
    {
        // Весь трюк в том, что в обычном методе,
        // который содержит какую-то общую логику,
        // вызывается виртуальный метод
        return _name + ": " + DoWork_Implementation();
    }

    virtual std::string DoWork_Implementation() = 0;

private:
    std::string _name;
};


class WorkerWithHammer : public Worker
{
public:
    WorkerWithHammer(const std::string& name)
        : Worker{ name }
    {}

    virtual std::string DoWork_Implementation() override
    {
        return "Boom-boom!";
    }
};


int main()
{
    //Worker w;  // Если раскомментировать, то будет ошибка при компиляции

    Worker* p_w{};  // Так можно
    p_w = new WorkerWithHammer{"Tom"};    
    cout << p_w->DoWork() << "\n";
    delete p_w;
    p_w = nullptr;

    WorkerWithHammer wwh{"Ronald"};
    cout << wwh.DoWork() << "\n";

    return 0;
}