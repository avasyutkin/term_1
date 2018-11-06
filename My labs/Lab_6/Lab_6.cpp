//Lab_6 - элементарные преобразования матриц при помощи класса
//Lab_7 - элементарные преобразования с векторами при помощи наследованного класса
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
};

class vector :public matrix { //наследованный класс векторов
private:
	bool boo;
	int number = 0;
	int vcolums = 0;
	int vrows = 1;
	int v_rows = 1;
	int vec[10][10];
	int v_colums = 10;

public:
	void inpc();
	void input();
	void printc();

	bool sum(vector vec2);
	bool multi(vector vec2);
	void multnum();
	int getelemc(int i, int j) {
		return vec[i][j];
	}
	int getcolumsc() {
		return vcolums;
	}
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

	vector vecA, vecB;
	vecA.inpc();
	vecA.input();
	vecA.printc();

	vecB.inpc();
	vecB.input();
	vecB.printc();

	vecA.multnum();
	vecA.printc();
	vecA.sum(vecB);
	vecA.printc();
	vecA.multi(vecB);
	vecA.printc();

	getchar(); 
	return 0;
}

int rows = 0, colums = 0;

void matrix::inpsw()
{
	std::cout << "Введите количество строк и столбцов матрицы" << std::endl;
	std::cin >> p_rows >> p_colums;
}

void matrix::input()
{
	std::cout << "Введите элементы матрицы" << std::endl;
	for (rows = 0; rows < p_rows; rows++) {
		for (colums = 0; colums < p_colums; colums++)
			std::cin >> matr[rows][colums]; //ввод очередного элемента матрицы 
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
				std::cout << matr[rows][colums] << "\t"; //вывод очередного элемента матрицы 
			std::cout << std::endl; //переход на новую строку после вывода всех элементов строки 
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

void vector::inpc()
{
	std::cout << "Введите размер вектора" << std::endl;
	std::cin >> v_colums;
}

void vector::input()
{
	std::cout << "Введите элементы вектора" << std::endl;
	for (vcolums = 0; vcolums < v_colums; vcolums++) {
		std::cin >> vec[vrows][vcolums];
	}
}

void vector::printc()
{
	if (!boo) {
		std::cout << "Ошибка!" << std::endl;
	}
	else {
		std::cout << std::endl;
		for (vcolums = 0; vcolums < v_colums; vcolums++) {
			std::cout << vec[vrows][vcolums] << "\t";
		}
		std::cout << std::endl;
	}
}

bool vector::sum(vector vec2)
{
	if (vcolums != vec2.getcolumsc()) {
		boo = false;
	}
	else {
		std::cout << "Мы суммируем векторы..." << std::endl;
		for (vcolums = 0; vcolums < v_colums; vcolums++) {
			vec[vrows][vcolums] = vec[vrows][vcolums] + vec2.getelemc(vrows, vcolums);
		}
		return true;
	}
}

bool vector::multi(vector vec2)
{
	if (vcolums != vec2.getcolumsc()) {
		boo = false;
	}
	else {
		std::cout << "Мы перемножаем векторы..." << std::endl;
		for (vcolums = 0; vcolums < v_colums; vcolums++) {
			vec[vrows][vcolums] = vec[vrows][vcolums] * vec2.getelemc(vrows, vcolums);
		}
		return true;
	}
}

void vector::multnum()
{
	std::cout << "Введите число, на которое нужно умножить вектор" << std::endl;
	std::cin >> number;
	std::cout << "Мы умнажаем вектор на число..." << std::endl;
	for (vcolums = 0; vcolums < v_colums; vcolums++) {
		vec[vrows][vcolums] = vec[vrows][vcolums] * number;
	}
}






/*
Сlass-описание пользовательского сложного типа данных (конструкция с++).
Поля класса - свойства и методы.
Функция, входящая в состав класс,- метод.
Переменная, входящая в состав класса, - свойства.

Автоматизм вызова конструктора и деструктора обеспечивается высокоуровневыми средствами автоматизации языка. К строке, где объявлен объект, компилятор не явно от программиста, дописывает и вызов класса.
инкапсуляция – фактически объединение данных и методов, объединенных единым смыслом в одну конструкцию языка.
Полиморфизм- одно и то же описание ведет себя по-разному. Простыми словами, экземпляры одного класса ведут себя по-разному.
Наследование- создание производных классов от родительского и заимствование его свойств и методов. Инкапсуляция, наследование и полиморфизм –три основных идеи объектно-ориентированного программирования.

ПЕРЕДАЧА В ФУКНЦИЮ МАССИВОВ
fnc1(double a[размер_массива]);

ПЕРЕДАЧА МАССИВОВ В ФУНКЦИЮ
void fnc4_1(int matr[3][3]);
void fnc4_2(int matr[][3]);
void fnc4_3(int(&matr)[3][3]);
void fnc4_4(int ** matr);


1.НАСЛЕДОВАНИЕ КЛАССОВ-заимствование свойств и методов родительского классо дочерним.
синтаксис:
class имя_нового_класса: [тип_наследования] имя_родительского_класса1 

2. Метод переопределенный в дочернем классе полностью заменит унаследованный родительский метод
Чтобы сначала выполнить родительский, а затем наследованный метод, то нужно указать таким способом
в родительском void reload1(){}
в дочернем void reload():void reload1();

3.Если объявить метод с словом virtual, то в данном классе можно не приводить реализацию метода, и определить его только в дочерних классах
ЗАДАНИЕ определить от класса матрицы дочерний класс вектора и дописать ему векторные операции(скалярное и векторное умножение)

4. Приведение типов. при попытке сложитьчисла двух различных типов(double и int), оба операнта автоматически преобразуются к наиболее сложному, длинному типу(double+int=double+doube)если char+int, то строку нужно привести к цифрами
*/