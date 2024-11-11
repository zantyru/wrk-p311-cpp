#include <iostream>
using std::cout;
using std::cin;


class Square
{
public:
    explicit Square(float sideSize = 1)
        : _sideSize{ sideSize }
    {}

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

    Square operator+(int otherArea) const
    {
        float resultArea = GetArea() + otherArea;

        return Square(sqrt(resultArea));
    }

private:
    float _sideSize;
};


int main()
{
    Square sqOne(4);
    Square sqTwo(2);
    cout << "squareOne.GetArea(): " << sqOne.GetArea() << " (sideSize: " << sqOne.GetWidth() << ")\n";
    cout << "squareTwo.GetArea(): " << sqTwo.GetArea() << " (sideSize: " << sqTwo.GetWidth() << ")\n";
    cout << "-----\n\n";

    sqOne = sqOne + 10;
    cout << "squareOne = squareOne + 10;\n";
    cout << "squareOne.GetArea(): " << sqOne.GetArea() << " (sideSize: " << sqOne.GetWidth() << ")\n";
    cout << "squareTwo.GetArea(): " << sqTwo.GetArea() << " (sideSize: " << sqTwo.GetWidth() << ")\n";
    cout << "-----\n\n";

    Square sqThree = sqTwo + sqOne;
    cout << "Square squareThree = squareTwo + squareOne;\n";
    cout << "squareOne.GetArea(): " << sqOne.GetArea() << " (sideSize: " << sqOne.GetWidth() << ")\n";
    cout << "squareTwo.GetArea(): " << sqTwo.GetArea() << " (sideSize: " << sqTwo.GetWidth() << ")\n";
    cout << "squareThree.GetArea(): " << sqThree.GetArea() << " (sideSize: " << sqThree.GetWidth() << ")\n";
    cout << "-----\n\n";


    return 0;
};