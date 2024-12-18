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

private:
    Dimension _width;
    Dimension _length;
    Dimension _depth;
};


class BoxWithCap : public Box
{
public:
    BoxWithCap(Dimension width, Dimension length, Dimension depth)
        : Box{ width, length, depth }
        , _isCapOpened{ false }
    {}

    void SetCapOpened(bool isCapOpened)
    {
        _isCapOpened = isCapOpened;
    }

    bool GetCapOpened() const
    {
        return _isCapOpened;
    }

    Dimension GetVolume() const
    {
        // Так не получится. Эти поля описаны в классе
        // Box в `private` зоне. К ним доступа даже
        // для наследников
        // return _width * _length * _depth;
        
        return GetWidth() * GetLength() * GetDepth();
    }

private:
    bool _isCapOpened;
};


// Box - базовый/base (родительский/parent) класс
// BoxWithCap - производный/drived (дочерний/потомок/child) класс


int main()
{
    BoxWithCap bwc{ 3, 2, 10 };
    bwc.SetCapOpened(true);

    cout << "bwc.GetVolume(): " << bwc.GetVolume() << "\n";

    return 0;
}
