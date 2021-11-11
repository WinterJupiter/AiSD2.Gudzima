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

	double operator[] (const size_t index) const
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

	Vector<T> operator* (const Vector<T>& v)
	{
		if (v.size != size) throw "Vectors aren't equal\n";
		Vector<T> mul(v);
		for (int i = 0; i < size; i++)
			mul.data[i] *= data[i];
		return mul;
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
		if (a == 0) throw ("Divide to 0!");
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

	friend std::istream& operator>> (std::istream& is, Vector<T>& v)
	{
		std::cout << "\nSize: ";
		is >> v.size;
		v.data = new T[v.size];
		for (int i = 0; i < v.size; i++)
			is >> v.data[i];
		return is;
	}

	friend std::ostream& operator<< (std::ostream& os, const Vector<T>& v)
	{
		os << "Size:" << v.Size() << std::endl;
		for (int i = 0; i < v.Size(); i++)
			os << i + 1 << ": " << v[i] << std::endl;
		return os;
	}
	
	//Vector<std::complex<float>> operator*(const float a)
	//{
	//	Vector<std::complex<float>> mul1(*this), mul2(*this);
	//	for (int i = 0; i < size; i++)
	//	{
	//		mul1.data[i] = a * mul1.data[i];
	//		mul2.data[i] *= a;
	//		if (mul1.data[i] != mul2.data[i]) throw "Not commutative\n";
	//	}
	//	return mul1;
	//}

	//Vector<std::complex<float>> operator* (const Vector<std::complex<float>>& v)
	//{
	//	if (v.size != size) throw "Vectors aren't equal\n";
	//	Vector<std::complex<float>> mul(v);
	//	Vector<std::complex<float>> result;
	//	for (int i = 0; i < size; i++)
	//		result += mul.data[i] * data[i];
	//	return result;
	//}

	//Vector<std::complex<double>> operator* (const Vector<std::complex<double>>& v)
	//{
	//	if (v.size != size) throw "Vectors aren't equal\n";
	//	Vector<std::complex<double>> mul(v);
	//	Vector<std::complex<double>> result;
	//	for (int i = 0; i < size; i++)
	//		result += mul.data[i] * data[i];
	//	return result;
	//}
};
