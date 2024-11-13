#include <iostream>
using std::cin;
using std::cout;
using std::string;


struct Position
{
    size_t x;
    size_t y;
};


class Scene
{
public:
    explicit Scene(size_t width, size_t height)
        : _p_cells{ nullptr }
        , _cellCount{ width * height }
        , _width{ width }
        , _height{ height }
    {
        if (_cellCount == 0) return;

        _p_cells = new char[_cellCount];

        std::memset(_p_cells, '?', sizeof(char) * _cellCount);
    }

    Scene(const Scene& other)
        : _p_cells{ nullptr }
        , _cellCount{ other._cellCount }
        , _width{ other._width }
        , _height{ other._height }
    {
        if (_cellCount == 0) return;

        _p_cells = new char[_cellCount];
        std::copy(other._p_cells, other._p_cells + other._cellCount, _p_cells);
    }

    ~Scene()
    {
        if (_p_cells == nullptr) return;

        delete[] _p_cells;
        _p_cells = nullptr;
        _cellCount = 0;
        _width = 0;
        _height = 0;
    }

    Scene& operator=(const Scene& other)
    {
        if (this == &other) return *this;

        if (_cellCount != other._cellCount)
        {
            delete[] _p_cells;
            _p_cells = nullptr;
            _cellCount = other._cellCount;
            _width = other._width;
            _height = other._height;

            if (_cellCount > 0)
            {
                _p_cells = new char[_cellCount];
            }
        }

        if (_cellCount > 0)
        {
            std::copy(other._p_cells, other._p_cells + other._cellCount, _p_cells);
        }

        return *this;
    }

    char& operator[](Position p)
    {
        //@TODO Сделать проверку на границы
        return _p_cells[p.x + p.y * _width];
    }

    const char& operator[](Position p) const
    {
        //@TODO Сделать проверку на границы
        return _p_cells[p.x + p.y * _width];
    }

    size_t GetWidth() const
    {
        return _width;
    }

    size_t GetHeight() const
    {
        return _height;
    }


private:
    char* _p_cells;
    size_t _cellCount;
    size_t _width;
    size_t _height;
};


std::ostream& operator<<(std::ostream& output, const Scene& scene)
{
    for (size_t y = 0; y < scene.GetHeight(); y++)
    {
        for (size_t x = 0; x < scene.GetWidth(); x++)
        {
            output << scene[{x, y}] << ' ';
        }
        output << '\n';
    }

    return output;
}


int main()
{
    Scene sc{ 10, 7 };

    //
    cout << "\n[1]\n";

    sc[Position{ 2, 3 }] = '@';
    sc[{ 5, 0 }] = '+';

    cout << sc[{ 2, 3 }] << '\n';
    cout << sc[Position{ 5, 0 }] << '\n';

    //
    cout << "\n[2]\n";

    cout << sc;

    //
    cout << "\n[3]\n";

    cout << sc;

    return 0;
}