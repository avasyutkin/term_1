#include "pch.h"
#include <iostream>

class matrix {
private:
	int matr[10][10];
	int matr2[10][10];
	int rows = 10, colums = 10;
	int s = 0;
	int inner = 0;
public:
	int inpsw();
	void input();
	void input1();
	void print();
	void print1();
	void sum();
	void multi();
	void transp();
};
int p_rows = 10, p_colums = 10;


int main()
{
	matrix matrA, matrB;
	matrA.inpsw();
	matrA.input();
	matrA.print();
	matrB.input1();
	matrB.print1();
	matrA.sum();
	matrA.print();
	matrA.multi();
	matrA.print();
	matrA.transp();
	matrA.print();
	getchar();
	return 0;
}

int matrix::inpsw()
{
	std::cin >> p_rows >> p_colums;
	return(p_rows, p_colums);
}

void matrix::input()
{
	for (rows = 0; rows < p_rows; rows++) {
		for (colums = 0; colums < p_colums; colums++)
			std::cin >> matr[rows][colums]; //ввод очередного элемента матрицы
	}
}

void matrix::input1()
{
	for (rows = 0; rows < p_rows; rows++) {
		for (colums = 0; colums < p_colums; colums++)
			std::cin >> matr2[rows][colums];
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

void matrix::print1()
{
	for (rows = 0; rows < p_rows; rows++) {
		for (colums = 0; colums < p_colums; colums++)
			std::cout << matr2[rows][colums] << "\t";
		std::cout << std::endl;
	}
}

void matrix::sum()
{
	for (rows = 0; rows < p_rows; rows++) {
		for (colums = 0; colums < p_colums; colums++) 
			matr[rows][colums] = matr[rows][colums] + matr2[rows][colums]; 
	}
}

void matrix::multi()
{
	for (rows = 0; rows < p_rows; rows++) {
		for (colums = 0; colums < p_colums; colums++)
			for (inner = 0; inner < rows; inner++)
				matr[rows][colums] += matr[rows][inner] * matr2[inner][colums];
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
