#include <string>
#include <sstream>
#include <iostream>
using std::cout;
using std::cin;


class NumberFilterStreamBuf : public std::streambuf
{
public:
    NumberFilterStreamBuf(std::istream& inputStream, std::ostream& outputStream)
        : _inputStream{ inputStream }
        , _outputStream{ outputStream }
        , _lastReadSymbolCode{ traits_type::eof() }
    {};
	
    virtual ~NumberFilterStreamBuf() = default;

protected:

    /* Методы записи в поток */

    virtual int overflow(int symbolCode) override
    {
        // Вызывается при переполнении буфера потока вывода.
        // 
        // Аргументы:
        // symbol - символ, который "не влез" в буфер.
        // 
        // Возвращаемое значение:
        // код записанного символа, если успех;
        // EOF в противном случае.
        //
        // Поведение по умолчанию (если не переопределить метод):
        // всегда возвращает EOF.

        if (symbolCode == traits_type::eof())
        {
            return traits_type::eof();
        }

        char_type symbol = static_cast<char_type>(symbolCode);

        if (std::isspace(symbol) || std::isdigit(symbol))
        {
            _outputStream.put(symbol);
            return _outputStream.good() ? symbol : traits_type::eof();
        }

        return symbol;
    }

    /* Методы чтения из потока */

    virtual int uflow() override
    {
        // Вызывается для получения текущего символа с перехом
        // к следующему.
        // 
        // Аргументы:
        // нет.
        // 
        // Возвращаемое значение:
        // код считанного символа, если успех;
        // EOF в противном случае.
        //
        // Поведение по умолчанию (если не переопределить метод):
        // вызывает underflow();
        // возвращает результат underflow() и сдвигает указатель
        // буфера ввода к следующему символу, если успех;        
        // EOF в противном случае.
        //
        // Важно! Попытка сдвинуть указатель незаданного буфера
        // окончится вылетом программы. Поэтому такое поведение
        // надо переопределить, если работа ведётся без буфера.

        int symbolCode = underflow();
        _lastReadSymbolCode = traits_type::eof();
        
        return symbolCode;
    }

    virtual int underflow() override
    {
        // Вызывается для получения текущего символа без перехода
        // к следующему.
        // 
        // Аргументы:
        // нет.
        // 
        // Возвращаемое значение:
        // код считанного символа, если успех;
        // EOF в противном случае.
        //
        // Поведение по умолчанию (если не переопределить метод):
        // возвращает символ на текущей позиции в буфере потока
        // ввода, если успех;
        // EOF в противном случае.

        if (_lastReadSymbolCode != traits_type::eof())
        {
            return _lastReadSymbolCode;
        }

        while (_inputStream.good())
        {
            _lastReadSymbolCode = _inputStream.get();

            if (_lastReadSymbolCode == traits_type::eof())
            {
                return traits_type::eof();
            }

            char_type symbol = static_cast<char_type>(_lastReadSymbolCode);

            if (std::isspace(symbol) || std::isdigit(symbol))
            {
                return symbol;
            }
        }

        return traits_type::eof();
    }

private:
    std::istream& _inputStream;
    std::ostream& _outputStream;
    int _lastReadSymbolCode; // Нужно для метода underflow()
};


int main()
{
    setlocale(LC_ALL, "Russian");

    const char strOne[] = "In 4 bytes contains 32 bits";
    const char strTwo[] = "Unix time starts from Jan 1, 1970";
    std::istringstream inputStringStream(strOne);

    NumberFilterStreamBuf nfsb(inputStringStream, cout);
    std::iostream nfs(&nfsb);

    std::string value;
    std::getline(nfs, value);
    nfs.clear();

    cout << "Исходная строка: '" << strOne << "'\n";
    cout << "Прочитано из nfs: '" << value << "'\n";

    cout << "Исходная строка: '" << strTwo << "'\n";
    cout << "Записано в nfs: '";
    nfs << strTwo;
    cout << "'\n";

    return 0;
}
