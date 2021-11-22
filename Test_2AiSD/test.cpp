#include "pch.h"
#include <complex>
#include "../Vector.h"

TEST(Vector, Vector_Constructor)
{
	Vector<int> v1, v2;
	EXPECT_EQ(0, v1.Size());
	EXPECT_EQ(0, v2.Size());

	Vector<std::complex<float>> v3, v4;
	EXPECT_EQ(0, v3.Size());
	EXPECT_EQ(0, v4.Size());
}

TEST(Vector, Vector_Constructor_Copy)
{
	Vector<int> v1;
	int value_int = 75;
	v1.Add(value_int);
	Vector<int> v2(v1);
	EXPECT_EQ(1, v2.Size());

	Vector<double> v11;
	double value_double = 75.99876;
	v11.Add(value_double);
	Vector<double> v12(v11);
	EXPECT_EQ(1, v12.Size());

	Vector<std::complex<double>> v3;
	std::complex<double> value_cdouble(1,5);
	v3.Add(value_cdouble);
	Vector<std::complex<double>> v4(v3);
	EXPECT_EQ(1, v4.Size());

	Vector<std::complex<float>> v23;
	std::complex<float> value_cfloat(1,5);
	v23.Add(value_cfloat);
	Vector<std::complex<float>> v24(v23);
	EXPECT_EQ(1, v24.Size());
}

TEST(Vector, Add)
{
	Vector<int> v1;
	int value_int = 75;
	v1.Add(value_int);
	value_int = -4;
	v1.Add(value_int);
	value_int = 0;
	v1.Add(value_int);
	EXPECT_EQ(3, v1.Size());

	Vector<double> v11;
	double value_double = 75.99876;
	v11.Add(value_double);
	value_double = -0.34562;
	v11.Add(value_double);
	value_double = 12;
	v11.Add(value_double);
	EXPECT_EQ(3, v11.Size());

	Vector<std::complex<double>> v3;
	std::complex<double> value_cdouble(1,-5);
	v3.Add(value_cdouble);
	std::complex<double> value_cdouble2(-1,78);
	v3.Add(value_cdouble2);
	EXPECT_EQ(2, v3.Size());

	Vector<std::complex<float>> v23;
	std::complex<float> value_cfloat(1,-5);
	v23.Add(value_cfloat);
	std::complex<float> value_cfloat2(-1,78);
	v23.Add(value_cfloat2);
	EXPECT_EQ(2, v23.Size());
}

TEST(Vector, Change)
{
	Vector<int> v1(1);
	bool flag = 0;
	v1.Change(1, 9);
	if (v1[0] == 9) flag = 1;
	else flag = 0;
	EXPECT_EQ(1, flag);

	Vector<std::complex<float>> v2(1);
	flag = 0;
	std::complex<float> value(1,9);
	v2.Change(1, value);
	if (v2[0] == value) flag = 1;
	else flag = 0;
	EXPECT_EQ(1, flag);
}

TEST(Vector, Operator_Equal_And_Square_Brackets)
{
	Vector<int> v1;
	int value_int = 75;
	v1.Add(value_int);
	value_int = -4;
	v1.Add(value_int);
	Vector<int> v2 = v1;
	bool flag = 0;
	for (int i = 0; i < v1.Size(); i++)
		if (v2[i] == v1[i]) flag = 1;
		else
		{
			flag = 0;
			break;
		}
	if (flag) EXPECT_EQ(2, v2.Size());

	Vector<std::complex<float>> v3;
	std::complex<float> value_cfloat(1, -5);
	v3.Add(value_cfloat);
	std::complex<float> value_cfloat2(-1, 78);
	v3.Add(value_cfloat2);
	Vector<std::complex<float>> v4 = v3;
	flag = 0;
	for (int i = 0; i < v1.Size(); i++)
		if (v2[i] == v1[i]) flag = 1;
		else
		{
			flag = 0;
			break;
		}
	if (flag) EXPECT_EQ(2, v2.Size());
}

