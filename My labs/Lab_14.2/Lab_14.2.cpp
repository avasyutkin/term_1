//Lab_14.2 - Cортировка учеников по классам через очередь
#include "pch.h"
#include <iostream>
#include <string>
#include <queue> //подключили библиотеку для использования очереди


int main()
{
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

/*	ОЧЕРЕДЬ — это структура данных, которая построена по принципу
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