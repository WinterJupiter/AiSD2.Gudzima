#pragma once
#include <iostream>
#include <string>

template<class T>
class Vector {
private:
	size_t size;
	T* data;
public:

	Vector()
	{
		size = 0;
		data = NULL;
	}

	Vector(const size_t size)
	{
		data = new T[size];
		for (int i = 0; i < size; i++)
			data[i] = 0;
	}

	Vector(const Vector<T>& v)
	{
		data = new T[v.size];
		size = v.size;
		for (int i = 0; i < size; i++)
			data[i] = v.data[i];
	}

	void Add(T value)
	{
		T* v = new T[size + 1];
		for (int i = 0; i < size; i++)
			v[i] = data[i];
		v[size] = value;
		delete[] data;
		data = v;
		size++;
	}

	void Change(size_t index, T value)
	{
		if ((index > size) || (index <= 0)) throw ("Invalid index");
		data[index - 1] = value;
	}

	size_t Size() const
	{
		return size;
	}

	T operator[] (const size_t index) const
	{
		if ((index > size) || (index < 0)) throw ("Invalid index");
		return data[index];
	}

	Vector<T>& operator=(const Vector<T>& v)
	{
		size = v.size;
		delete[] data;
		data = new T[size];
		for (int i = 0; i < size; i++)
			data[i] = v.data[i];
		return *this;
	}

	Vector<T> operator+(const Vector<T>& v)
	{
		if (v.size != size) throw "Vectors aren't equal\n";
		Vector<T> sum(v);
		for (int i = 0; i < size; i++)
			sum.data[i] += data[i];
		return sum;
	}

	Vector<T> operator-(const Vector<T>& v)
	{
		if (v.size != size) throw "Vectors aren't equal\n";
		Vector<T> sub(*this);
		for (int i = 0; i < size; i++)
			sub.data[i] = data[i] - v.data[i];
		return sub;
	}

	T operator* (const Vector<T>& v)
	{
		if (v.size != size) throw "Vectors aren't equal\n";
		Vector<T> mul(v);
		T result = 0;
		for (int i = 0; i < size; i++)
			result += mul.data[i] * data[i];
		return result;
	}

	Vector<T> operator*(const T a)
	{
		Vector<T> mul1(*this), mul2(*this);
		for (int i = 0; i < size; i++)
		{
			mul1.data[i] = a * mul1.data[i];
			mul2.data[i] *= a;
			if (mul1.data[i] != mul2.data[i]) throw "Not commutative\n";
		}
		return mul1;
	}

	Vector<T> operator/ (const T a)
	{
		if (a == T(0)) throw ("Divide to 0!");
		Vector<T> div(*this);
		for (int i = 0; i < size; i++)
			div.data[i] /= a;
		return div;
	}

	~Vector()
	{
		size = 0;
		delete[] data;
	}

	template<class T>
	friend std::istream& operator>> (std::istream& is, Vector<T>& v);

	friend std::ostream& operator<< (std::ostream& os, const Vector<T>& v)
	{
		os << "Size:" << v.Size() << std::endl;
		for (int i = 0; i < v.Size(); i++)
			os << i + 1 << ": " << v[i] << std::endl;
		return os;
	}

	std::complex<float> operator* (const Vector<std::complex<float>>& v) const
	{
		if (v.size != size) throw "Vectors aren't equal\n";
		std::complex<float> result = 0;
		for (size_t i = 0; i < size; i++)
			result += std::complex<float>(data[i].real() * v.data[i].real(), (-1) * data[i].imag() * v.data[i].imag());
		return result;
	}

	std::complex<double> operator* (const Vector<std::complex<double>>& v) const
	{
		if (v.size != size) throw "Vectors aren't equal\n";
		std::complex<double> result = 0;
		for (size_t i = 0; i < size; i++)
			result += std::complex<double>(data[i].real() * v.data[i].real(), (-1) * data[i].imag() * v.data[i].imag());
		return result;
	}

};

template<class T>
std::istream& operator>> (std::istream& is, Vector<T>& v)
{
	std::cout << "\nSize: ";
	is >> v.size;
	v.data = new T[v.size];
	for (int i = 0; i < v.size; i++)
		is >> v.data[i];
	return is;
}

template<>
std::istream& operator>> (std::istream& is, Vector<std::complex<double>>& v)
{
	std::cout << "\nSize: ";
	is >> v.size;
	v.data = new std::complex<double>[v.size];
	for (int i = 0; i < v.size; i++)
	{
		double real = 0;
		double imag = 0;
		std::cout << "\nReal part: ";
		is >> real;
		std::cout << "\nImag part: ";
		is >> imag;
		v.data[i] = std::complex<double>(real, imag);
	}
	return is;
}

template<>
std::istream& operator>> (std::istream& is, Vector<std::complex<float>>& v)
{
	std::cout << "\nSize: ";
	is >> v.size;
	v.data = new std::complex<float>[v.size];
	for (int i = 0; i < v.size; i++)
	{
		double real = 0;
		double imag = 0;
		std::cout << "\nReal part: ";
		is >> real;
		std::cout << "\nImag part: ";
		is >> imag;
		v.data[i] = std::complex<float>(real, imag);
	}
	return is;
}
