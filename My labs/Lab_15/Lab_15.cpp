//Lab_15 - Шаблоны
#include <iostream>

template <typename MyType> //чтобы не писать много функций, можно использовать свой тип. область template - только нижеслудущая функция. 
MyType myFunc(MyType * arr, int size) { //перегрузка функции 
	MyType res = arr[0];
	for (int iter = 0; iter < size; iter++) {
		if (res < arr[iter])
			res = arr[iter];
	}
	return res;
}

/*
double myFunc(double * arr, int size) {
double res = arr[0];
for (int iter = 0; iter < size;iter++) {
if (res < arr[iter])
res = arr[iter];
}
return res;
}


int myFunc(int * arr, int size) {
int res = arr[0];
for (int iter = 0; iter < size; iter++) {
if (res < arr[iter])
res = arr[iter];
}
return res;
}

char myFunc(char * arr, int size) {
char res = arr[0];
for (int iter = 0; iter < size; iter++) {
if (res < arr[iter])
res = arr[iter];
}
return res;
}
*/

template<typename TT>
class myList {
public:
	TT element;
	myList * prev;
	myList * next; //next указывает на NULL, то есть на конeц списка
	myList(); //конструктор 
	myList(TT el); //перегрузка конструктора 

	myList<TT> next_elem() {
		return next;
	}
	void print();
	void push_back(TT new_elem); ;//функция для добаления последнего элемента 
};


int main() {
	/*	int * arrI, sizeI = 5, sizeCh = 5, sizeD = 5;
	char * arrCh;
	double * arrD;

	arrI = new int[sizeI];
	arrCh = new char[sizeCh];
	arrD = new double[sizeD];

	std::cout << "Input arrI";
	for (int it = 0; it < sizeI; it++) {
	std::cin >> arrI[it];
	}
	std::cout << "Input arrCh";
	for (int it = 0; it < sizeCh; it++) {
	std::cin >> arrCh[it];
	}
	std::cout << "Input arrD";
	for (int it = 0; it < sizeD; it++) {
	std::cin >> arrD[it];
	}
	std::cout << "Max element int = " << myFunc(arrI, sizeI);
	std::cout << "Max element char = " << myFunc(arrCh, sizeCh);
	std::cout << "Max element double = " << myFunc(arrD, sizeD);
	*/
	myList<int> li(5);
	li.push_back(4);
	//li.push_back(7);
	li.print();

	getchar();
	return 0;
}

template<typename TT>
myList<TT>::myList()
{
	prev = NULL;
	next = NULL;
}

template<typename TT>
myList<TT>::myList(TT el)
{
	prev = NULL;
	next = NULL;
	element = el;
}

template<typename TT>
void myList<TT>::print()
{
	myList<TT> *temp = new myList<TT>; 
	*temp = *this; 
	while (temp->prev != NULL) { //пока не дошли до конца 
		*temp = *temp->prev;
	}
	while (temp->next != NULL) {
		std::cout << temp->element << "\t";
		*temp = *temp->next;
	}
	std::cout << temp->element << "\t";
}

template<typename TT>
void myList<TT>::push_back(TT new_elem)
{
	myList<TT> *tmp = new myList<TT>;
	myList<TT> *tmp1 = new myList<TT>;
	next = tmp;
	*tmp1 = *this;
	tmp->element = new_elem;
	(tmp->prev) = tmp1;
	tmp->next = NULL;
	this->element = tmp->element;
	this->prev = tmp->prev;
	this->next = NULL;
}