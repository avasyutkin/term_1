//Lab_14 - проверка скобок с помощью стека

#include "pch.h"
#include <iostream>
#include <string>
#include <stack> // подключаем библиотеку для использования стека

bool ArePair(char opening, char closing)
{
	if (opening == '(' && closing == ')') return true;
	else if (opening == '{' && closing == '}') return true;
	else if (opening == '[' && closing == ']') return true;
	return false;
}
bool AreParanthesesBalanced(std::string exp)
{
	std::stack<char>  S;
	for (int i = 0; i < exp.length(); i++)
	{
		if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
			S.push(exp[i]);
		else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
		{
			if (S.empty() || !ArePair(S.top(), exp[i]))
				return false;
			else
				S.pop();
		}
	}
	return S.empty() ? true : false;
}

int main()
{
	setlocale(LC_ALL, "rus");

	/*Code to test the function AreParanthesesBalanced*/
	std::string expression;
	std::cout << "Enter an expression:  "; 
	std::cin >> expression;
	if (AreParanthesesBalanced(expression))
		std::cout << "Balanced\n";
	else
		std::cout << "Not Balanced\n";

	system("pause");
	return 0;
}
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

//В ВЕКТОРЕ ЛЕГКО НАХОДИТЬ ЭЛЕМЕНТЫ
//В ЛИСТЕ ЛЕГКО УДАЛЯТЬ И ВСТАВЛЯТЬ НОВЫЕ ЭЛЕМЕНТЫ
