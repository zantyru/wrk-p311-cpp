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

private:
    bool _isCapOpened;
};


// Box - базовый/base (родительский/parent) класс
// BoxWithCap - производный/drived (дочерний/потомок/child) класс


int main()
{
    Box b{ 2, 6, 1 };
    BoxWithCap bwc{ 5, 5, 5 };

    cout << "b.GetWidth(): " << b.GetWidth() << "\n";
    cout << "bwc.GetWidth(): " << bwc.GetWidth() << "\n";
    
    // ѕодробна€ развЄрнута€ верси€ доступа к методу,
    // унаследованному от класса Box
    cout << "bwc.Box::GetWidth(): " << bwc.Box::GetWidth() << "\n";

    // “ак нельз€. ќбъекту более узкоспециализированного класса нельз€
    // присвоить объект более общего класса (если не определено конкретное
    // правило)
    // bwc = b;

    // ј наоборот можно, потому что компил€тор добавл€ет оператор
    // присваивани€ дл€ такого случа€ (ну, почти), если это €вно
    // не было запрещено
    b = bwc;
    cout << "b.GetWidth(): " << b.GetWidth() << "\n";

    return 0;
}
