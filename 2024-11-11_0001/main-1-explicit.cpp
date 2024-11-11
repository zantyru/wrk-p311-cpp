// Про explicit конструктор


class Dummy
{
public:
    Dummy(int value)
        : _value{ value }
    {}

    int GetValue() const
    {
        return _value;
    }

private:
    int _value;
};


class DummyExplicit
{
public:
    explicit DummyExplicit(int value)  //@NOTE Добавлено ключевое слово explicit
        : _value{ value }
    {}

    int GetValue() const
    {
        return _value;
    }

private:
    int _value;
};


int main()
{
    {
        Dummy d1(12);
        Dummy d2{ 12 };
        Dummy d3 = 12;  // ! Так можно, так как конструктор НЕ explicit
        Dummy d4 = Dummy(12);
    }

    {
        DummyExplicit d1(12);
        DummyExplicit d2{ 12 };
        //DummyExplicit d3 = 12;  // ! Так уже НЕЛЬЗЯ, так как конструктор explicit
        DummyExplicit d4 = DummyExplicit(12);
    }

    return 0;
};