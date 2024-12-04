// Автор: студент Денис

#include <iostream>
using std::cout;
using std::cin;


template <class T>
class Deck {
public:
    Deck() : _head{ 0 }, _tail{ 0 }, _count{ 0 } {}

    bool PushFront(const T &element) {
        if (IsFull()) return false;
        _head = (_head - 1 + SIZE) % SIZE;
        _elements[_head] = element;
        _count++;
        return true;
    }

    bool PushBack(const T &element) {
        if (IsFull()) return false;
        _elements[_tail] = element;
        _tail = (_tail + 1) % SIZE;
        _count++;
        return true;
    }

    bool PopFront(T *p_element) {
        if (IsEmpty()) return false;
        *p_element = _elements[_head];
        _head = (_head + 1) % SIZE;
        _count--;
        return true;
    }

    bool PopBack(T *p_element) {
        if (IsEmpty()) return false;
        _tail = (_tail - 1 + SIZE) % SIZE;
        *p_element = _elements[_tail];
        _count--;
        return true;
    }

    bool IsEmpty() const {
        return _count == 0;
    }

    bool IsFull() const {
        return _count == SIZE;
    }

private:
    static const size_t SIZE = 12;
    T _elements[SIZE];
    size_t _head;
    size_t _tail;
    size_t _count;
};


int main() {
    Deck<int> deckOfIntegers;

    deckOfIntegers.PushBack(10);
    deckOfIntegers.PushBack(20);
    deckOfIntegers.PushFront(5);
    deckOfIntegers.PushFront(1);
    deckOfIntegers.PushBack(30);


    while (!deckOfIntegers.IsEmpty()) {
        int e{};
        deckOfIntegers.PopFront(&e);
        cout << e << " ";
    }
    cout << "\n";


    Deck<int> deck2;
    deck2.PushBack(1);
    deck2.PushBack(2);
    deck2.PushBack(3);

    int x;
    deck2.PopBack(&x);
    cout << x << "\n";

    while (!deck2.IsEmpty()) {
        int e{};
        deck2.PopFront(&e);
        cout << e << " ";
    }
    cout << "\n";

    return 0;
}
