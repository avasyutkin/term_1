// Lab_14.4 - структура данных List

#include "pch.h"
#include <iostream>
#include <list>
#include <iterator>


using namespace std;

int main() {
	list <int> mylist;
	list <int> listmerge = { 7, 8, 9 };

	for (int i = 0; i < 2; i++) {
		for (int j = 1; j < 6; j++) {
			mylist.push_back(i); // добавили 10 элементов
		}
	}

	copy(mylist.begin(), mylist.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	mylist.insert(mylist.end(), 6);  // добавили новый элемент

	copy(mylist.begin(), mylist.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	mylist.unique();  // удалили все дубликаты
	list <int> ::iterator it;

	for (it = mylist.begin(); it != mylist.end(); it++) {
		cout << (*it) << " ";
	}

	mylist.merge(listmerge);  // присвоили список 
	for (it = mylist.begin(); it != mylist.end(); it++) {
		cout << (*it) << " ";
	}
	return 0;
}

//Это структура данных, которая построена на двусвязных списках.
//Это значит, что любой элемент знает только о предыдущем и о следующем элементах.
//У двусвязного списка нет индексов.
//Плюсы:
//Добавление и удаление ячеек осуществляется быстро.
//Кроме добавления и удаления в конец, мы также можем добавить и удалить элемент в начале контейнера.
//Минусы :
//Медленное обращение к элементам, находящимся в центре.
//insert
//С помощью его можно добавить новый элемент в любую часть контейнера(в нашем случае для списка).Вот как он работает :
//insert(<позиция>, <значение>);
//Первым аргументом передаем — местоположение.Оно указывается итератором, что это читайте вот здесь.
//Вторым значение новой ячейки.Здесь может быть как переменная так и просто значение(5 например).
//string cpp = "Это легко";
//insert(it, cpp);