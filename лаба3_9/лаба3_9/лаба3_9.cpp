#include <iostream>
#include <ctime>
using namespace std;

//В созданном списке определить количество и удалить все элементы, находящиеся между минимальным и максимальным элементами.

struct queue {
	int info;
	queue* next, * prev;
};

void create(queue**, queue**, int);
void add(int, queue**, queue**, int);
void view(queue*);
void del(queue**);

int main() {
	setlocale(LC_ALL, "Rus");
	queue* begin, * end, * t, * tem, * p, * temp;
	begin = end = t = tem = p = temp = NULL;
	int n, m, s, c, i, k, max, min, t1, t2 = 0;
	srand((unsigned)time(0));
	while (1) {
		cout << "\n1 - создать список\n2 - добавить элементы\n3 - просмотреть\n4 - Удалить элементы между max и min и расчитать их\n";
		cin >> s;

		switch (s) {
		case 1:
			if (begin != NULL) {
				cout << "Память заполнена, хотите очистить её?\n1 - да, иначе - нет.\n";
				cin >> m;

				if (m == 1)
					del(&begin);
				else break;
			}
			cout << "Введите первый элемент\n";
			cin >> m;

			create(&begin, &end, m);
			break;
		case 2:
			if (begin != NULL) {
				cout << "Выберите режим записи:\n0 - с начала\n1 - с конца\n";
				cin >> c;

				cout << "введите количество элементов\n";
				cin >> n;

				cout << "1 - ввод с клавиатуры, иначе - рандом\n";
				cin >> s;

				if (s != 1)for (int i = 0; i < n; i++) add(c, &begin, &end, rand() % 21 - 10);
				else {
					cout << "введите элементы:";
					for (int i = 0; i < n; i++) {
						cin >> m;

						add(c, &begin, &end, m);
					}
				}
			}
			else cout << "Нет элементов! Создайте список перед добавлением элементов\n";
			break;
		case 3:
			if (begin == NULL)cout << "Нет элементов!\n";
			else {
				cout << "Элементы\n";
				view(begin);
			}
			break;
		case 4:
			if (begin != NULL) {
				max = min = begin->info;
				tem = begin->next;
				t1 = t2 = c = 1;
				while (tem != NULL) {
					c++;
					if (tem->info > max) {
						t1 = c;
						max = tem->info;
					}
					if (tem->info < min) {
						t2 = c;
						min = tem->info;
					}
					tem = tem->next;
				}
				cout << "Max: " << max << "\t#" << t1 << "\nMin: " << min << "\t#" << t2 << endl;
				c = k = i = 0;
				while (begin != NULL) {
					c++;
					if ((t1 > t2 && (c >= t1 || c <= t2)) || (t1 < t2 && (c <= t1 || c >= t2))) {
						if (k == 0) {
							create(&p, &temp, begin->info);
							k++;
						}
						else
							add(0, &p, &temp, begin->info);
					}
					else i++;
					begin = begin->next;
				}
				k = 0;
				while (p != NULL) {
					if (k == 0) {
						create(&begin, &end, p->info);
						k++;
					}
					else
						add(0, &begin, &end, p->info);
					p = p->next;
				}
				cout << "результат\n" << "количество удаленных " << i << endl;
				view(begin);
				break;
			}

			else cout << "Нет элементов!\n";
			break;
		default:
			if (begin != NULL)
				del(&begin);
			return 1;
		}
	}

}

void create(queue** a, queue** b, int in) {
	queue* t = new queue;
	t->info = in; // ИЧ
	t->next = t->prev = NULL; //АЧ (1-ый налл)
	*a = *b = t; //установка на первый элемет
}

void add(int kod, queue** b, queue** e, int in) {
	queue* t = new queue;
	t->info = in;
	if (kod == 0) {
		t->next = *b; //новый элемент связываем с 1-м
		(*b)->prev = t; // изменяем адреса связей
		*b = t; // переставляем указатель
		(*b)->prev = NULL;
	}
	else {
		t->next = NULL;// следующего нет
		t->prev = *e; // новый с последним
		(*e)->next = t;
		*e = t;
	}
}

void view(queue* t) {

	cout << "с начала:\t";
	while (t->next != NULL) {
		cout << t->info << "\t";
		t = t->next;
	}

	cout << t->info << "\nс конца:\t";
	while (t != NULL) {
		cout << t->info << "\t";
		t = t->prev;
	}
	cout << endl;
}

void del(queue** p) {
	queue* t;
	while (*p != NULL) {
		t = *p;
		*p = (*p)->next;
		delete t;
	}
}