#include <iostream>
#include <math.h>
using namespace std;

double f(double x) {
	return x * x * x - 5 * x * x;
}
double N(double* x, double* y, double xt, int m) {
	int i, k;
	double* D = new double[m], N, p; //динамческий метод
	for (i = 0; i < m; i++) {
		D[i] = y[i];
	}
	p = 1;
	N = y[0];
	for (k = 0; k < m - 1; k++) {
		for (i = 0; i < m - k; i++) {
			D[i] = (D[i] - D[i + 1]) / (x[i] - x[i + k + 1]);
		}
		p = p * (xt - x[k]);
		N += p * D[0];
	}
	delete[]D;
	return N;
}
double pogr(double x, double N) {
	return (f(x) - N);
}

int main() {
	setlocale(LC_ALL, "rus");
	double a, b, h, h1, x, * m_x, m_y_t, * m_y, max, p = 0;
	int i, n, m;
	cout << " условие: a=-2, b=5, m=5." << endl;
	cout << "введите начало отрезка: "; cin >> a;
	cout << "введите конец отрезка: "; cin >> b;
	cout << "введите количество известных узлов: "; cin >> m;
	cout << "введите количество точек в которых нужно восстановить значение: "; cin >> n;
	h = (b - a) / (m - 1);
	h1 = (b - a) / (n - 1);
	m_y = new double[m + 1];
	m_x = new double[m + 1];

	for (x = a, i = 0; i < m; i++) {
		m_x[i] = x;
		m_y[i] = f(x);
		x += h;
	}
	max = p;
	for (x = a, i = 0; i < n; i++, x += h1) {
		m_y_t = N(m_x, m_y, x, m);
		cout << "xt= " << x << " f*(x)= " << m_y_t;
		p = abs(f(x) - m_y_t);
		cout << "\tпогрешность: " << p << endl;
		if (p > max) max = p;
	}
	cout << " мах погрешность = " << max << endl;
}
