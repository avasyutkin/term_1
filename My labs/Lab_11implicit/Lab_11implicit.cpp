// Lab_11implicit - явное подключение динамической бибилиотеки

#include "pch.h"
#include "Lab_11dll.h"
#include <iostream>

using namespace std;

//Подключение к библиотеке
#pragma comment (lib, "Lab_11dll.lib")

int main(int argc, char* argv[])
{
	cout << "Calculated value: " << ADD(100.567, 194.6) << endl;

	cout << "Press any key for exit!" << endl;

	getchar();

	return 0;
}