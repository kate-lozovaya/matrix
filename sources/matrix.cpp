#include "matrix.hpp"
#include <iostream>
using namespace std;

Matrix::Matrix()
{
	line = column = 0;
	this->A = nullptr;
}
Matrix::Matrix(int a, int b)
{
	line = a;
	column = b;
	A = new int*[line];
	for (int i = 0; i < line; ++i)
	{
		A[i] = new int[column];
		for (int j = 0; j < column; ++j)
			A[i][j] = 0;
	}
}
Matrix::Matrix(const Matrix &C)
{
	line = C.line;
	column = C.column;
	A = new int*[line];
	for (int i = 0; i < line; ++i)
	{
		A[i] = new int[column];
		for (int j = 0; j < column; ++j)
			A[i][j] = C.A[i][j];
	}
}
Matrix::~Matrix()
{
	for (int i = 0; i < line; ++i)
		delete[]A[i];
	delete[]A;
}
int Matrix::line_()
{
	return line;
}
int Matrix::column_()
{
	return column;
}
int Matrix::el_(int i, int j)
{
	return A[i][j];
}
Matrix Matrix::operator + (Matrix B)const
{
	Matrix C(line, column);
	for (int i = 0; i < line; ++i)
	{
		for (int j = 0; j < column; ++j)
			C.A[i][j] = A[i][j] + B.A[i][j];
	}
	return C;
}
Matrix Matrix::operator * (Matrix B)const
{
	Matrix C(line, B.column);
	for (int i = 0; i < line; ++i)
		for (int j = 0; j < B.column; ++j)
		{
			C.A[i][j] = 0;
			for (int k = 0; k < column; ++k)
				C.A[i][j] = C.A[i][j] + A[i][k] * B.A[k][j];
		}
	return C;
}
Matrix& Matrix:: operator = (const Matrix &C)
{
	if (&C == this)
		return *this;
	for (int i = 0; i < line; ++i)
		delete[]A[i];
	delete[]A;
	A = new int*[C.line];
	for (int i = 0; i < C.line; ++i)
	{
		A[i] = new int[C.column];
		for (int j = 0; j < C.column; ++j)
			A[i][j] = C.A[i][j];
	}
	line = C.line;
	column = C.column;
	return *this;
}
const bool Matrix::operator == (const Matrix &C)
{
	for (int i = 0; i < line; ++i)
		for (int j = 0; j < column; ++j)
		{
			if (A[i][j] == C.A[i][j])
				return true;
			return false;
		}
}
ostream& operator << (ostream &out, Matrix &C)
{

	for (int i = 0; i < C.line; ++i)
	{
		for (int j = 0; j < C.column; ++j)
			out << C.A[i][j] << " ";
		out << endl;
	}
	return out;
}
istream& operator >> (istream &in, Matrix &C)
{
	for (int i = 0; i < C.line; ++i)
	for (int j = 0; j < C.column; ++j)
		in >> C.A[i][j];
	return in;
}
