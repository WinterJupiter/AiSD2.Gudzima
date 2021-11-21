#include <iostream>
#include <conio.h>
#include <complex>
#include "Vector.h"


int get_key()
{
	int key = 0;
	std::cin >> key;
	if ((key == 0) || (key == 224)) std::cin >> key;
	return key;
}

int menu()
{
	std::cout << "1 - Vector of int\n2 - Vector of double\n3 - Vector of complex float\n4 - Vector of complex double\n5 - Exit\n\n";
	while (true)
	{
		int key = get_key();
		if ((key == 5) || (key == 1) || (key == 2) || (key == 3) || (key == 4)) return key;
	}
}

int menu1()
{
	std::cout << "For work!\n\n1 - First vector\n2 - Second vector\n3 - Complete task\n4 - Exit\n\n";
	while (true)
	{
		int key = get_key();
		if ((key == 4) || (key == 1) || (key == 2) || (key == 3)) return key;
	}
}

int menu2()
{
	std::cout << "\n\n1 - Change by index\n2 - Add element\n3 - Exit\n\n";
	while (true)
	{
		int key = get_key();
		if ((key == 3) || (key == 1) || (key == 2)) return key;
	}
}

int menu3()
{
	std::cout << "\n\n1 - Addition\n2 - Subtraction\n3 - Multiplication\n4 - Division\n5 - Multiplication by const\n6 - Exit\n\n";
	while (true)
	{
		int key = get_key();
		if ((key == 6) || (key == 1) || (key == 2) || (key == 3) || (key == 4) || (key == 5)) return key;
	}
}

std::complex<float> InComplex1()
{
	std::complex<float> value = 0;
	float real = 0;
	float imag = 0;
	std::cout << "\nReal part: ";
	std::cin >> real;
	std::cout << "\nImag part: ";
	std::cin >> imag;
	value = std::complex<float>(real, imag);
	return value;
}

std::complex<double> InComplex2()
{
	std::complex<double> value = 0;
	double real = 0;
	double imag = 0;
	std::cout << "\nReal part: ";
	std::cin >> real;
	std::cout << "\nImag part: ";
	std::cin >> imag;
	value = std::complex<double>(real, imag);
	return value;
}

void Int()
{
	Vector<int> first, second;
	std::cout << "Input first vector: ";
	std::cin >> first;
	std::cout << "Input second vector: ";
	std::cin >> second;
	std::cout << std::endl << std::endl;
	while (true)
	{
		system("cls");
		int m = menu1();
		if (m == 1)
		{
			while (true)
			{
				system("cls");
				std::cout << "First vector: ";
				std::cout << first << std::endl;
				int n = menu2();
				if (n == 3) break;
				if (n == 1)
				{
					size_t index;
					int value;
					std::cout << "Which element: ";
					std::cin >> index;
					std::cout << "Enter a new value: ";
					std::cin >> value;
					first.Change(index, value);
				}
				if (n == 2)
				{
					int value;
					std::cout << "Enter a new value: ";
					std::cin >> value;
					first.Add(value);
				}
			}
		}
		if (m == 2)
		{
			while (true)
			{
				system("cls");
				std::cout << "Second vector: ";
				std::cout << second << std::endl;
				int n = menu2();
				if (n == 3) break;
				if (n == 1)
				{
					size_t index;
					int value;
					std::cout << "Which element: ";
					std::cin >> index;
					std::cout << "Enter a new value: ";
					std::cin >> value;
					second.Change(index, value);
				}
				if (n == 2)
				{
					int value;
					std::cout << "Enter a new value: ";
					std::cin >> value;
					second.Add(value);
				}
			}
		}
		if (m == 3)
		{
			while (true)
			{
				system("cls");
				std::cout << "First vector: ";
				std::cout << first << std::endl;
				std::cout << "Second vector: ";
				std::cout << second << std::endl;
				int n = menu3();
				if (n == 6) break;
				if (n == 1)
				{
					Vector<int> add;
					std::cout << "Addition:\n" << std::endl;
					try
					{
						add = first + second;
						std::cin.get();
					}
					catch (const char* err)
					{
						std::cout << err << std::endl;
					}

					std::cout << add << std::endl;
					system("pause");
				}
				if (n == 2)
				{
					Vector<int> sub;
					std::cout << "Subtraction:\n" << std::endl;
					try
					{
						sub = first - second;
						std::cin.get();
					}
					catch (const char* err)
					{
						std::cout << err << std::endl;
					}
					std::cout << sub << std::endl;
					system("pause");
				}
				if (n == 3)
				{
					int mul;
					std::cout << "Multiplication:\n" << std::endl;
					try
					{
						mul = first * second;
						std::cin.get();
					}
					catch (const char* err)
					{
						std::cout << err << std::endl;
					}
					std::cout << mul << std::endl;
					system("pause");
				}
				if (n == 4)
				{
					Vector<int> div1, div2;
					std::cout << "Division:\n" << std::endl;
					int value;
					std::cout << "Enter a new value: ";
					std::cin >> value;
					try
					{
						div1 = first / value;
						std::cin.get();
					}
					catch (const char* err)
					{
						std::cout << err << std::endl;
					}
					std::cout << div1 << std::endl;
					try
					{
						div2 = second / value;
						std::cin.get();
					}
					catch (const char* err)
					{
						std::cout << err << std::endl;
					}
					std::cout << div2 << std::endl;
					system("pause");
				}
				if (n == 5)
				{
					Vector<int> mul1, mul2;
					std::cout << "Multiplication by const:\n" << std::endl;
					int value;
					std::cout << "Enter a new value: ";
					std::cin >> value;
					try
					{
						mul1 = first * value;
						std::cin.get();
					}
					catch (const char* err)
					{
						std::cout << err << std::endl;
					}
					std::cout << mul1 << std::endl;
					try
					{
						mul2 = second * value;
						std::cin.get();
					}
					catch (const char* err)
					{
						std::cout << err << std::endl;
					}
					std::cout << mul2 << std::endl;
					system("pause");
				}
			}
		}
		if (m == 4) break;
	}
}

