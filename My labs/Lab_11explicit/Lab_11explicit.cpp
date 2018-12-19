// Lab_11explicit - неявное подключение динамической библиотеки

#include "pch.h"
#include <iostream>
#include <windows.h>

using namespace std;

//Инициализация функции
double(*fun)(double, double);

int main(int argc, char* argv[])
{
	// Загрузка dll
	HMODULE h = LoadLibrary(L"Lab_11dll.dll");

	(FARPROC &)fun = GetProcAddress(h, "ADD");

	//Обращаемся к библиотеке, чтоб посчитать 
	cout << "Calculated value: " << fun(100, 194) << endl;

	getchar();

	//Выгружаем библиотеку из системной памяти
	FreeLibrary(h);

	cout << "Press any key for exit!" << endl;

	getchar();

	return 0;
}