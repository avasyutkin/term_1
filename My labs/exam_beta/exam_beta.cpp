#include "pch.h"
#include <iostream>

class stroks
{
	stroks()
	{
		char stro;
		char *stro = new char[0];
	}
	stroks()
	{
		char *stro = new char[ur];
		for (int i = 0; i < ur; i++)
		{
			stro[i] = stradd[i];
		}
	}

public:
	char *stradd;
	int ur;
	void add();
	void clear();
	void insert();
	void cut();

};

int main()
{

}

void stroks::add()
{
	std::cout << "Введите строку" << std::endl;
	std::cin >> stradd;
	while (stradd != 0)
	{
		ur = ur + 1;
	}

}