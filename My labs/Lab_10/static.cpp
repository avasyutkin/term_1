#include "static.h"

matrixdyn operator + (matrixdyn A, matrixdyn B)
{
	matrixdyn res;
	res.odim(A.getrows(), A.getcolums());
	if (A.getrows() != B.getrows() || A.getcolums() != B.getcolums())
	{
		std::cout << "Error!\t";
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
		std::cout << "Error!\t";
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
		std::cout << "Error!\t";
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

std::ostream & operator << (std::ostream & os, const matrixdyn & d)
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
			std::cin >>

				matr[i*colums + j];
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