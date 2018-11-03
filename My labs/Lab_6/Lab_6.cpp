#include "pch.h" 
#include <iostream> 

class matrix {
private:
	int colums;
	int matr[10][10];
	int p_rows = 10, p_colums = 10;


public:
	void inpsw();
	void input();

	void print();

	bool sum(matrix matr2);
	bool multi(matrix matr2);
	void transp();
	int getelem(int i, int j) {
		return matr[i][j];
	} 
	int getrows() {
		return rows;
	}
	int getcolums(){
		return colums;
	}
};

/*class vector :public matrix {
private:
	int colums;
	int matr[10][10];
	int p_rows = 10, p_colums = 10;


public:
	void inpsw();
	void input();

	void print();

	void sum(matrix matr2);
	void multi(matrix matr2);
	void transp();
	int getelem(int i, int j) {
		return matr[i][j];
	}
};
*/
int main()
{
	matrix matrA, matrB;
	matrA.inpsw();
	matrA.input();
	matrA.print();

	matrB.inpsw();
	matrB.input();
	matrB.print();

	matrA.sum(matrB);
	matrA.print();
	matrA.multi(matrB);
	matrA.print();
	matrA.transp();
	matrA.print();
	getchar(); 
	return 0;
}

int rows = 0, colums = 0;

void matrix::inpsw()
{
	std::cin >> p_rows >> p_colums;
}

void matrix::input()
{
	for (rows = 0; rows < p_rows; rows++) {
		for (colums = 0; colums < p_colums; colums++)
			std::cin >> matr[rows][colums]; //ввод очередного элемента матрицы 
	}
}

void matrix::print()
{
	for (rows = 0; rows < p_rows; rows++) {
		for (colums = 0; colums < p_colums; colums++)
			std::cout << matr[rows][colums] << "\t"; //вывод очередного элемента матрицы 
		std::cout << std::endl; //переход на новую строку после вывода всех элементов строки 
	}
}
bool matrix::sum(matrix matr2)
{
	if (rows != matr2.getrows()) {
		return false;
	}
	if (colums != matr2.getcolums()) {
		return false;
	}
	for (rows = 0; rows < p_rows; rows++) {
		for (colums = 0; colums < p_colums; colums++)
			matr[rows][colums] = matr[rows][colums] + matr2.getelem(rows, colums);
	}
	return true;
}

bool matrix::multi(matrix matr2)
{
	if (colums != matr2.getrows())
	{
		return false;
	{
		int inner = 0;
		int s = 0;
		for (rows = 0; rows < p_rows; rows++) {
			for (colums = 0; colums < p_colums; colums++)
				for (inner = 0; inner < rows; inner++)
					matr[rows][colums] += matr[rows][inner] * matr2.getelem(inner, colums);
			}
		}
	}
}

void matrix::transp()
{
	int o = 0;
	for (rows = 0; rows < p_rows; rows++) {
		for (colums = rows; colums < p_colums; colums++) {
			int o = matr[rows][colums];
			matr[rows][colums] = matr[colums][rows];
			matr[colums][rows] = o;
		}
	}
}
