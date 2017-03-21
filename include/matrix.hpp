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
	int line_();
	int column_();
	Matrix& operator= (const Matrix &C);
	Matrix operator+ (const Matrix B)const;
	Matrix operator * (const Matrix B)const;
	const bool operator == (const Matrix &C);
	friend ostream& operator << (ostream &out, const Matrix &C);
	friend istream& operator >> (istream &in, const Matrix &C);
	void scan(string)const;
};
