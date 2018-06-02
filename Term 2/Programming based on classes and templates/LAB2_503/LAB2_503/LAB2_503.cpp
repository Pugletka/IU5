
#include "stdafx.h"
#include "LAB2_503.h"

#include <iostream>
#include <fstream>

#include <iomanip>

using namespace std;

extern int iSecond;

ostream & hexbase(ostream & s)
{
	s << hex << showbase;

	return s;
}

ostream & ccc(ostream & s)
{
	s << setw(20) << setfill('!');

	return s;
}

char * Spravka(void);
char * Cat(char *str1, char *str2);

void printRect(Rect *rect);
void getRect(Rect *rect);

ostream & operator<<(ostream & s, Rect rect) {

	printRect(&rect);
	return s;
}

istream & operator>>(istream & s, Rect & rect) {

	getRect(&rect);
	return s;
}

ofstream & operator<<(ofstream & s, Rect rect) {

	s.write((char *)&rect, sizeof(Rect));
	return s;
}

ifstream & operator>>(ifstream & s, Rect & rect) {

	s.read((char *)&rect, sizeof(Rect));
	return s;
}

void main() {

	system(" chcp 1251 > nul");

	cout << "LAB2_503 ��5-23 ���� ������" << endl << endl;

	// ����� 4.3

	cout << "4.3. ��������� �������� ����� � ������ ��� ���������� ����������� �����" << endl << endl;

	int iVal;
	cout << "������� iVal: ";
	cin >> iVal;
	cout << "���� ������� �������� iVal = " << iVal << endl << endl;

	double dVal;
	cout << "������� dVal: ";
	cin >> dVal;
	cout << "���� ������� �������� dVal = " << dVal << endl << endl;

	bool bVal;
	cout << "������� bVal: ";
	cin >> bVal;
	cout << "���� ������� �������� bVal = " << boolalpha << bVal << endl << endl;

	char sMas[100];
	cout << "������� sMas: ";
	cin >> sMas;
	cout << "���� ������� �������� sMas = " << sMas << endl << endl;

	iVal = 5;
	int *pInt = &iVal;
	cout << "*pInt = " << *pInt << endl;
	cout << "������� *pInt: ";
	cin >> *pInt;
	cout << "���� ������� �������� *pInt = " << *pInt << endl << endl;

	// ����� 4.4

	cout << "4.4. ��������� �������� ����� � ������ � ������� ������� get, getline, put, write" << endl << endl;

	char ch;
	cout << "������ � get � put. ������� ������ (����� ����� - '.'):";
	do {

		ch = cin.get();
		cout.put(ch);

	} while (ch != '.');

	cout << endl;

	cout.write("������ � getline � write. ������� ������ (����� ����� - '.'):\n",
		sizeof("������ � getline � write. ������� ������ (����� ����� - '.'):\n") / sizeof(char)-1);

	char str[30];
	cin.getline(str, 30, '.');

	cout << str << endl << endl;

	// ����� 4.5

	cout << "4.5. ������������������ ������������� ������� �������������� ������ � �����" << endl << endl;

	cout << "������� sMas: ";
	cin >> sMas;

	cout.fill('_');
	cout.width(30);
	cout << setw(50) << "���� ������� �������� sMas = " << sMas << endl << endl;

	cout << "������� dVal: ";
	cin >> dVal;

	cout << "���� ������� �������� dVal(dec) = " << dVal << endl;

	cout << "�� precision(2): dVal = " << dVal << endl;
	cout.precision(2);
	cout << "����� precision(2): dVal = " << dVal << endl << endl;

	// ����� 4.6

	cout << "4.6. ������������������ ������������� ������������� ��� ��������� ��������" << endl << endl;

	cout << "������� iVal: ";
	cin >> iVal;
	cout << "���� ������� �������� iVal = " << iVal << endl << endl;
	cout.unsetf(ios_base::dec);

	cout.setf(ios_base::hex);
	cout << "hex iVal = " << iVal << endl;
	cout.unsetf(ios_base::hex);

	cout.setf(ios_base::dec);
	cout << "dec iVal = " << iVal << endl;
	cout.unsetf(ios_base::dec);

	cout.setf(ios_base::oct);
	cout << "oct iVal = " << iVal << endl << endl;
	cout.unsetf(ios_base::oct);

	cout << "setbase(16) ival = " << setbase(16) << iVal << endl;
	cout << "setbase(10) ival = " << setbase(10) << iVal << endl;
	cout << "setbase(8) ival = " << setbase(8) << iVal << endl << endl;

	cout << "��� iVal hex - " << setbase(16) << showbase << iVal << endl;
	cout << "��� iVal oct - " << setbase(8) << showbase << iVal << endl;
	cout << "��� iVal dec - " << setbase(10) << showbase << iVal << endl << endl;

	cout << "������� dVal: ";
	cin >> dVal;
	cout << "���� ������� �������� dVal = " << dVal << " = " << scientific << dVal << endl << endl;

	// ����� 4.7

	cout << "4.7. ������������������ ������������� ����������������� ������������" << endl << endl;

	cout << "iVal = " << hexbase << iVal << endl << endl;

	// ����� 4.8

	cout << "4.8. ������������������ ����� ������� � ������� ����� � ������ � ��������" << endl << endl;

	cout << Spravka() << endl << endl;

	cout << dec << "iSecond = " << iSecond << endl << endl;

	char str1[10] = "12345";
	char str2[5] = "6789";

	cout << "Cat(\"12345\", \"6789\") = " << Cat(str1, str2) << endl << endl;

	// ����� 4.9

	cout << "4.9. ����� � ����� �������� ���������������� ������� � ����������� �������" << endl << endl;

	Rect rect = Rect();

	printRect(&rect);
	cout << endl;

	getRect(&rect);

	cout << endl;
	printRect(&rect);
	cout << endl;

	// ����� 4.10

	cout << "4.10. ������ � ������� � ������� ���������� ����� � ������" << endl << endl;

	cout << "\t�������� ������ �����" << endl << endl;

	int rectsSize = 3;

	Rect *rects = new Rect[rectsSize];
	rects[0] = Rect(1, 2, 10, 10);
	rects[1] = Rect(2, 3, 10, 10);
	rects[2] = Rect(3, 4, 10, 10);

	ofstream out("Var_G03.bin", ios::out | ios::binary);
	
	if (!out.fail()) {
		out.write((char *)rects, sizeof(Rect) * rectsSize);
	}

	out.close();

	delete[]rects;

	cout << "���� Var_G03.bin ������" << endl << endl;

	cout << "\t������ � ���������� �����" << endl << endl;

	rects = new Rect[rectsSize];

	ifstream in("Var_G03.bin", ios::in | ios::binary);

	if (!in.fail()) {
		in.read((char *)rects, sizeof(Rect) * rectsSize);
	}

	in.close();

	for (int i = 0; i < rectsSize; i++)
	{
		printRect(&rects[i]);
	}

	cout << endl;

	delete[]rects;
	
	cout << "\t��������� � ���������� �����" << endl << endl;
	
	fstream file;

	Rect additionalRect = Rect(666, 666, 10, 10);

	file.open("Var_G03.bin", ios::out | ios::app | ios::binary);
	
	if (!file.fail())
	{
		file.write((char *)&additionalRect, sizeof(Rect));
		rectsSize++;
	}

	file.close();

	file.clear();

	rects = new Rect[rectsSize];

	file.open("Var_G03.bin", ios::binary | ios::in);

	if (!file.fail())
	{
		file.read((char *)rects, sizeof(Rect)* rectsSize);
	}

	file.close();

	for (int i = 0; i < rectsSize; i++)
	{
		printRect(&rects[i]);
	}
	cout << endl;

	delete[]rects;

	cout << "\t������ ������ �� ������" << endl << endl;

	Rect readRect;
	int numberOfRect = 2;

	in.open("Var_G03.bin", ios::in | ios::binary);

	if (!in.fail()) {
		in.seekg(sizeof(Rect) * (numberOfRect - 1), ios::beg);
		in.read((char *)&readRect, sizeof(Rect));
	}

	in.close();

	printRect(&readRect);
	cout << endl;

	cout << "\t�������� ������ �����" << endl << endl;

	rects = new Rect[rectsSize];

	in.open("Var_G03.bin", ios::in | ios::binary);

	if (!in.fail()) {
		in.read((char *)rects, sizeof(Rect)* rectsSize);
	}

	in.close();

	out.open("LR2.bin", ios::out | ios::binary | ios::trunc);

	int newRectsSize = 0;

	if (!out.fail()) {

		for (int i = 0; i < rectsSize; i++) {

			if (i % 2 == 0) {
				out.write((char *)&rects[i], sizeof(Rect));
				newRectsSize++;
			}

		}

		cout << "���� LR2.bin ������" << endl << endl;
	}

	out.close();

	Rect *newRects = new Rect[newRectsSize];

	in.open("LR2.bin", ios::binary | ios::in);

	if (!in.fail()) {
		in.read((char *)newRects, sizeof(Rect)* newRectsSize);
	}

	in.close();

	for (int i = 0; i < newRectsSize; i++) {
		printRect(&newRects[i]);
	}

	cout << endl;

	delete[]rects;
	delete[]newRects;

	// ����� 4.11

	cout << "4.11. ����������� � �������� ������� ����� � ������" << endl << endl;

	ifstream inbuf("LR2.bin", ios::binary | ios::in); // �������� � �������� �����
	cout << hex << endl << inbuf.rdbuf() << endl; // ����� ����� �����

	// �������������� ���������� ��� ������� ���������

	cout << "�������������� ���������� ��� ������� ���������" << endl << endl;

	cout << "\t���������� << � >>" << endl << endl;

	Rect rect12 = Rect();
	cin >> rect12;
	cout << rect12;


	system("pause");
}

void writeRectsFromArray(Rect *rects, int count) {
	
	ofstream file;

	file.open("Var_G03.bin", ios::out | ios::binary);
	file.write((char *)rects, sizeof(Rect) * count);
	file.close();

}

void readRectsToArray(Rect *rects, int count) {

	ifstream file;

	file.open("Var_G03.bin", ios::in | ios::binary);
	file.read((char *)rects, sizeof(Rect) * count);
	file.close();

}