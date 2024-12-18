#include <iostream>
using std::cout;
using std::cin;


using Dimension = unsigned int;


class Box
{
public:
    Box(Dimension width, Dimension length, Dimension depth)
        : _width{ width }
        , _length{ length }
        , _depth{ depth }
    {}

    inline Dimension GetWidth() const
    {
        return _width;
    }

    inline Dimension GetLength() const
    {
        return _length;
    }

    inline Dimension GetDepth() const
    {
        return _depth;
    }

    inline Dimension GetVolume() const
    {
        return _width * _length * _depth;
    }

private:
    Dimension _width;
    Dimension _length;
    Dimension _depth;
};


class HeavyBox : public Box
{
public:
    HeavyBox(Dimension width, Dimension length, Dimension depth, Dimension thickness = 0)
        : Box{ width, length, depth}
        , _thickness{ thickness }
    {
        Dimension min = (GetWidth() < GetLength()) ? GetWidth() : GetLength();
        min = (GetDepth() < min) ? GetDepth() : min;

        Dimension halfMin = min >> 1;

        if (_thickness > halfMin) _thickness = halfMin;
    }

    Dimension GetVolume() const  // Этот метод перекрывает (shadows) одноимённый метод класса Box
    {
        Dimension doubledThickness = _thickness << 1;

        return (GetWidth() - doubledThickness)
            * (GetLength() - doubledThickness)
            * (GetDepth() - _thickness)
        ;;
    }

private:
    Dimension _thickness;
};


int main()
{
    HeavyBox hb{ 10, 5, 6, 2 };

    cout << "hb.GetVolume(): " << hb.GetVolume() << "\n";

    // Вызов Box-версии метода GetVolume
    cout << "hb.Box::GetVolume(): " << hb.Box::GetVolume() << "\n";

    return 0;
}
