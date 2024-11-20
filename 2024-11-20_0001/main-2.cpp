#include <iostream>
using std::cout;


class Dimension
{
public:
	float Value;

	Dimension(const std::string& name)
		: Value{ 0.0f }
		, _name{ name }
	{ }

	const std::string &GetName() const
	{
		return _name;
	}

	Dimension operator*(const Dimension& other) const
	{
		Dimension result("Результат");
		result.Value = Value * other.Value;

		return *this;
	}

private:
	std::string _name;
};


template<class T>
T ComputeVolume(T a, T b, T c)
{
	return a * b * c;
}


int main()
{
	cout << ComputeVolume(34, 2, 10) << "\n";
	cout << ComputeVolume(2.5, 3.0, 1.0) << "\n";

	Dimension width("Ширина");
	width.Value = 10.0f;

	Dimension length("Длина");
	length.Value = 2.0f;

	Dimension height("Высота");
	height.Value = 2.0f;

	cout << ComputeVolume(width, length, height).Value << "\n";

	return 0;
}
