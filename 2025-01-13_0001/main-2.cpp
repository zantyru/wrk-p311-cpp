#include <iostream>
using std::cout;
using std::cin;


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

    virtual void DoWork() = 0;

private:
    std::string _name;
};


class WorkerWithHammer : public Worker
{
public:
    WorkerWithHammer(const std::string& name)
        : Worker{ name }
    {}

    virtual void DoWork() override
    {
        cout << "Boom-boom!\n";
    }
};


int main()
{
    //Worker w;  // Если раскомментировать, то будет ошибка при компиляции

    Worker* p_w{};  // Так можно
    p_w = new WorkerWithHammer{"Tom"};
    cout << p_w->GetName() << ": ";
    p_w->DoWork();
    delete p_w;
    p_w = nullptr;

    WorkerWithHammer wwh{"Ronald"};
    cout << wwh.GetName() << ": ";
    wwh.DoWork();

    return 0;
}
