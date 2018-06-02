#include "stdafx.h"
#include "LAB4_503.h"

#include <iostream>

using namespace std;

#define RAZM 5
#define swap(type, a, b) {type t; t = a; a = b; b = t;}
#define cmp(a, b) (a >= b)

typedef SuperEllipse<int> TypeDefEllips; 

void main()
{
	system("chcp 1251 > nul");
	cout << "LAB4_503" << endl << endl;

	// ����� 4.3. ������������ � ���������� ����� ����������
	cout << "����� 4.3. ������������ � ���������� ����� ����������" << endl << endl;

	int intArray[RAZM] = { 1, 2, 3, 4, 5 };
	int sum = 0;

	for (size_t i = 0; i < RAZM; i++) {
		sum += intArray[i];
	}

	cout << "��������� ������������ = " << sum << endl;

	int a = 13;
	int b = 666;

	cout << "a = " << a << ", b = " << b << " -> swap -> ";
	swap(int, a, b);
	cout << "a = " << a << ", b = " << b << endl;

	cout << "cmp(a, b) = " << boolalpha << cmp(a, b) << endl;
	cout << "cmp(b, a) = " << boolalpha << cmp(b, a) << endl << endl;

	// ����� 4.4. ������� ������� Swap 
	cout << "����� 4.4. ������� ������� Swap" << endl << endl;

	cout << "����� ��� (���������):" << endl;
	cout << "�� Swap: x = " << a << " y = " << b << endl;
	swapPointers(&a, &b);
	cout << "����� Swap: x = " << a << " y = " << b << endl;

	double x = 10.4;
	double y = 4.10;

	cout << "������������ ��� (���������):" << endl;
	cout << "�� Swap: x = " << x << " y = " << y << endl;
	swapPointers(&x, &y);
	cout << "����� Swap: x = " << x << " y = " << y << endl;

	cout << "����� ��� (������):" << endl;
	cout << "�� Swap: x = " << a << " y = " << b << endl;
	swapLinks(a, b);
	cout << "����� Swap: x = " << a << " y = " << b << endl;

	cout << "������������ ��� (������):" << endl;
	cout << "�� Swap: x = " << x << " y = " << y << endl;
	swapLinks(x, y);
	cout << "����� Swap: x = " << x << " y = " << y << endl << endl;

	// ����� 4.5. ������ ������� � ����������� ����������� (�����)  
	cout << "����� 4.5. ������ ������� � ����������� ����������� (�����)" << endl << endl;

	int intArr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	cout << "����� int = " << total<int, sizeof(intArr)/sizeof(int)>(intArr) << endl;
	float floatArr[] = {1.1f, 2.2f, 3.3f, 4.4f, 5.5f, 6.6f, 7.7f, 8.8f, 9.9f};
	cout << "����� float = " << total<float, sizeof(floatArr)/sizeof(float)>(floatArr) << endl;
	double doubleArr[] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9};
	cout << "����� double = " << total<double, sizeof(doubleArr)/sizeof(double)>(doubleArr) << endl << endl;

	// ����� 4.6. ������������� ������� ������� (�.�.) 
	cout << "����� 4.6. ������������� ������� ������� (�.�.)" << endl << endl;

	char ch = 'a';
	swapPointers(&ch, &ch);
	cout << endl;

	// ����� 4.7. ������ ������ � ����������� �������� � ����� ���������� 
	cout << "����� 4.7. ������ ������ � ����������� �������� � ����� ����������" << endl << endl;

	SuperEllipse<int> intEllipse = SuperEllipse<int>(1, 2, 3, 4);
	cout << "������ int (������ ���� ��������):" << endl;
	intEllipse.print();
	cout << endl;

	SuperEllipse<float> floatEllipse = SuperEllipse<float>(1.1f, 2.2f, 3, 4);
	cout << "������ float (������ ���� ��������):" << endl;
	intEllipse.print();
	cout << endl;

	SuperEllipse<double> doubleEllipse = SuperEllipse<double>(1.1, 2.2, 3, 4);
	cout << "������ double (������ ���� ��������):" << endl;
	intEllipse.print();
	cout << endl;

	// ����� 4.8. ������ ������ � ����������� �������� � ����� �����������
	cout << "����� 4.8. ������ ������ � ����������� �������� � ����� �����������" << endl << endl;

	DoubleSuperEllipse<int, 5> sEllipse  = DoubleSuperEllipse<int, 5>(1, 2, 4);
	cout << "������ int (������ ��� ���������):" << endl;
	sEllipse.print();
	cout << endl;

	// ����� 4.9. ������ ������ � �������� �������� � ����� �����������
	cout << "����� 4.9. ������ ������ � �������� �������� � ����� �����������" << endl << endl;

	DoubleSuperEllipse<long, 5> dEllipse  = DoubleSuperEllipse<long, 5>(10, 20, 4);
	cout << "������ long (������ ��� ���������):" << endl;
	dEllipse.print();
	cout << endl;

	// ����� 4.10. �������� ������ ������ �� ������ ������� ������ 
	cout << "����� 4.10. �������� ������ ������ �� ������ ������� ������" << endl << endl;

	FixedDoubleSuperEllipse fixedEllipse = FixedDoubleSuperEllipse(10, 20, 666, 4);
	cout << "������ long � ��������� ���������:" << endl;
	fixedEllipse.print();
	cout << endl;

	// ����� 4.11. �������� ������ ������� ������ �� ������ ������� ������
	cout << "����� 4.11. �������� ������ ������� ������ �� ������ ������� ������" << endl << endl;

	LinedSuperEllipse<int> linedEllipse1 = LinedSuperEllipse<int>(10, 20, 12, 45, 4);
	cout << "������ int (������):" << endl;
	linedEllipse1.print();
	cout << endl;

	LinedSuperEllipse<float> linedEllipse2 = LinedSuperEllipse<float>(10.3f, 2.0f, 12, 45, 4);
	cout << "������ float (������):" << endl;
	linedEllipse2.print();
	cout << endl;

	// ����� 4.12. �������� ������ ������� ������ �� ������ ������� ������
	cout << "����� 4.12. �������� ������ ������� ������ �� ������ ������� ������" << endl << endl;

	TypeDefEllips typedefEllipse = TypeDefEllips(1, 2, 3, 4);
	cout << "������ int (typedef):" << endl;
	typedefEllipse.print();
	cout << endl;

	system("PAUSE");
}

template <class T> 
void swapPointers(T *a, T *b)
{
	if (a == b) {

		cout << "���������� ������!" << endl;

	} else {

		T  Temp = *a;
		*a = *b;
		*b = Temp;

	}
};

template <class T> 
void swapLinks(T & a, T & b)
{
	T  Temp = a;
	a = b;
	b = Temp;
}

template <class T, int size>  
T total(T *arr) {

	T result = 0;

	for(int i = 0; i < size; i++) {
		result += arr[i];
	}

	return result;
}

template <class T, int fill>
void DoubleSuperEllipse<T, fill>::fastMove(int dx, int dy) {

	SuperEllipse::x = dx;
	SuperEllipse::y = dy;
}
