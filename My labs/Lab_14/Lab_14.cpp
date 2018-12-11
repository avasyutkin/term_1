#include "pch.h"
#include <iostream>
#include <string>
#include <stack> // подключаем библиотеку для использования стека
#include <queue> // подключили библиотеку для использования очереди
#include <deque> // подключили библиотеку для использования  дека

/*
#include <list> // подключили библиотеку для использования списка
#include <set> // подключили библиотеку для использования множества
#include <map> // подключили библиотеку для использования ассоциативного массива
*/

int main()
{
	setlocale(LC_ALL, "rus");

	/*
	СТЕК — это структура данных, которая работает
	по принципу FILO(first in — last out; первый пришел — последний ушел).

	В стеке нет индексов,т.е. нельзя обратиться к определенному элементу.
	Каждый элемент имеет указатель на следующий элемент.
	Головной элемент указывает на NULL.

	Достоинство: операции удаления и добавления элемента делаются за const время.
	*/

	/*std::stack<int> stackInt;//stack <тип данных> <имя>; -создание стека
	int i = 0, a = 0;
	std::cout << "Введите 5 целых чисел: " << std::endl;
	while (i != 5) {
		std::cin >> a;
		stackInt.push(a);  // добавляем введенное число
		i++;
	}

	if (stackInt.empty()) // проверяем пуст ли стек (нет)
		std::cout << "Стек не пуст";

	std::cout << "Верхний элемент стека: " << stackInt.top() << std::endl;
	stackInt.pop();  // удаляем верхний элемент

	std::cout << "Новый верхний элемент: " << stackInt.top() << std::endl;
	*/
	/* 
	ЗАДАНИЕ 1

	Проверить правильность расстановки скобок(, ), [, ], { , }
	в введенном пользователем выражении за линейное время (один просмотр выражения).
	
	Считываем элемент.
	Если это(, [или{ , то помещаем ее в стек.
	Если это),] или }, то сравниваем с верхним элементом стека.
	Если образовалась пара, то верхний элемент стека удаляем.
	Иначе - выражение неправильное.

	Когда все элементы считали, то проверяем стек на пустоту.
	Если стек пуст, то выражение правильное.
	Иначе - выражение неправильное.
	*/
	//РЕШЕНИЕ 1



	/*
	ОЧЕРЕДЬ — это структура данных, которая построена по принципу
	LILO(last in — last out : последним пришел — последним вышел).
	*/

	/*std::queue <int> MyQueue;  // создали очередь
	std::cout << "Введите 7 чисел: " << std::endl;
	for (i = 0; i < 7; i++) {
		std::cin >> a;
		MyQueue.push(a);  // добавляем в очередь элементы
	}
	std::cout << std::endl;
	std::cout << "Первый элемент в очереди: " << MyQueue.front() << std::endl;
	MyQueue.pop();  // удаляем элемент из очереди
	std::cout << "Первый элемент (после удаления): " << MyQueue.front() << std::endl;

	if (!MyQueue.empty()) // проверяем пуста ли очередь (нет)
		std::cout << "Очередь не пуста!";
	*/
	/*
	Очередь с приоритетом(priority_queue) — это обычная очередь,
	но в ней новый элемент добавляется в такое место,
	чтобы очередь была отсортирована по убыванию.
	*/
	/*
	std::priority_queue <int> priority_q;  // объявляем приоритетную очередь

	std::cout << "Введите 7 чисел: " << std::endl;
	for (i = 0; i < 7; i++) {
		std::cin >> a;
		priority_q.push(a);  // добавляем элементы в очередь
		//std::copy(priority_q.pop(),priority_q.top(), std::ostream_iterator(std::cout, " "));
	}
	// выводим первый
	std::cout << "Первый элемент очереди: " << priority_q.top();
	*/
	/*
	ЗАДАНИЕ 2

	Программа на вход получает список школьников.
	В каждой строке сначала записан номер класса(число, равное 9, 10 или 11), затем(через пробел) – фамилия.
	Необходимо вывести список по классам :
	сначала всех учащихся 9 класса, затем – 10, затем – 11.
	Внутри одного класса порядок вывода должен быть таким же, как на входе.
	*/

	//РЕШЕНИЕ 2
	std::queue<std::string> Class_9;
	std::queue<std::string> Class_10;
	std::queue<std::string> Class_11;

	int input_class;
	std::cin >> input_class;

	while (input_class != 0)
	{

		if (input_class == 9)
		{
			std::string student;
			std::cin >> student;
			Class_9.push(student);
		}

		if (input_class == 10)
		{
			std::string student;
			std::cin >> student;
			Class_10.push(student);
		}

		if (input_class == 11)
		{
			std::string student;
			std::cin >> student;
			Class_11.push(student);
		}

		std::cin >> input_class;

	}

	while (!Class_9.empty())
	{
		std::cout << Class_9.front() << std::endl;
		Class_9.pop();
	}

	while (!Class_10.empty())
	{
		std::cout << Class_10.front() << std::endl;
		Class_10.pop();
	}

	while (!Class_11.empty())
	{
		std::cout << Class_11.front() << std::endl;
		Class_11.pop();
	}

	/*
	ДЕК(англ.deque – аббревиатура от double - ended queue, двухсторонняя очередь)
	называется структура данных, в которую можно удалять и добавлять элементы
	как в начало, так и в конец.

	Дек хранится в памяти так же, как и очередь.
	*/

	/*
	ЗАДАЧА 3
	Проверить, является ли введенная строка палиндромом
	(читается одинаково слева направо и справа налево). Использовать дек.

	Считываем строку посимвольно. каждый символ добавляем в хвост дека.
	Далее сравниваем первый и последний символ дека.
	*/

	//ЗАДАЧА 4
	/*
	Описать структуру данных List.
	Продемонстрировать работу с этой структурой:
	ввод, вывод,
	добавление элемента и удаление,
	сортировка.
	*/

	//ЗАДАЧА 5
	/*
	Описать структуру данных Set.
	Продемонстрировать работу с этой структурой:
	ввод, вывод,
	добавление элемента и удаление.
	*/

	//ЗАДАЧА 6
	/*
	Описать структуру данных map.
	Продемонстрировать работу с этой структурой:
	ввод, вывод,
	добавление элемента и удаление.
	*/

	// ЗАДАЧА 7
	/*
	Составить таблицу сравнения по времени выполнения операций
	для дека, стека, очереди, списка, множества, массива из n элементов.
	Список операций:
	добавление в начало
	добавление в конец
	добавление в середину
	удаление из начала
	удаление с конца
	удаление из середины
	значение элемента из начала
	значение элемента с конца
	значение элемента из середины
	*/
	system("pause");
	return 0;
}






