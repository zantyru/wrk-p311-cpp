#include <iostream>
using std::cout;
using std::cin;


class Base
{
public:
    int x{ -1 };

protected:
    int _y{ 77 };

private:
    int _z{ -9 };
};


class DerivedPublicaly : public Base
{
public:
    void PrintFields() const
    {
        cout << "[DerivedPublicaly] x: " << x << "\n";
        cout << "[DerivedPublicaly] _y: " << _y << "\n";
    }
};


class DerivedProtectedly : protected Base
{
public:
    void PrintFields() const
    {
        cout << "[DerivedProtectedly] x: " << x << "\n";  // � ���� ������ ���� `x` ��� ����� ������������ ������� ������ protected
        cout << "[DerivedProtectedly] _y: " << _y << "\n";
    }
};


class DerivedPrivately : private Base
{
public:
    void PrintFields() const
    {
        cout << "[DerivedPrivately] x: " << x << "\n";
        cout << "[DerivedPrivately] _y: " << _y << "\n";
    }
};


class Y : public DerivedPrivately
{
public:
    void PrintFields() const
    {
        // ��� ��� ������� � ����� `x` � `_y`, ��� ���
        // � ������ DerivedPrivately ��� ���� ����� 
        // ������������ ������� private
        //cout << "[Y] x: " << x << "\n";
        //cout << "[Y] _y: " << _y << "\n";
    }
};


int main()
{
    DerivedPublicaly dpublic;
    dpublic.x = 1000;
    dpublic.PrintFields();

    DerivedProtectedly dprotected;
    // dprotected.x = 1001;  // ���� `x` ����� ����������
    dprotected.PrintFields();

    DerivedPrivately dprivate;
    // dprotected.x = 1001;  // ���� `x` ����� ��������� (�������)
    dprivate.PrintFields();

    Y y;
    y.PrintFields();

    return 0;
}
 