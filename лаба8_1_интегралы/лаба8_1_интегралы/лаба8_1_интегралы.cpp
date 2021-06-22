#pragma hdrstop
#pragma warning(disable : 4996)
#include <iostream>
#include <math.h>
#include <conio.h>

using namespace std;

double f(double);
double Metod(double (*f)(double), double, double, int);

void main() {

	setlocale(LC_ALL, "Rus");
	double a, b, eps, I1, I2;
	int n, n1, kod;
	cout << "Метод средних, если a=-2, b=3, Интеграл=5,983" << endl;

	do {
		cout << "Введите нижний предел интегрирования : "; cin >> a;
		cout << "Введите верхний предел интегрирования : "; cin >> b;
		cout << " Выберите метод решения : \n\t1 – по заданному количеству разбиений отрезка интегрирования\n\tиначе – по заданной точности\n ";
		cin >> kod;
		if (kod == 1) {
			cout << "Введите количество разбиений: ";
			cin >> n;
			I1 = Metod(f, a, b, n);
		}
		else {
			cout << "Введите точность: ";
			cin >> eps;

			I1 = Metod(f, a, b, n1 = 2);

			do {
				I2 = I1;
				n1 *= 2;
				I1 = Metod(f, a, b, n1);
			} while (fabs(I2 - I1) > eps);
			cout << "\t n=" << n1 / 2 << endl;
		}
		cout << "\n\t Интеграл = " << I1 << endl;
		cout << "\n Повторно - 1, Иначе - Exit " << endl;
	} while (getch() == '1');
}

double f(double x) {
	return 4 * x - 7 * sin(x);
}

double Metod(double (*f)(double x), double a, double b, int n) {

	double s = 0, h, x;
	h = (b - a) / n;
	for (x = a + h / 2; x <= b; x += h) {
		s = s + f(x);
	}
	return h * s;
}