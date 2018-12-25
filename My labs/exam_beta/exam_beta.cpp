#include "pch.h"
#include <iostream>


#include "pch.h"
#include<iostream>
#include "String.h" 
#include <string> 

String::String()
{

	std::cin >> strlen; // Вводится длина строки 
	str = new char[strlen]; //Создается строка нужной длины 
	std::cin >> str; //Вводится с клавиатуры строка 

}
String::String(const String& lhs) {
	str = new char[length(lhs.str) + 1]; //вычисляем длину стркои массива в объекте аналогичного класса и создаем строку такой же длины 
	str = lhs.str; //Передаем значение в новую строку 
}

String::String(char* str1) {
	str = new char[length(str1) + 1]; //вычисляем длину стркои массива и создаем строку такой же длины 
	str = str1; //Копируем значения массива в новую строку 
}
int String::length(char*str1) { //Функция для вычисления длины строки char[] 
	int i = 0;
	while (str1[i] != '\0')
	{
		i++;
	}
	return i;
}

char* String::Add(char*str1) {

	char* str2 = new char[length(str) + length(str1) + 1];

	for (int i = 0; i < length(str); i++) {
		str2[i] = str[i];
	}
	for (int i = 0; i <= length(str1); i++) {
		str2[length(str) + i] = str1[i];
	}
	str = str2;

	delete str2;
	return str;

}

char* String::Cut(int num, int qu) {
	if (num + qu <= length(str)) {
		for (int i = num; i < (num + qu); i++) {
			str[i] = ' ';
		}
		for (int i = num; i < (num + qu); i++) {
			str[i] = str[i + qu];
			str[num + qu] = '\0';
		}
		return str;
	}
	else { std::cout << "Number is too big"; }
	return str;
}

char* String::insert(int num, char* sl) {
	if ((num + length(sl)) <= (length(str))) {

		for (int i = num; i < (num + length(sl)); i++)
		{
			str[i] = sl[i - num];
		}
		return str;
	}
	else {
		std::cout << "ERROR";
		return str;
	}
}

void String::clear() {
	char* str1 = new char[1];
	str = str1;
	delete str1;

}
String::~String()
{
}


int main()
{
	char* A1 = new char[15];
	delete A1;
	String A;
	for (int i = 0; i < 10000; i++) {

		A.str = A.Add((char*)"ABCDEFGASDFGHJKLZASDFGHJ");

		A.str = A.insert(15, "ABCD");
		A.clear();
	}
	system("pause");
	return 0;
}




/*class stroks
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

void stroks::clear()
{

}
*/