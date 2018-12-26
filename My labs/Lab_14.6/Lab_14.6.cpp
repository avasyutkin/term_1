// Lab_14.6 - структура данных map

#include "pch.h"
#include <iostream>
#include <map> //подключили библиотеку для работы с map
using namespace std;

int main()
{
	map <string, string> passport = { { "Donald", "Trump" }, //string - ключ, int - значение
								   { "Vladimir", "Putin" } }; //map явно инициализирована

	passport["maxim"] = "Denisov";     // добавляем
	passport["andrey"] = "Puzerevsky"; // новые
	passport["dima"] = "Tilyupo";      // значения

	cout << "Size: " << passport.size() << endl;

	map <string, string> ::iterator full_name; // создали итератор на passport

	full_name = passport.find("andrey"); // находим ячейку
	passport.erase(full_name);           // удаляем

	cout << "Size: " << passport.size();
}

//В этот контейнер можно помещать сразу два значения. 
//Это ассоциативный контейнер, который работает по принципу — [ключ — значение]. 
//При добавлении нового элемента контейнер будет отсортирован по возрастанию.
//При создании map все его элементы будут иметь значение нуля.