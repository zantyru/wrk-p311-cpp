#include <iostream>
using std::cout;
using std::cin;


class Square
{
public:
    explicit Square(float sideSize = 1)
        : _sideSize{ sideSize }
    {
        if (_sideSize < 0.0f) _sideSize = 0.0f;
    }

    float GetWidth() const
    {
        return _sideSize;
    }

    float GetHeight() const
    {
        return _sideSize;
    }

    float GetArea() const
    {
        return _sideSize * _sideSize;
    }

    Square operator+(const Square& other) const // *this + other
    {
        float resultArea = GetArea() + other.GetArea();
        
        return Square(sqrt(resultArea));
    }

    Square operator+(float otherArea) const
    {
        float resultArea = GetArea() + otherArea;

        return Square(sqrt(resultArea));
    }

    Square operator-(const Square& other) const
    {
        float resultArea = GetArea() - other.GetArea();

        if (resultArea < 0.0f) resultArea = 0.0f;

        return Square(sqrt(resultArea));
    }

    Square operator-(float otherArea) const
    {
        float resultArea = GetArea() - otherArea;

        if (resultArea < 0.0f) resultArea = 0.0f;

        return Square(sqrt(resultArea));
    }

private:
    float _sideSize;
};


int main()
{
    Square sqOne(4);
    Square sqTwo(2);
    cout << "sqOne.GetArea(): " << sqOne.GetArea() << " (sideSize: " << sqOne.GetWidth() << ")\n";
    cout << "sqTwo.GetArea(): " << sqTwo.GetArea() << " (sideSize: " << sqTwo.GetWidth() << ")\n";
    cout << "-----\n\n";

    sqOne = sqOne + 10;
    cout << "sqOne = sqOne + 10;\n";
    cout << "sqOne.GetArea(): " << sqOne.GetArea() << " (sideSize: " << sqOne.GetWidth() << ")\n";
    cout << "sqTwo.GetArea(): " << sqTwo.GetArea() << " (sideSize: " << sqTwo.GetWidth() << ")\n";
    cout << "-----\n\n";

    Square sqThree = sqTwo + sqOne;
    cout << "Square sqThree = sqTwo + sqOne;\n";
    cout << "sqOne.GetArea(): " << sqOne.GetArea() << " (sideSize: " << sqOne.GetWidth() << ")\n";
    cout << "sqTwo.GetArea(): " << sqTwo.GetArea() << " (sideSize: " << sqTwo.GetWidth() << ")\n";
    cout << "sqThree.GetArea(): " << sqThree.GetArea() << " (sideSize: " << sqThree.GetWidth() << ")\n";
    cout << "-----\n\n";

    Square sqFour = sqTwo - sqOne;
    cout << "Square sqFour = sqTwo - sqOne;\n";
    cout << "sqOne.GetArea(): " << sqOne.GetArea() << " (sideSize: " << sqOne.GetWidth() << ")\n";
    cout << "sqTwo.GetArea(): " << sqTwo.GetArea() << " (sideSize: " << sqTwo.GetWidth() << ")\n";
    cout << "sqFour.GetArea(): " << sqFour.GetArea() << " (sideSize: " << sqFour.GetWidth() << ")\n";
    cout << "-----\n\n";

    return 0;
};