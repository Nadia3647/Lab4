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
		cout << "�������� �������� (1 - ������, 0 - ���������)" << endl;
		cin >> chek;
		switch (chek)
		{
		case(0):
		{
			cout << "��������� ���������" << endl;
			break;
		}
		case(1):
		{
			cout << "���������� �������� ������� cos(x)"<<endl;
			double x; // �������� ���������
			double func; // ������ �������� �������
			double sum; // �������� ��������� �����
			int n; // ����� ��������� � ��������� �����

			cout << "������� 1" << endl;
			cout << "������� �������� ��������� > ";
			cin >> x;
			cout << "������� ����� ��������� > ";
			cin >> n;
			func = cos(x);// ���������� "�������" ��������
			double last;
			sum = sumN(x, n, last);
			cout << "������ �������� ������� ����� " << func << endl;
			cout << "��������� ����� ���� ����� " << sum << endl;
			cout << "���������� ����������� ����� " << fabs(func - sum) << endl;
			cout << "��������� ��������� ����� " << last << endl;

			cout << "������� 2" << endl;
			double E;
			cout << "������� �������� ��������� > ";
			cin >> x;
			cout << "������� �������� ���������� > ";
			cin >> E;
			func = cos(x);
			sum = sumE(x, E, n);
			cout << "������ �������� ������� ����� " << func << endl;
			cout << "��������� ����� ���� c �������� ��������� ����� " << sum << endl;
			cout << "������ " << n << " ������ ����" << endl;
			sum = sumE(x, E / 10, n);
			cout << "��������� ����� ���� c ���������, ������� � 10 ���, ����� " << sum << endl;
			cout << "������ " << n << " ������ ����" << endl;
			
			break;

		}

		default:
		{
			cout << "����������� �������� ������" << endl;
			chek = 1;
			continue;
		}

		}

	}
	
}

double sumN(double x, int n, double& last) // ���������� ��������� �����
{	
	last = 1;
	double sum = last;
	for (int i = 0; i < n - 1; ++i)
	{
		double r; // ��������� ����������� � �����������
	   	r = -x * x / (2 * i + 1) / (2 * i + 2);
		last *= r; // ��������� ���������� ���������� 
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