void Double()
{
	Vector<double> first, second;
	std::cout << "Input first vector: ";
	std::cin >> first;
	std::cout << "Input second vector: ";
	std::cin >> second;
	std::cout << std::endl << std::endl;
	while (true)
	{
		system("cls");
		int m = menu1();
		if (m == 1)
		{
			while (true)
			{
				system("cls");
				std::cout << "First vector: ";
				std::cout << first << std::endl;
				int n = menu2();
				if (n == 3) break;
				if (n == 1)
				{
					size_t index;
					double value;
					std::cout << "Which element: ";
					std::cin >> index;
					std::cout << "Enter a new value: ";
					std::cin >> value;
					first.Change(index, value);
				}
				if (n == 2)
				{
					double value;
					std::cout << "Enter a new value: ";
					std::cin >> value;
					first.Add(value);
				}
			}
		}
		if (m == 2)
		{
			while (true)
			{
				system("cls");
				std::cout << "Second vector: ";
				std::cout << second << std::endl;
				int n = menu2();
				if (n == 3) break;
				if (n == 1)
				{
					size_t index;
					double value;
					std::cout << "Which element: ";
					std::cin >> index;
					std::cout << "Enter a new value: ";
					std::cin >> value;
					second.Change(index, value);
				}
				if (n == 2)
				{
					double value;
					std::cout << "Enter a new value: ";
					std::cin >> value;
					second.Add(value);
				}
			}
		}
		if (m == 3)
		{
			while (true)
			{
				system("cls");
				std::cout << "First vector: ";
				std::cout << first << std::endl;
				std::cout << "Second vector: ";
				std::cout << second << std::endl;
				int n = menu3();
				if (n == 6) break;
				if (n == 1)
				{
					Vector<double> add;
					std::cout << "Addition:\n" << std::endl;
					try
					{
						add = first + second;
						std::cin.get();
					}
					catch (const char* err)
					{
						std::cout << err << std::endl;
					}
					std::cout << add << std::endl;
					system("pause");
				}
				if (n == 2)
				{
					Vector<double> sub;
					std::cout << "Subtraction:\n" << std::endl;
					try
					{
						sub = first - second;
						std::cin.get();
					}
					catch (const char* err)
					{
						std::cout << err << std::endl;
					}
					std::cout << sub << std::endl;
					system("pause");
				}
				if (n == 3)
				{
					double mul;
					std::cout << "Multiplication:\n" << std::endl;
					try
					{
						mul = first * second;
						std::cin.get();
					}
					catch (const char* err)
					{
						std::cout << err << std::endl;
					}
					std::cout << mul << std::endl;
					system("pause");
				}
				if (n == 4)
				{
					Vector<double> div1, div2;
					std::cout << "Division:\n" << std::endl;
					double value;
					std::cout << "Enter a new value: ";
					std::cin >> value;
					try
					{
						div1 = first / value;
						std::cin.get();
					}
					catch (const char* err)
					{
						std::cout << err << std::endl;
					}
					std::cout << div1 << std::endl;
					try
					{
						div2 = second / value;
						std::cin.get();
					}
					catch (const char* err)
					{
						std::cout << err << std::endl;
					}
					std::cout << div2 << std::endl;
					system("pause");
				}
				if (n == 5)
				{
					Vector<double> mul1, mul2;
					std::cout << "Multiplication by const:\n" << std::endl;
					double value;
					std::cout << "Enter a new value: ";
					std::cin >> value;
					try
					{
						mul1 = first * value;
						std::cin.get();
					}
					catch (const char* err)
					{
						std::cout << err << std::endl;
					}
					std::cout << mul1 << std::endl;
					try
					{
						mul2 = second * value;
						std::cin.get();
					}
					catch (const char* err)
					{
						std::cout << err << std::endl;
					}
					std::cout << mul2 << std::endl;
					system("pause");
				}
			}
		}
		if (m == 4) break;
	}
}

