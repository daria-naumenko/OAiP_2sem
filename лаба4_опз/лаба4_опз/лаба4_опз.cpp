#include <iostream>
using namespace std;

//ОПЗ 

struct Stack {
	char c;
	Stack* next;
};

int Prior(char);
Stack* InS(Stack*, char);
Stack* OutS(Stack*, char*);
double Result(char*);

void main() {
	setlocale(LC_ALL, "Rus");
	Stack* t, * Op = NULL;
	char a;
	char In[81], Out[81];
	int k, l = 0, counter = 0;
	cout << "Введите формулу: ";
	cin >> In;
	for (k = 0; In[k] != '\0'; ++k) {
		if (In[k] >= 'a' && In[k] <= 'z')
			Out[l++] = In[k];
		else if (In[k] == '(') { //-если (, записываем ее в стек
			Op = InS(Op, In[k]); counter++;
		}
		else if (In[k] == ')') { //- если ), извлекаем из стека в строку Out все операциии до открывающей скобки
			counter--;
			if (counter < 0) {
				cout << "  ')' записыается после '(' " << endl; system("pause");  return;
			}
			while ((Op->c) != '(') {
				Op = OutS(Op, &a);
				if (!Op)
					a = '\0';
				Out[l++] = a;
			}
			t = Op;
			Op = Op->next;
			delete t;
		}
		else if (In[k] == '+' || In[k] == '-' || In[k] == '*' || In[k] == '/') {
			while (Op != NULL && Prior(Op->c) >= Prior(In[k])) {
				Op = OutS(Op, &a);
				Out[l++] = a; //-записывается в строку Out
			}
			Op = InS(Op, In[k]);
		}
	}
	if (counter != 0) { cout << " Неверное кол-во скобок" << endl; system("pause"); return; }
	while (Op != NULL) {
		Op = OutS(Op, &a);
		Out[l++] = a;
	}
	Out[l] = '\0'; //- окончание строки
	cout << "\n Польская запись= " << Out << endl;
	cout << "Результат= " << Result(Out) << endl;
	system("pause");
}
//----Реализация приоритета операций---—
int Prior(char a) { // поступает какой-то символ
	switch (a) {
	case'*': case'/': return 3;
	case'-': case'+': return 2;
	case'(': return 1;
	}
	return 0;
}
//---Добавлениие элемента в стек------—
Stack* InS(Stack* p, char s)
{
	Stack* t = new Stack;
	t->c = s;
	t->next = p;
	return t;
}
//-----Извлечение элемента из стека----------—
Stack* OutS(Stack* p, char* s)
{
	Stack* t = p;
	*s = p->c; // 
	p = p->next;
	delete t;
	return p;
}
//------Расчет выражения ОПЗ------—
double Result(char* str) {
	int i;    Stack* begin = NULL;
	char ss, ss1, ss2, ssR = 'z' + 1; // ss - т символ,  ss1 и ss2 -с для операнда первого и воторого, ssR-вспомог последовательно получающее 
	double op1, op2, res, mas[50];
	bool written[50];
	cout << "Введите данные" << endl;
	for (i = 0; str[i] != '\0'; ++i) {
		ss = str[i];
		if (ss >= 'a' && ss <= 'z') {
			if (written[int(ss - 'a')] != true) {
				cout << ss << "=";
				cin >> mas[int(ss - 'a')];
				written[int(ss - 'a')] = true;
			}

		}
	}
	for (i = 0; str[i] != '\0'; ++i) {
		ss = str[i];
		if (!(ss == '+' || ss == '-' || ss == '*' || ss == '/' || ss == '^'))
			begin = InS(begin, ss);
		else {
			begin = OutS(begin, &ss2);
			begin = OutS(begin, &ss1);
			op2 = mas[int(ss2 - 'a')];
			op1 = mas[int(ss1 - 'a')];
			switch (ss) {
			case'+': res = op1 + op2; break;
			case'-': res = op1 - op2; break;
			case'*': res = op1 * op2; break;
			case'/': if (op2 == 0) {
				cout << "Делить на 0 нельзя" << endl; system("pause");
				exit(0);
			}
				   else { res = op1 / op2; break; }
			}
			mas[int(ssR - 'a')] = res;
			begin = InS(begin, ssR);
			ssR++;
		}
	}
	return res;
}