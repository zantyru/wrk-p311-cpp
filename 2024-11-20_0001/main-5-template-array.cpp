#include <iostream>
using std::cout;


template<class T>
class Array
{
public:
    explicit Array(size_t length)
        : _length{ length }
        , _p_elements{ nullptr }
    {
        if (_length == 0) return;

        _p_elements = new T[_length];
    }

    Array(const Array &other)
        : _length{ other._length }
        , _p_elements{ nullptr }
    {
        if (_length == 0) return;

        _p_elements = new T[_length];

        // for (size_t n = 0; n < _length; n++)
        // {
        //     _p_elements[n] = other._p_elements[n];
        // }

        std::copy(
            other._p_elements,                  // Источник данных (начало)
            other._p_elements + other._length,  // Источник данных (конец, адрес за последним элементом)
            _p_elements                         // Приёмник данных
        );
    }

    ~Array()
    {
        if (_length == 0) return;

        delete[] _p_elements;
        _p_elements = nullptr;
        _length = 0;
    }

    const Array &operator=(const Array &other) const
    {
        if (this == &other) return *this;

        if (_length != other._length)
        {
            if (_length != 0)
            {
                delete[] _p_elements;
                _p_elements = nullptr;
                _length = 0;
            }

            _length = other._length;

            if (_length != 0)
            {
                _p_elements = new T[_length];
            }
        }

        std::copy(
            other._p_elements,                  // Источник данных (начало)
            other._p_elements + other._length,  // Источник данных (конец, адрес за последним элементом)
            _p_elements                         // Приёмник данных
        );

        return *this;
    }

    T &operator[](size_t index)
    {
        //@TODO Добавить проверку индекса
        return _p_elements[index];
    }

    const T &operator[](size_t index) const
    {
        //@TODO Добавить проверку индекса
        return _p_elements[index];
    }

    size_t GetLength() const
    {
        return _length;
    }

private:
    size_t _length;
    T *_p_elements;
};


int main()
{
    Array<std::string> messages(10);
    Array<int> numbers(13);

    numbers[4] = 38;
    cout << "numbers[4]: " << numbers[4] << "\n";

    messages[7] = "Работает";
    cout << "messages[7]: " << messages[7] << "\n";


    return 0;
}
