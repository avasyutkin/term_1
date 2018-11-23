// Lab_9 - перегрузка операторов

#include "pch.h"
#include <iostream>
#include <fstream>

class matrixdyn
{
protected:
	double *matr;
	int rows;
	int	colums;
	bool boo;
public:
	virtual void create();
	virtual void input();
	void print();
	void transp();
	int getrows() const
	{
		return rows;
	}
	int getcolums() const
	{
		return colums;
	}
	double getelem(int r, int c) const
	{
		return matr[r*colums + c];
	}
	void olelem(int oro, int oco, double oel) 
	{
		matr[oro*colums + oco] = oel;
	}
	void odim(int oro, int oco)
	{
		rows = oro;
		colums = oco;
		matr = new double[rows*colums];
	}
	friend std::ostream& operator<<(std::ostream& os, const matrixdyn& d);
	void del();
};

class vectordyn : public matrixdyn
{
public:
	void virtual input();
	void virtual create();
};

int main()
{
	setlocale(0, "");

	matrixdyn A, B;
	A.create();
	A.input();
	std::cout << "Матрица A \n";
	A.print();

	B.create();
	B.input();
	std::cout << "Матрица B \n";
	B.print();

	A.transp();

	std::cout << "A + B" << A + B << std::endl;
	std::cout << "A - B" << A - B << std::endl;
	std::cout << "A * B" << A * B << std::endl;

	A.del();
	B.del();


	vectordyn C, D;
	C.create();
	C.input();
	std::cout << "Вектор C \n";
	C.print();

	D.create();
	D.input();
	std::cout << "Вектор D \n";
	D.print();

	std::cout << "C * 7" << C * 7 << std::endl;
	std::cout << "C + D" << C + D << std::endl;
	std::cout << "C * D" << C * D << std::endl;

	C.del();
	D.del();

	getchar();
	return 0;
}

matrixdyn operator + (matrixdyn A, matrixdyn B) 
{
	matrixdyn res;
	res.odim(A.getrows(), A.getcolums());
	if (A.getrows() != B.getrows() || A.getcolums() != B.getcolums())
	{
		std::cout << "Error!" << std::endl;
		return A;
	}
	for (int i = 0; i < B.getrows(); i++)
		for (int j = 0; j < A.getcolums(); j++)
			res.olelem(i, j, A.getelem(i, j) + B.getelem(i, j));
	return res;
}

matrixdyn operator - (matrixdyn A, matrixdyn B)
{
	matrixdyn res;
	res.odim(A.getrows(), A.getcolums());
	if (A.getrows() != B.getrows() || A.getcolums() != B.getcolums())
	{
		std::cout << "Error!" << std::endl;
		return A;
	}
	for (int i = 0; i < B.getrows(); i++)
		for (int j = 0; j < A.getcolums(); j++)
			res.olelem(i, j, A.getelem(i, j) - B.getelem(i, j));
	return res;
}

matrixdyn operator * (matrixdyn A, matrixdyn B)
{
	matrixdyn res;
	if (A.getcolums() != B.getrows())
	{
		std::cout << "Error!" << std::endl;
		return A;
	}
	res.odim(A.getrows(), B.getcolums());
	int rows = A.getrows();
	int temp = A.getcolums();
	int colums = B.getcolums();
	for (int j = 0; j < colums; j++) 
		for (int i = 0; i < rows; i++) 
		{
			double x = 0;
			for (int t = 0; t < temp; t++)
				x += A.getelem(i, t)*B.getelem(t, j);
			res.olelem(i, j, x);
		}
	return res;
}

std::ostream & operator<<(std::ostream & os, const matrixdyn & d)
{
	for (int i = 0; i < d.getrows(); i++) {
		for (int j = 0; j < d.getcolums(); j++)
			os << d.getelem(i, j) << "\t";
		os << "\n";
	}
	return os;
}

void matrixdyn::create()
{
	int p_rows;
	int p_colums;
	std::cout << "Введите количество строк" << std::endl;
	std::cin >> p_rows;
	std::cout << "Введите количество столбцов" << std::endl;
	std::cin >> p_colums;
	std::cout << "\n";
	rows = p_rows;
	colums = p_colums;
	matr = new double[rows*colums];
}

void matrixdyn::input()
{
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < colums; j++)
		{
			std::cout << "Матрица[" << i + 1 << "][" << j + 1 << "]";
			std::cin >> matr[i*colums + j];
		}
	std::cout << "\n";
	boo = true;
}

void matrixdyn::print()
{
	if (!boo)
	{
		std::cout << "Error!" << "\n" << "\n";
		boo = true;
	}
	else
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < colums; j++)
				std::cout << matr[i*colums + j] << "\t";
			std::cout << std::endl;
		}
		std::cout << "\n";
	}
}

void matrixdyn::transp()
{
	double *matr3 = new double[rows*colums];
	if (rows != colums)
	{
		std::cout << "Мы транспонируем только квадратные матрицы.\n" << std::endl;
	}
	else
	{
		std::cout << "Мы транспонируем матрицу A..." << std::endl;
		int o = 0;
		for (int i = 0; i < rows; i++)
			for (int j = i; j < colums; j++)
			{
				int o = matr[i*colums + j];
				matr[i*colums + j] = matr[j*rows + i];
				matr[j*rows + i] = o;
			}
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < colums; j++)
				std::cout << matr[i*colums + j] << "\t";
			std::cout << std::endl;
		}
		std::cout << "\n";
	}
}

void matrixdyn::del()
{
	if (matr != NULL)
	{
		delete matr;
		matr = NULL;
	}
	else
		std::cout << "Тут чисто!" << std::endl;
}

void vectordyn::input()
{
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < colums; j++)
		{
			std::cout << "Вектор[" << j + 1 << "] = ";
			std::cin >> matr[i*colums + j];
		}
	std::cout << "\n";
	boo = true;
}

void vectordyn::create()
{
	int p_rows = 1;
	int p_colums;
	std::cout << "Количество строк = 1" << std::endl;
	std::cout << "Введите количество столбцов" << std::endl;
	std::cin >> p_colums;
	colums = p_colums;
	rows = p_rows;
	matr = new double[rows*colums];
}

vectordyn operator * (vectordyn C, int k) 
{
	vectordyn result;
	int u = C.getrows();
	int uu = C.getcolums();
	result.odim(u, uu);
	for (int i = 0; i < u; i++)
		for (int j = 0; j < uu; j++) 
		{
			double a = C.getelem(i, j);
			result.olelem(i, j, k*a);
		}
	return result;
}

vectordyn operator * (vectordyn C, vectordyn D)
{
	matrixdyn K = C;
	matrixdyn M = D;
	M.transp();
	if (K.getcolums() != M.getrows())
		std::cout << "Error!" << std::endl;
	matrixdyn X = K * M;
	return X.getelem(0, 0);
}