void ComplexFloat()
{
	Vector<std::complex<float>> first, second;
	std::cout << "Input first vector: ";
	std::cin >> first;
	std::cout << "Input second vector: ";
	std::cin >> second;
	std::cout << std::endl << std::endl;
	while (true)
	{
		system("cls");
		int m = menu1();
		if (m == 1)
		{
			while (true)
			{
				system("cls");
				std::cout << "First vector: ";
				std::cout << first << std::endl;
				int n = menu2();
				if (n == 3) break;
				if (n == 1)
				{
					size_t index;
					std::complex<float> value;
					std::cout << "Which element: ";
					std::cin >> index;
					std::cout << "Enter a new value: ";
					value = InComplex1();
					first.Change(index, value);
				}
				if (n == 2)
				{
					std::complex<float> value;
					std::cout << "Enter a new value: ";
					value = InComplex1();
					first.Add(value);
				}
			}
		}
		if (m == 2)
		{
			while (true)
			{
				system("cls");
				std::cout << "Second vector: ";
				std::cout << second << std::endl;
				int n = menu2();
				if (n == 3) break;
				if (n == 1)
				{
					size_t index;
					std::complex<float> value;
					std::cout << "Which element: ";
					std::cin >> index;
					std::cout << "Enter a new value: ";
					value = InComplex1();
					second.Change(index, value);
				}
				if (n == 2)
				{
					std::complex<float> value;
					std::cout << "Enter a new value: ";
					value = InComplex1();
					second.Add(value);
				}
			}
		}
		if (m == 3)
		{
			while (true)
			{
				system("cls");
				std::cout << "First vector: ";
				std::cout << first << std::endl;
				std::cout << "Second vector: ";
				std::cout << second << std::endl;
				int n = menu3();
				if (n == 6) break;
				if (n == 1)
				{
					Vector<std::complex<float>> add;
					std::cout << "Addition:\n" << std::endl;
					try
					{
						add = first + second;
						std::cin.get();
					}
					catch (const char* err)
					{
						std::cout << err << std::endl;
					}
					std::cout << add << std::endl;
					system("pause");
				}
				if (n == 2)
				{
					Vector<std::complex<float>> sub;
					std::cout << "Subtraction:\n" << std::endl;
					try
					{
						sub = first - second;
						std::cin.get();
					}
					catch (const char* err)
					{
						std::cout << err << std::endl;
					}
					std::cout << sub << std::endl;
					system("pause");
				}
				if (n == 3)
				{
					std::complex<float> mul;
					std::cout << "Multiplication:\n" << std::endl;
					try
					{
						mul = first * second;
						std::cin.get();
					}
					catch (const char* err)
					{
						std::cout << err << std::endl;
					}
					std::cout << mul << std::endl;
					system("pause");
				}
				if (n == 4)
				{
					Vector<std::complex<float>> div1, div2;
					std::cout << "Division:\n" << std::endl;
					std::complex<float> value;
					std::cout << "Enter a new value: ";
					value = InComplex1();
					try
					{
						div1 = first / value;
						std::cin.get();
					}
					catch (const char* err)
					{
						std::cout << err << std::endl;
					}
					std::cout << div1 << std::endl;
					try
					{
						div2 = second / value;
						std::cin.get();
					}
					catch (const char* err)
					{
						std::cout << err << std::endl;
					}
					std::cout << div2 << std::endl;
					system("pause");
				}
				if (n == 5)
				{
					Vector<std::complex<float>> mul1, mul2;
					std::cout << "Multiplication by const:\n" << std::endl;
					std::complex<float> value;
					std::cout << "Enter a new value: ";
					value = InComplex1();;
					try
					{
						mul1 = first * value;
						std::cin.get();
					}
					catch (const char* err)
					{
						std::cout << err << std::endl;
					}
					std::cout << mul1 << std::endl;
					try
					{
						mul2 = second * value;
						std::cin.get();
					}
					catch (const char* err)
					{
						std::cout << err << std::endl;
					}
					std::cout << mul2 << std::endl;
					system("pause");
				}
			}
		}
		if (m == 4) break;
	}
}

