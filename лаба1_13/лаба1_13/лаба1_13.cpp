#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <math.h>

//Вычислить   y = x^n   если

using namespace std;
double fun_rec(double, int);
double fun(double, int);
void main()
{
	setlocale(LC_ALL, "Rus");
	double x, y;
	int n;
	cout << "Введите x, n: ";
	cin >> x >> n;
	if (n % 2 == 0)
		cout << "n чётное, значит y=(x^(n/2))^2" << endl;
	else
		cout << "n нечётное, значит y=x*x^(n-1)" << endl;

	cout << "\t Рекурсивная функция: y= " << fun_rec(x, n) << endl;

	cout << "\t Обычная функция: y= " << fun(x, n) << endl;
}
double fun(double x, int n)
{
	double y;
	if (n == 1) y = x;
	if (n % 2 == 0) {
		y = pow(x, n);
	}
	else {
		y = x * pow(x, n - 1);
	}
	return y;
}
double fun_rec(double x, int n)
{
	if (n == 1)
		return x;
	if (n % 2 == 0)
	{
		return fun_rec(x, n / 2.) * fun_rec(x, n / 2.);
	}
	else {
		return x * fun_rec(x, n - 1);
	}
}
