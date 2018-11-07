// Lab_7 - элементарные преобразования матриц с помощью динамической памяти 

#include "pch.h"
#include <iostream>

class matrix { //класс матриц
private:
	bool boo;
	int rows;
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
	int getcolums() {
		return colums;
	}
	void del();
};



int main()
{
	setlocale(0, "");

	matrix matrA, matrB;
	matrA.inpsw();
	matrA.input();
	matrA.print();

	matrB.inpsw();
	matrB.input();
	matrB.print();

	matrA.transp();
	matrA.print();
	matrA.sum(matrB);
	matrA.print();
	matrA.multi(matrB);
	matrA.print();

	matrA.del();

	getchar();
	return 0;
}

int rows = 0, colums = 0;

void matrix::inpsw()
{
	std::cout << "Введите количество строк и столбцов матрицы" << std::endl;
	std::cin >> p_rows >> p_colums;
	matr[rows][colums] = *new int [p_rows];   //Выделение памяти под двумерный массив 
	for (int rows = 0; rows < p_rows; rows++) {
		matr[rows][colums] = *new int[p_colums];
	}
}

void matrix::input()
{
	std::cout << "Введите элементы матрицы" << std::endl;
	for (rows = 0; rows < p_rows; rows++) {
		for (colums = 0; colums < p_colums; colums++)
			std::cin >> matr[rows][colums]; 
	}
}

void matrix::print()
{
	if (!boo) {
		std::cout << "Ошибка!" << std::endl;
	}
	else {
		std::cout << std::endl;
		for (rows = 0; rows < p_rows; rows++) {
			for (colums = 0; colums < p_colums; colums++)
				std::cout << matr[rows][colums] << "\t"; 
			std::cout << std::endl; 
		}
	}
}

bool matrix::sum(matrix matr2)
{
	if (rows != matr2.getrows() or colums != matr2.getcolums())
	{
		boo = false;
		return false;
	}
	else {
		std::cout << "Мы суммируем матрицы..." << std::endl;
		for (rows = 0; rows < p_rows; rows++)
		{
			for (colums = 0; colums < p_colums; colums++)
				matr[rows][colums] = matr[rows][colums] + matr2.getelem(rows, colums);
		}
		return true;
	}
}

bool matrix::multi(matrix matr2)
{
	if (colums != matr2.getrows() or rows != matr2.getcolums())
	{
		boo = false;
	}
	if (rows == matr2.getcolums() and colums == matr2.getrows())
	{
		std::cout << "Мы перемножаем матрицы..." << std::endl;
		int inner = 0;
		int s = 0;
		for (rows = 0; rows < p_rows; rows++) {
			for (colums = 0; colums < p_colums; colums++) {
				for (inner = 0; inner < rows; inner++)
					matr[rows][colums] += matr[rows][inner] * matr2.getelem(inner, colums);
			}
		}
		return true;
	}
}

void matrix::transp()
{
	std::cout << "Мы транспонируем матрицу..." << std::endl;
	int o = 0;
	for (rows = 0; rows < p_rows; rows++) {
		for (colums = rows; colums < p_colums; colums++) {
			int o = matr[rows][colums];
			matr[rows][colums] = matr[colums][rows];
			matr[colums][rows] = o;
		}
	}
}

void matrix::del() //Очищение памяти
{
	for (rows = 0; rows < p_rows; rows++)
		delete[] matr[p_colums];
}
