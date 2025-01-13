#include <iostream>
using std::cout;
using std::cin;


class Worker  // ���� ����� �����������, ������ ���...
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

    virtual void DoWork() = 0;  // ... ���� ������ ����������� �������-���� (������, ��� ��� = 0)

private:
    std::string _name;
};


int main()
{
    //Worker w;  // ���� ����������������, �� ����� ������ ��� ����������

    Worker* p_w{};  // ��� �����

    return 0;
}
