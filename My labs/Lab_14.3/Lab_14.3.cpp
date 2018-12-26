//Lab_14.3 - проверка палиндрома через дек

#include "pch.h"
#include <iostream>
#include <string>
#include <deque> //подключили библиотеку для использования дека

int main()
{
	std::deque<std::string>p1;
	std::string input;
	std::cin >> input;
	p1.push_back(input);
	while (p1.size() > 1 && p1.front() == p1.back())
	{
		if (p1.front() == p1.back())
		{
			p1.pop_front();
			if (!p1.empty())
				p1.pop_back();
		}
		else
			std::cout << "no" << std::endl;
	}
	if (p1.size() == 1)
	{
		p1.pop_back();
		std::cout << "yes" << std::endl;
	}
	else
		std::cout << "no" << std::endl;
	/*if (p1.empty())
		std::cout << "yes" << std::endl;
	else
		std::cout << "no" << std::endl;*/
}
/*
	ДЕК(англ.deque – аббревиатура от double - ended queue, двухсторонняя очередь)
	называется структура данных, в которую можно удалять и добавлять элементы
	как в начало, так и в конец.

	Дек хранится в памяти так же, как и очередь.
*/