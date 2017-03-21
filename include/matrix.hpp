#include <iostream>
#include <fstream>

using namespace std;

class Matrix
{
private:
	int line, column;
	int**A;

public:
	Matrix();
	Matrix(int a, int b);
	Matrix(const Matrix &C);
	~Matrix();
	int line_()const;
	int column_()const;
	Matrix& operator = (const Matrix &C);
	Matrix operator + (const Matrix B)const;
	Matrix operator * (const Matrix B)const;
	bool operator == (const Matrix &C)const;
	friend ostream& operator << (ostream &out, const Matrix &C);
	friend istream& operator >> (istream &in, Matrix &C);
	void scan(string)const;
};
