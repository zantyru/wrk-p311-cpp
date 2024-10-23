#include <iostream>
using std::cout;
using std::cin;


class Point2D
{
public:
    float X;
    float Y;

    Point2D()
        : X{ 1.0f }
        , Y{ 1.0f }
    {
        cout << "Point2D | Default constructor\n";
    }
};


int main()
{
    cout << "Step 0\n";
    Point2D p1;

    cout << "Step 1\n";
    cout << "p1.X: " << p1.X << "\n";

    cout << "Step 2\n";
    p1.X = 7.5f;
    cout << "p1.X: " << p1.X << "\n";

    cout << "Step 3\n";
    Point2D p2 = p1;  // Эта операция никак не отобразится в консоли

    cout << "Step 4\n";
    cout << "p2.X: " << p2.X << "\n";

    return 0;
}