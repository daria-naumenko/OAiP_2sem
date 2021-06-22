#include <iostream>
#include <cmath>

// корни уравнения  4x-7sin(x) метод итерации

double functionY(double x);
double functionF(double x);
double method(double e, double x_arr);

using namespace std;

int main() {
	setlocale(LC_ALL, "Rus");
	double x, a, b, e, h;
	cout << "Введите a = "; cin >> a;
	cout << "Введите b = "; cin >> b;
	cout << "Введите e = "; cin >> e;
	cout << "Введите h = "; cin >> h;
	x = a;
	while (x < b) {
		cout << "Корни" << endl;
		cout << "x:" << x << " " << "y:" << functionY(x) << endl;
		x = x + h;
	}

	double x_arr, y, solution;

	for (a; a < b; a += h) {
		x_arr = a;
		y = functionY(x_arr);
		if (y * functionY(x_arr + h) < 0) {
			solution = method(e, x_arr);
			cout << "Решение: " << solution << endl;
			cout << "X в диапазоне " << x_arr << " до " << x_arr + h << endl;
			cout << "Y в диапозоне " << solution << " до " << functionY(solution) << endl;
			cout << '\n';
		}
		else {
			cout << "Нет решений в диапазоне " << endl;
			cout << "X от " << x_arr << " до " << x_arr + h << endl;
			cout << "Y от " << y << " до " << functionY(x_arr + h) << endl;
			cout << '\n';
		}
	}
	return 1;
}

double functionY(double x) {
	return 4 * x - 7 * sin(x);
}

double functionF(double x) {
	return 7 * sin(x) / 4; //4x-7sin(x) = y => y = 0 => 4x=7sinx => x = 7sinx/4
}

double method(double e, double x_arr) {
	int it = 0;
	double dif, temp_x;
	for (dif = 1, it; dif > e || it >= 100; it++)
	{
		temp_x = functionF(x_arr);
		if (it == 0 && temp_x < x_arr) {
			return 0;
		}
		dif = fabs(temp_x - x_arr);
		x_arr = temp_x;
	}
	cout << endl;
	cout << "Итерации: " << it << endl;
	return temp_x;
}