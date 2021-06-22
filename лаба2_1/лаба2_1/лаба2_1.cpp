#include <iostream>
using namespace std;

//Разделить созданный список на два: в первом – положительные числа, во втором – отрицательные. 

struct stack { //однонапрвленный список
	int inf; //ИЧ
	stack* next; //АЧ next-указатель на след элемент
};

stack* add(stack*, int);
void view(stack*);
void delst(stack*);


void main() {
	int n, number;
	stack* topall = nullptr; // вместо begin (адрес первого элемента)
	stack* topnegative = nullptr; // нулевые указатели topnegative(вместо t )

	cout << "Size of stack:\n";
	cin >> n;

	cout << "Enter numbers:\n";
	for (int i = 0; i < n; i++) {
		cin >> number;
		topall = add(topall, number);
	}

	topall = add(topall, 0);
	stack* temp = topall;
	while (topall->next != nullptr)
	{
		if (topall->next->inf < 0) //  -> косвенная адресаци, topall->inf - ИЧ первого элемента, next - второго
		{
			topnegative = add(topnegative, topall->next->inf); // topnegative - 

			stack* tmp = topall->next;
			topall->next = tmp->next;
			delete(tmp);
		}
		else topall = topall->next;
	}

	topall = temp;
	topall = topall->next;
	delete temp; //освобождение ранее захваченной памяти 

	view(topall);
	view(topnegative);

	delst(topall);
	delst(topnegative);
}

//добавить в стэк элемент
stack* add(stack* top, int info) {
	stack* p = new stack;
	p->next = top; //формируем ИЧ
	p->inf = info; //формируем АЧ
	return p; //возвращаем измененную вершину в которую добавили элемент
}

// просмотерть стэк
void view(stack* top) { // устанавливаем текущий указатель на вершинку
	while (top != NULL) { // выполняем цикл до тех пор, пока текущий указатель top !=0 (т.е. список еще есть)
		cout << top->inf << ' '; //ИЧ выводим на экран
		top = top->next; //переставляем текущий элемент на следующий за ним
	}
	cout << endl; //конец цикла
}

// удалить стэк...... функция типа void тк обнулённую вершину возвращаем в точку вызова по адресу с помощью указателя
void delst(stack* top) {
	stack* temp;
	while (top != NULL) {   // выполняем цикл до тех пор, пока вершина top !=0, закончится цикл когда топ=0
		temp = top; //запоминаем адрес вершины
		top = top->next; //сдвигаем вершину на следующий элемент
		delete temp; //освобождаем память занятую бывшей вершиной
	}     // итак до тех пор пока всё не освободим
	//return p;
}