//Lab_2 - табуляция
#include "pch.h"
#include <iostream>

int main()
{
	setlocale(0, "");

	std::cout << "новая строка \t \t \t \\n \n";
	std::cout << "горизонтальная табуляция \t \\t \n";
	std::cout << "вертикальная табуляция \t \t \\v \n";
	std::cout << "стирание назад \t \t \t \\b \n";
	std::cout << "возврат каретки \t \t \\r \n";
	std::cout << "перевод страницы \t \t \\f \n";
	std::cout << "предупреждение \t \t \t \\a \n";
	std::cout << "обратная косая черта \t \t \\\\ \n";
	std::cout << "вопросительный знак \t \t \\? \n";
	std::cout << "одинарная кавычка \t \t \\' \n";
	std::cout << "двойная кавычка \t \t \\\" \n";
	std::cout << "нуль-символ \t \t \t \\0 \n";

	getchar();
}