// Lab_9 - перегрузка операторов 

#include "pch.h" 
#include <iostream> 

class matrixdyn
{
protected:
	double *matr;
	int rows;
	int colums;
	bool boo;
public:
	virtual void create();
	virtual void input();
	void print();
	void plus(matrixdyn matr2);
	void mult(matrixdyn matr2);
	void transp();
	int getrows()
	{
		return rows;
	}
	int getcolums()
	{
		return colums;
	}
	double getelem(int r, int c)
	{
		return matr[r*colums + c];
	}
	void del();
};

class vectordyn : public matrixdyn
{
public:
	virtual void input();
	virtual void create();
	void xmult(double k);
	double scalmultvector(vectordyn vec2);
};

int main()
{
	setlocale(0, "");

	matrixdyn matrA, matrB;
	matrA.create();
	matrA.input();
	std::cout << "Матрица A \n";
	matrA.print();

	matrB.create();
	matrB.input();
	std::cout << "Матрица B \n";
	matrB.print();

	matrA.transp();

	matrA.plus(matrB);
	std::cout << "A + B \n";
	matrA.print();

	matrA.mult(matrB);
	std::cout << "A * B \n";
	matrA.print();

	matrA.del();
	matrB.del();


	vectordyn matrA1, matrB1;
	matrA1.create();
	matrA1.input();
	std::cout << "Вектор A \n";
	matrA1.print();

	matrB1.create();
	matrB1.input();
	std::cout << "Вектор B \n";
	matrB1.print();

	matrA1.xmult(10);
	std::cout << "А * 10 \n";
	matrA1.print();

	matrA1.plus(matrB1);
	std::cout << "A * 10 + B \n";
	matrA1.print();

	double f = matrA1.scalmultvector(matrB1);
	std::cout << "(A * 10 + B) * B \n" << f << std::endl;

	matrA1.del();
	matrB1.del();

	getchar();
	return 0;
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

void matrixdyn::plus(matrixdyn matr2)
{
	if (rows != matr2.getrows() || colums != matr2.getcolums())
	{
		boo = false;
	}
	else {
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < colums; j++)
				matr[i*colums + j] += matr2.getelem(i, j);
	}
}

void matrixdyn::mult(matrixdyn matr2)
{
	if (colums != matr2.getrows())
		boo = false;
	else
	{
		double x = 0;
		double *matr3 = new double[rows*matr2.getcolums()];
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < matr2.getcolums(); j++) {
				for (int t = 0; t < colums; t++)
					x += matr[i*colums + t] * matr2.getelem(t, j);
				matr3[i * matr2.getcolums() + j] = x;
				x = 0;
			}
		}
		delete[] matr;
		matr = new double[rows * matr2.getcolums()];
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < matr2.getcolums(); j++) {
				matr[i * matr2.colums + j] = matr3[i * matr2.getcolums() + j];
			}
		}
		colums = matr2.getcolums();
		boo = true;
		delete[] matr3;

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

void vectordyn::xmult(double k)
{
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < colums; j++)
			matr[i*colums + j] *= k;
}

double vectordyn::scalmultvector(vectordyn vec2)
{
	double product = 0;
	if (colums != vec2.getcolums())
	{
		boo = false;
		std::cout << "Мы вычисляем скалярное произведение только равных векторов.\n" << std::endl;
	}
	else
	{
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < colums; j++)
				product = product + matr[i*colums + j] * vec2.getelem(i, j);
		return product;
	}
}