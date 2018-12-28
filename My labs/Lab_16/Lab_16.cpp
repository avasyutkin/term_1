﻿//Lab_16 - Деревья

#include "pch.h"
#include <iostream>

//Наша структура
struct node //представляет одно звено нашего будущего дерева
{
	int info; //Информационное поле
	node *l, *r; //Левая и Правая часть дерева
};

node *tree = NULL; //Объявляем переменную, тип которой структура Дерево

/*ФУНКЦИЯ ЗАПИСИ ЭЛЕМЕНТА В БИНАРНОЕ ДЕРЕВО*/
void push(int a, node **t)
{
	if ((*t) == NULL) //Если дерева не существует
	{
		(*t) = new node; //Выделяем память
		(*t)->info = a; //Кладем в выделенное место аргумент a
		(*t)->l = (*t)->r = NULL; //Очищаем память для следующего роста
		return; //Заложили семечко, выходим
	}
	//Дерево есть
	if (a > (*t)->info) push(a, &(*t)->r); //Если аргумент а больше чем текущий элемент, кладем его вправо
	else push(a, &(*t)->l); //Иначе кладем его влево
}

/*ФУНКЦИЯ ОТОБРАЖЕНИЯ ДЕРЕВА НА ЭКРАНЕ*/
void print(node *t, int u)
{
	if (t == NULL) return; //Если дерево пустое, то отображать нечего, выходим
	else //Иначе
	{
		print(t->l, ++u); //С помощью рекурсивного посещаем левое поддерево
		for (int i = 0; i < u; ++i) std::cout << "|";
		std::cout << t->info << std::endl; //И показываем элемент
		u--;
	}
	print(t->r, ++u); //С помощью рекурсии посещаем правое поддерево
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int n; //Количество элементов
	int s; //Число, передаваемое в дерево
	std::cout << "введите количество элементов  ";
	std::cin >> n; //Вводим количество элементов

	for (int i = 0; i < n; ++i)
	{
		std::cout << "ведите число  ";
		std::cin >> s; //Считываем элемент за элементом

		push(s, &tree); //И каждый кладем в дерево
	}
	std::cout << "ваше дерево\n";
	print(tree, 0);
	std::cin.ignore().get();
}


/*
Бинарное дерево — это упорядоченное дерево, каждая вершина которого имеет не более двух поддеревьев,
причём для каждого узла выполняется правило: 
в левом поддереве содержатся только ключи, имеющие значения, меньшие, чем значение данного узла,
а в правом поддереве содержатся только ключи, имеющие значения, большие,чем значение данного узла.
Реализация дерева

Узел дерева можно описать как структуру:
struct tnode {
  int field;           // поле данных
  struct tnode *left;  // левый потомок
  struct tnode *right; // правый потомок
};
При этом обход дерева в префиксной форме будет иметь вид

void treeprint(tnode *tree) {
  if (tree!=NULL) { //Пока не встретится пустой узел
	cout << tree->field; //Отображаем корень дерева
	treeprint(tree->left); //Рекурсивная функция для левого поддерева
	treeprint(tree->right); //Рекурсивная функция для правого поддерева
  }
}
Обход дерева в инфиксной форме будет иметь вид

void treeprint(tnode *tree) {
  if (tree!=NULL) { //Пока не встретится пустой узел
	treeprint(tree->left); //Рекурсивная функция для левого поддерева
	cout << tree->field; //Отображаем корень дерева
	treeprint(tree->right); //Рекурсивная функция для правого поддерева
  }
}
Обход дерева в постфиксной форме будет иметь вид

void treeprint(tnode *tree) {
  if (tree!=NULL) { //Пока не встретится пустой узел
	treeprint(tree->left); //Рекурсивная функция для левого поддерева
	treeprint(tree->right); //Рекурсивная функция для правого поддерева
	cout << tree->field; //Отображаем корень дерева
  }
}
*/