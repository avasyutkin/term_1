#include "pch.h"
#include <iostream> 


class matrix {

private:
	int matr[3][3];
	int rows = 3, colums = 3;
public:
	matrix();
	~matrix();
	void setMatrix(int p_rows, int p_colums, int p_matr[3][3]);
	void input();
	void print();

	void sumMatrix(matrix matr2);
	void multMatrix(matrix matr2);
	void transp();


};

int main()
{
	matrix matrA, matrB;
	matrA.input();
	matrA.print();
	matrB.input();
	matrB.print();
	matrA.transp();
	matrA.print();
	matrA.sumMatrix(matrB);
	matrA.print();
	matrA.multMatrix(matrB);
	matrA.print();
	return 0;
	getchar();
}

matrix::matrix() //ЗОЧЕМ ЭТА НАДА
{
}

matrix::~matrix() // И ЭТА
{
}

void matrix::setMatrix(int p_rows, int p_colums, int p_matr[3][3]) //И ЭТА ТОЖИ
{

}

void matrix::input()
{
	for (rows = 0; rows < 3; rows++) {
		for (colums = 0; colums < 3; colums++) 
			std::cin >> matr[rows][colums]; //ввод очередного элемента матрицы
	}
}

void matrix::print()
{
	for (rows = 0; rows < 3; rows++){
		for (colums = 0; colums < 3; colums++)
			std::cout << matr[rows][colums] << "\t"; //вывод очередного элемента матрицы
		std::cout << std::endl; //переход на новую строку после вывода всех элементов строки
	}
	system("pause");
}

void matrix::sumMatrix(matrix matr2)
{
	for (rows = 0; rows < 3; rows++) {
		for (colums = 0; colums < 3; colums++) {
			matr[rows][colums] = matr[rows][colums] + matr[rows][colums]; //суммирует две одинаковые матрицы. почему?
		}
	}
}

void matrix::multMatrix(matrix matr2)
{
	
}

void matrix::transp()
{
	int o = 0;
	for (rows = 0; rows < 3; rows++) {
		for (colums = rows; colums < 3; colums++) { //почему колумс = ровс? а не тоже 0
			int o = matr[rows][colums];
			matr[rows][colums] = matr[colums][rows];
			matr[colums][rows] = o;
		}
	}
}