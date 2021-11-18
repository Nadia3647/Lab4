#include "stdafx.h"
#include <conio.h>
#include <locale>
#include <iostream>

using namespace std;

double sumN(double, int, double&);
double sumE(double, double, int&);

int main()
{
	setlocale(LC_ALL, "rus");
	int chek = 1;
	while (chek == 1)
	{
		cout << "Выберите действие (1 - расчёт, 0 - остановка)" << endl;
		cin >> chek;
		switch (chek)
		{
		case(0):
		{
			cout << "Программа завершена" << endl;
			break;
		}
		case(1):
		{
			cout << "Вычисление значений функции cos(x)"<<endl;
			double x; // Значение аргумента
			double func; // Точное значение функции
			double sum; // Значение частичной суммы
			int n; // Число слагаемых в частичной сумме

			cout << "Задание 1" << endl;
			cout << "Введите значение аргумента > ";
			cin >> x;
			cout << "Задайте число слагаемых > ";
			cin >> n;
			func = cos(x);// Вычисление "точного" значения
			double last;
			sum = sumN(x, n, last);
			cout << "Точное значение функции равно " << func << endl;
			cout << "Частичная сумма ряда равна " << sum << endl;
			cout << "Абсолютная погрешность равна " << fabs(func - sum) << endl;
			cout << "Последнее слагаемое равно " << last << endl;

			cout << "Задание 2" << endl;
			double E;
			cout << "Введите значение аргумента > ";
			cin >> x;
			cout << "Задайте точность вычислений > ";
			cin >> E;
			func = cos(x);
			sum = sumE(x, E, n);
			cout << "Точное значение функции равно " << func << endl;
			cout << "Частичная сумма ряда c заданной точностью равна " << sum << endl;
			cout << "Учтено " << n << " членов ряда" << endl;
			sum = sumE(x, E / 10, n);
			cout << "Частичная сумма ряда c точностью, большей в 10 раз, равна " << sum << endl;
			cout << "Учтено " << n << " членов ряда" << endl;
			
			break;

		}

		default:
		{
			cout << "Некорректно введеные данные" << endl;
			chek = 1;
			continue;
		}

		}

	}
	
}

double sumN(double x, int n, double& last) // Вычесление частичной суммы
{	
	last = 1;
	double sum = last;
	for (int i = 0; i < n - 1; ++i)
	{
		double r; // Отношение слагаемлого к предыдущему
	   	r = -x * x / (2 * i + 1) / (2 * i + 2);
		last *= r; // Вычеслние последнего слагаемого 
		sum += last; 
	}
	return sum;
}

double sumE(double x, double E, int& n)
{
	double last;
	last = 1;
	double sum = last;
	for (n = 0; fabs(last) > E; n++)
	{
		double r; 
		r = -x * x / (2 * n + 1) / (2 * n + 2);
		last *= r;
		sum += last;
	}
	return sum;
}
