#include "matrix.hpp"

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

Matrix::void scan(string filename)const
{
	ifstream fin;
	fin.open(filename);
	if (!fin.is_open())
		cout << "The file isn't find" << endl;
	else
	{
		for (int i = 0; i < line; ++i)
		{
			for (int j = 0; j < column; ++j)
			{
				if (!fin.eof())
				{
					fin >> A[i][j];
				}else A[i][j] = 0;
			}
		}
	}
	fin.close();
}

Matrix::void print(ostream&steam)const
{
	for (int i = 0; i < line; ++i)
	{
		for (int j = 0; j < column; ++j)
			steam << A[i][j] << " ";
		steam << endl;
	}
}

Matrix::Matrix& operator= (const Matrix &C)
{
       for (int i = 0; i < line; ++i)
		delete[]A[i];
	delete[]A;
	for(int i = 0; i < line; ++i)
           for(int j = 0; j < column; ++j)
               a[i][j] = C.A[i][j];
       return *this;
}

Matrix::Matrix operator+ (Matrix B)const
{
	Matrix C(line, column);
	for (int i = 0; i < line; ++i)
	{
		for (int j = 0; j < column; ++j)
			C.A[i][j] = A[i][j] + B.A[i][j];
	}
	return C;
}

Matrix::Matrix operator * (Matrix B)const
{
	Matrix C(line, column);
	for (int i = 0; i < line; ++i)
	for (int j = 0; j < B.column; ++j)
	{
		C.A[i][j] = 0;
		for (int k = 0; k < column; ++j)
			C.A[i][j] += A[i][k] * B.A[k][j];
	}
	return C;
}

int main()
{
	Matrix m1, m2;
	int line, column;
	string filename;
	cout << "ADDITION" << endl << "Enter the number of lines ";
	cin >> line;
	cout << "Enter the number of columns ";
	cin >> column;
	m1 = m2 = Matrix(line, column);
	cout << "Enter the file name for the first matrix" << endl;
	cin >> filename;
	m1.scan(filename);
	filename = "";
	cout << "Enter the file name for the second matrix" << endl;
	cin >> filename;
	m2.scan(filename);
	filename = "";
	cout << endl << "The first matrix" << endl;
	m1.print(cout);
	cout << endl << "The second matrix" << endl;
	m2.print(cout);
	m1 = m1 + m2;
	cout << endl << "Result" << endl;
	m1.print(cout);
	cout << endl << endl << "MULTIPLICATION" << endl << "Enter the number of lines of the first matrix ";
	cin >> line;
	cout << "Enter the number of columns of the first matrix (the number of lines of the second matrix) ";
	cin >> column;
	m1 = Matrix(line, column);
	line = column;
	cout << "Enter the number of columns of the second matrix ";
	cin >> column;
	m2 = Matrix(line, column);
	cout << "Enter the file name for the first matrix" << endl;
	cin >> filename;
	m1.scan(filename);
	filename = "";
	cout << "Enter the file name for the second matrix" << endl;
	cin >> filename;
	m2.scan(filename);
	cout << "The first matrix" << endl;
	m1.print(cout);
	cout << "The second matrix" << endl;
	m2.print(cout);
	m1 = m1*m2;
	cout << "Result" << endl;
	m1.print(cout);
	system("pause");
	return 0;
}
