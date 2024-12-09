#include <iostream>
using std::cout;
using std::cin;


template<class T>
class Queue
{
public:
    Queue()
        : _head{ 0 }
        , _tail{ 0 }
        , _length{ 0 }
    {}

    // Добавить в очередь
    bool Enqueue(const T& element)
    {
        if (IsFull()) return false;

        if (_length > 0)
        {
            _tail = (_MAX_LENGTH + _tail - 1) % _MAX_LENGTH;
        }

        _elements[_tail] = element;
        ++_length;

        return true;
    }

    // Изъять из очереди
    bool Dequeue(T& element)
    {
        if (IsEmpty()) return false;

        element = _elements[_head];
        --_length;

        if (_length > 0)
        {
            _head = (_MAX_LENGTH + _head - 1) % _MAX_LENGTH;
        }

        return true;
    }

    inline bool IsEmpty() const
    {
        return _length == 0;
    }

    inline bool IsFull() const
    {
        return _length == _MAX_LENGTH;
    }

private:
    static const size_t _MAX_LENGTH = 10;
    size_t _head;
    size_t _tail;
    size_t _length;
    T _elements[_MAX_LENGTH];
};


struct Paper
{
    float width{};
    float height{};
};


std::ostream& operator<<(std::ostream& out, const Paper& paper)
{
    out
        << "Paper{ width = " << paper.width
        << ", height = " << paper.height
        << "}"
    ;;

    return out;
}


int main()
{
    Queue<Paper> q;

    q.Enqueue(Paper{ 3.4f, 12.0f });
    q.Enqueue(Paper{ 7.1f, 12.0f });
    q.Enqueue(Paper{ 5.0f, 2.0f });
    q.Enqueue(Paper{ 1.0f, 1.0f });

    while (!q.IsEmpty())
    {
        Paper paper;
        q.Dequeue(paper);
        cout << paper << "\n";
    }

    return 0;
}
