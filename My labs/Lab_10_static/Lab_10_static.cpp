
#include "static.h"
#include <iostream>

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

	std::cout << "A + B \n" << A + B << std::endl;
	std::cout << "A - B \n" << A - B << std::endl;
	std::cout << "A * B \n" << A * B << std::endl;

	A.del();
	B.del();

	getchar();
	return 0;
}