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
	// Явное указание типа (версии функции)
	cout << ComputeVolume<int>(34.5, 2.1f, 10) << "\n";

	// Вот так теперь нельзя, так как типы аргументов
	// разные; компилятор не может самостоятельно
	// определить, какую версию функции сконструировать 
	// по шаблону или использовать уже ранее созданную
	// cout << ComputeVolume(34.5, 2.1f, 10) << "\n";

	return 0;
}
