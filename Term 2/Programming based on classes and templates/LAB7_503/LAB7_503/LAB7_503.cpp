// LAB7_503.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include "LAB7_503.h"
#include <iostream>

using namespace std;

void vPrint(vector<int>& v) {
	
	int i;
	for( i = 0; (unsigned) i < v.size( ) ; i++) {
		cout << "v[" << i << "] = " << v[i] << endl;
	}
}

void vIterPrint(vector<int>& v) {
	
	vector<int>::iterator iter;
	for(iter = v.begin(); iter != v.end(); iter++) {
		cout << "v[] = " << *iter << endl;
	}
}

void vIterPrint(vector<Complex>& v) {
	
	vector<Complex>::iterator iter;
	for(iter = v.begin(); iter != v.end(); iter++) {
		cout << "complexVector[] = "<< *iter << endl;
	}
}


void main() {

	system("chcp 1251>0");

	cout << "LAB7_503" << endl << endl;

	///////////////////////////////////////////////////////////////

	cout << "����� 4.4. ��������� �������� ������� vector ���� int/long" << endl << endl;
	cout << "\t�������� �������" << endl << endl;

	vector <int> intVector;

	/////////////////////////////////////////////////////////////////

	cout << "����� 4.5. ��������� ���������� ������� - ������" << endl << endl;
	cout << "\t���������� �������" << endl << endl;

	for (int i = 0; i < 5; i++) {

		intVector.push_back(i);
		cout << "intVector["<< i << "] = "<< intVector[i] << endl;
	
	}

	cout << endl;

	/////////////////////////////////////////////////////////////////

	cout << "����� 4.6. ������� ���� ������� ���������� �������� ���� int/long" << endl << endl;
	cout << "\t������� ������ �������" << endl << endl;

	vPrint(intVector);
	cout << endl;

	/////////////////////////////////////////////////////////////////

	cout << "����� 4.7. ������������� ��������� ��� ��������" << endl << endl;
	cout << "\t��������" << endl << endl;

	vector<int>::iterator iter; // ���������� ���������

	cout << "������ � ������� ���������:" << endl;
	for(iter = intVector.begin(); iter != intVector.end(); iter++) {
		cout << "v[] = " << *iter << endl;
	}
	cout << endl;

	/////////////////////////////////////////////////////////////////

	cout << "����� 4.8. ������� ������� ���������� �������� ���� int/long � ����������" << endl << endl;
	cout << "\t������� � ����������" << endl << endl;

	vIterPrint(intVector);
	cout << endl;

	/////////////////////////////////////////////////////////////////

	cout << "����� 4.9. ��������� ���������� ��������� � ������ �� ������" << endl << endl;
	cout << "\t���������� � ������" << endl << endl;

	intVector.insert(intVector.begin() + 2, 100);
	vIterPrint(intVector);

	cout << endl;

	/////////////////////////////////////////////////////////////////

	cout << "����� 4.10. ��������� �������� ��������� �� ������� �� ������" << endl << endl;
	cout << "\t�������� �� �������" << endl << endl;

	intVector.erase(intVector.begin()); 
	vIterPrint(intVector);

	cout << endl;

	/////////////////////////////////////////////////////////////////

	cout << "����� 4.11. ��������� ������� ������� � �������� ������� �������" << endl << endl;
	cout << "\t������� �������" << endl << endl;

	if (!intVector.empty()) {

		intVector.clear();

	}

	if (intVector.empty()) {

		cout << "������ ������" << endl << endl;

	}

	/////////////////////////////////////////////////////////////////

	cout << "����� 4.12. ��������� �������� ������� ��� ������ ������" << endl << endl;
	cout << "\t������ ������ �������" << endl << endl;

	vector <Complex> complexVector;

	for (int i = 0; i < 5; i++) {

		complexVector.push_back(Complex(i, 5-i, 5));
		cout << "complexVector["<< i << "] = "<< complexVector[i] << endl;
	
	}
	
	cout << endl;

	/////////////////////////////////////////////////////////////////

	cout << "����� 4.13. ��������� ������ ������ vector ��� ������������ ������" << endl << endl;
	cout << "\t������ � ��������" << endl << endl;

	complexVector.insert(complexVector.begin() + 2, Complex(11, 22, 6));

	for (int i = 0; i < 6; i++) {

		cout << "complexVector["<< i << "] = "<< complexVector[i] << endl;
	
	}

	cout << endl;

	/////////////////////////////////////////////////////////////////

	cout << "����� 4.14. ������� ������� ���������� �������� ������ ������ � ����������" << endl << endl;
	cout << "\t������� � ����������" << endl << endl;

	vIterPrint(complexVector);
	cout << endl;

	/////////////////////////////////////////////////////////////////

	cout << "����� 4.15.��������� �������� ������ MFC �� �������� ��� ������ ������" << endl << endl;
	cout << "\t�������� MFC" << endl << endl;

	ABArray myArray;

	cout << "����� ABArray ������" << endl << endl;

	/////////////////////////////////////////////////////////////////

	cout << "����� 4.16.��������� ���������� ������� ��� ������ ������" << endl << endl;
	cout << "\t���������� �������" << endl << endl;

	for (int i = 0; i < 5; i++) {

		myArray.Add(Complex(i, (i, 5-i), 5));

	}

	cout << myArray;
	cout << endl;

	/////////////////////////////////////////////////////////////////

	cout << "����� 4.17.��������� ����������� � �������" << endl << endl;
	cout << "\t������ � ��������. " << endl << endl;

	cout << myArray.GetAt(3) << endl << endl;

	myArray.SetAt(3, Complex(100, 200, 5));
	cout << myArray.GetAt(3) << endl << endl;

	myArray.InsertAt(3, Complex(100, 200, 5));
	cout << myArray;
	cout << endl;

	myArray.RemoveAt(3);
	cout << myArray;
	cout << endl;

	//myArray.RemoveAll();

	ABArray myArray2;
	myArray2.Add(Complex(0, 0, 0));
	myArray2.Append(myArray);

	cout << myArray2;
	cout << endl;

	system("pause");

}