TEST(Vector, Operator_Addition)
{
	Vector<int> v1, v2, add;
	int value_int = 75;
	v1.Add(value_int);
	value_int = -4;
	v2.Add(value_int);
	add = v1 + v2;
	EXPECT_EQ(71, add[0]);

	Vector<std::complex<float>> v3, v4, cadd;
	std::complex<float> value_cfloat(1, -5);
	v3.Add(value_cfloat);
	std::complex<float> value_cfloat2(-1, 78);
	v4.Add(value_cfloat2);
	cadd = v3 + v4;
	std::complex<float> res(0, 73);
	EXPECT_EQ(res, cadd[0]);
}

TEST(Vector, Operator_Subtraction)
{
	Vector<int> v1, v2, sub;
	int value_int = 75;
	v1.Add(value_int);
	value_int = -4;
	v2.Add(value_int);
	sub = v1 - v2;
	EXPECT_EQ(79, sub[0]);

	Vector<std::complex<float>> v3, v4, csub;
	std::complex<float> value_cfloat(1, -5);
	v3.Add(value_cfloat);
	std::complex<float> value_cfloat2(-1, 78);
	v4.Add(value_cfloat2);
	csub = v3 - v4;
	std::complex<float> res(2, -83);
	EXPECT_EQ(res, csub[0]);
}

TEST(Vector, Operator_Multiplication)
{
	Vector<int> v1, v2;
	int mul;
	int value_int = 75;
	v1.Add(value_int);
	value_int = -4;
	v2.Add(value_int);
	mul = v1 * v2;
	EXPECT_EQ(-300, mul);

	Vector<std::complex<float>> v3, v4;
	std::complex<float> cmul = 0;
	std::complex<float> value_cfloat(1, -5);
	v3.Add(value_cfloat);
	std::complex<float> value_cfloat2(-1, 78);
	v4.Add(value_cfloat2);
	cmul = v3 * v4;
	std::complex<float> res(389, 83);
	EXPECT_EQ(res, cmul);
}

TEST(Vector, Operator_Division)
{
	Vector<int> v1, v2, div1, div2;
	int a = 4;
	int value_int = 75;
	v1.Add(value_int);
	value_int = -4;
	v2.Add(value_int);
	div1 = v1/a;
	div2 = v2/a;
	if ((div1[0] == 18) && (div2[0] == -1)) EXPECT_EQ(1, 1);
	else EXPECT_EQ(0, 0);

	Vector<std::complex<float>> v3, v4, cdiv1, cdiv2;
	std::complex<float> ca(2, 32);
	std::complex<float> value_cfloat(1, -5);
	v3.Add(value_cfloat);
	std::complex<float> value_cfloat2(-1, 78);
	v4.Add(value_cfloat2);
	cdiv1 = v3 / ca;
	cdiv2 = v4 / ca;
	std::complex<float> res1(-0.153696, -0.040856);
	std::complex<float> res2(2.42607, 0.182879);
	if ((cdiv1[0] == res1) && (cdiv2[0] == res2)) EXPECT_EQ(1, 1);
	else EXPECT_EQ(0, 0);
}

TEST(Vector, Operator_Multiplicatoin_Const)
{
	Vector<int> v1, v2, mul1, mul2;
	int a = 2;
	int value_int = 75;
	v1.Add(value_int);
	value_int = -4;
	v2.Add(value_int);
	mul1 = v1 * a;
	mul2 = v2 * a;
	if ((mul1[0] == 150) && (mul2[0] == -8)) EXPECT_EQ(1, 1);
	else EXPECT_EQ(0, 0);

	Vector<std::complex<float>> v3, v4, cmul1, cmul2;
	std::complex<float> ca(2, 2);
	std::complex<float> value_cfloat(1, -5);
	v3.Add(value_cfloat);
	std::complex<float> value_cfloat2(-1, 78);
	v4.Add(value_cfloat2);
	cmul1 = v3 * ca;
	cmul2 = v4 * ca;
	std::complex<float> res1(12, -8);
	std::complex<float> res2(-158, 154);
	if ((cmul1[0] == res1) && (cmul2[0] == res2)) EXPECT_EQ(1, 1);
	else EXPECT_EQ(0, 0);
}