void ComplexDouble()
{
	Vector<std::complex<double>> first, second;
	std::cout << "Input first vector: ";
	std::cin >> first;
	std::cout << "Input second vector: ";
	std::cin >> second;
	std::cout << std::endl << std::endl;
	while (true)
	{
		system("cls");
		int m = menu1();
		if (m == 1)
		{
			while (true)
			{
				system("cls");
				std::cout << "First vector: ";
				std::cout << first << std::endl;
				int n = menu2();
				if (n == 3) break;
				if (n == 1)
				{
					size_t index;
					std::complex<double> value;
					std::cout << "Which element: ";
					std::cin >> index;
					std::cout << "Enter a new value: ";
					value = InComplex2();
					first.Change(index, value);
				}
				if (n == 2)
				{
					std::complex<double> value;
					std::cout << "Enter a new value: ";
					value = InComplex2();
					first.Add(value);
				}
			}
		}
		if (m == 2)
		{
			while (true)
			{
				system("cls");
				std::cout << "Second vector: ";
				std::cout << second << std::endl;
				int n = menu2();
				if (n == 3) break;
				if (n == 1)
				{
					size_t index;
					std::complex<double> value;
					std::cout << "Which element: ";
					std::cin >> index;
					std::cout << "Enter a new value: ";
					value = InComplex2();
					second.Change(index, value);
				}
				if (n == 2)
				{
					std::complex<double> value;
					std::cout << "Enter a new value: ";
					value = InComplex2();
					second.Add(value);
				}
			}
		}
		if (m == 3)
		{
			while (true)
			{
				system("cls");
				std::cout << "First vector: ";
				std::cout << first << std::endl;
				std::cout << "Second vector: ";
				std::cout << second << std::endl;
				int n = menu3();
				if (n == 6) break;
				if (n == 1)
				{
					Vector<std::complex<double>> add;
					std::cout << "Addition:\n" << std::endl;
					try
					{
						add = first + second;
						std::cin.get();
					}
					catch (const char* err)
					{
						std::cout << err << std::endl;
					}

					std::cout << add << std::endl;
					system("pause");
				}
				if (n == 2)
				{
					Vector<std::complex<double>> sub;
					std::cout << "Subtraction:\n" << std::endl;
					try
					{
						sub = first - second;
						std::cin.get();
					}
					catch (const char* err)
					{
						std::cout << err << std::endl;
					}
					std::cout << sub << std::endl;
					system("pause");
				}
				if (n == 3)
				{
					std::complex<double> mul;
					std::cout << "Multiplication:\n" << std::endl;
					try
					{
						mul = first * second;
						std::cin.get();
					}
					catch (const char* err)
					{
						std::cout << err << std::endl;
					}
					std::cout << mul << std::endl;
					system("pause");
				}
				if (n == 4)
				{
					Vector<std::complex<double>> div1, div2;
					std::cout << "Division:\n" << std::endl;
					std::complex<double> value;
					std::cout << "Enter a new value: ";
					value=InComplex2();
					try
					{
						div1 = first / value;
						std::cin.get();
					}
					catch (const char* err)
					{
						std::cout << err << std::endl;
					}
					std::cout << div1 << std::endl;
					try
					{
						div2 = second / value;
						std::cin.get();
					}
					catch (const char* err)
					{
						std::cout << err << std::endl;
					}
					std::cout << div2 << std::endl;
					system("pause");
				}
				if (n == 5)
				{
					Vector<std::complex<double>> mul1, mul2;
					std::cout << "Multiplication by const:\n" << std::endl;
					std::complex<double> value;
					std::cout << "Enter a new value: ";
					value = InComplex2();
					try
					{
						mul1 = first * value;
						std::cin.get();
					}
					catch (const char* err)
					{
						std::cout << err << std::endl;
					}
					std::cout << mul1 << std::endl;
					try
					{
						mul2 = second * value;
						std::cin.get();
					}
					catch (const char* err)
					{
						std::cout << err << std::endl;
					}
					std::cout << mul2 << std::endl;
					system("pause");
				}
			}
		}
		if (m == 4) break;
	}
}

int main()
{
	while (true)
	{
		system("cls");
		int m = menu();
		if (m == 5) break;
		if (m == 1) Int();
		if (m == 2) Double();
		if (m == 3) ComplexFloat();
		if (m == 4) ComplexDouble();
	}
	return 0;
}