/*
#include "pch.h"
#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <deque>


int main()
{	//1
	std::stack<std::string> st;
	std::stack<std::string> st1;
	std::stack<std::string> st2;

	char stroka;
	std::cin >> stroka;
	while (stroka != 0)
	{
		if (stroka == '[' || stroka == '(' || stroka == '{' || stroka == ']' || stroka == ')' || stroka == '}')
		{
			if (stroka == '[')
			{
				st.push =()
			}
			if (stroka == '(')
			{

			}
			if (stroka == '{')
			{

			}
		}
	}


	//2
	std::queue<std::string> Class_9;
	std::queue<std::string> Class_10;
	std::queue<std::string> Class_11;

	int input_class;
	std::cin >> input_class;

	while (input_class != 0)
	{

		if (input_class == 9)
		{
			std::string student;
			std::cin >> student;
			Class_9.push(student);
		}

		if (input_class == 10)
		{
			std::string student;
			std::cin >> student;
			Class_10.push(student);
		}

		if (input_class == 11)
		{
			std::string student;
			std::cin >> student;
			Class_11.push(student);
		}

		std::cin >> input_class;

	}

	while (!Class_9.empty())
	{
		std::cout << Class_9.front() << std::endl;
		Class_9.pop();
	}

	while (!Class_10.empty())
	{
		std::cout << Class_10.front() << std::endl;
		Class_10.pop();
	}

	while (!Class_11.empty())
	{
		std::cout << Class_11.front() << std::endl;
		Class_11.pop();
	}

}
*/