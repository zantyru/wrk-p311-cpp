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

    /* ������ ������ � ����� */

    virtual int overflow(int symbolCode) override
    {
        // ���������� ��� ������������ ������ ������ ������.
        // 
        // ���������:
        // symbol - ������, ������� "�� ����" � �����.
        // 
        // ������������ ��������:
        // ��� ����������� �������, ���� �����;
        // EOF � ��������� ������.
        //
        // ��������� �� ��������� (���� �� �������������� �����):
        // ������ ���������� EOF.

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

    /* ������ ������ �� ������ */

    virtual int uflow() override
    {
        // ���������� ��� ��������� �������� ������� � �������
        // � ����������.
        // 
        // ���������:
        // ���.
        // 
        // ������������ ��������:
        // ��� ���������� �������, ���� �����;
        // EOF � ��������� ������.
        //
        // ��������� �� ��������� (���� �� �������������� �����):
        // �������� underflow();
        // ���������� ��������� underflow() � �������� ���������
        // ������ ����� � ���������� �������, ���� �����;        
        // EOF � ��������� ������.
        //
        // �����! ������� �������� ��������� ����������� ������
        // ��������� ������� ���������. ������� ����� ���������
        // ���� ��������������, ���� ������ ������ ��� ������.

        int symbolCode = underflow();
        _lastReadSymbolCode = traits_type::eof();
        
        return symbolCode;
    }

    virtual int underflow() override
    {
        // ���������� ��� ��������� �������� ������� ��� ��������
        // � ����������.
        // 
        // ���������:
        // ���.
        // 
        // ������������ ��������:
        // ��� ���������� �������, ���� �����;
        // EOF � ��������� ������.
        //
        // ��������� �� ��������� (���� �� �������������� �����):
        // ���������� ������ �� ������� ������� � ������ ������
        // �����, ���� �����;
        // EOF � ��������� ������.

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
    int _lastReadSymbolCode; // ����� ��� ������ underflow()
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

    cout << "�������� ������: '" << strOne << "'\n";
    cout << "��������� �� nfs: '" << value << "'\n";

    cout << "�������� ������: '" << strTwo << "'\n";
    cout << "�������� � nfs: '";
    nfs << strTwo;
    cout << "'\n";

    return 0;
}
