#include "pch.h"
#include <iostream> 
#include "Lab_6.h"


class matrix {

private:
	int matr[10][10];
	int matr2[10][10];
	int rows = 10, colums = 10;

public:
	matrix();
	~matrix();
	void setMatrix(int p_rows, int p_colums, int p_matr[10][10]);
	void input();
	void matr2();
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
	matrB.matr2();
	matrB.print();
	matrA.transp();
	matrA.print();
	matrA.sumMatrix(matrB);
	matrA.print();
	matrA.multMatrix(matrB);
	matrA.print();
	getchar();
	return 0;
}

matrix::matrix() //ЗОЧЕМ ЭТА НАДА
{
}

matrix::~matrix() // И ЭТА
{
}

void matrix::setMatrix(int p_rows, int p_colums, int p_matr[10][10]) //И ЭТА ТОЖИ
{
	std::cin >> p_rows >> p_colums;
}

void matrix::input()
{
	std::cin >> rows >> colums;
	for (rows = 0; rows < p_rows; rows++) {
		for (colums = 0; colums < p_colums; colums++)
			std::cin >> matr[rows][colums]; //ввод очередного элемента матрицы
	}
}

void matrix::matr2()
{
	std::cin >> rows >> colums;
	for (rows = 0; rows < p_rows; rows++) {
		for (colums = 0; colums < p_colums; colums++)
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
	//system("pause");
	 
}void matrix::sumMatrix(matrix matr2)
{
	for (rows = 0; rows < 3; rows++) {
		for (colums = 0; colums < 3; colums++) {
			matr[rows][colums] = matr[rows][colums] + matr2[rows][colums]; //суммирует две одинаковые матрицы. почему? НАПИСАТЬ ФУНКЦИЯ ДЛЯ МАТР2
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
		for (colums = rows; colums < 3; colums++) { 
			int o = matr[rows][colums];
			matr[rows][colums] = matr[colums][rows];
			matr[colums][rows] = o;
		}
	}
}