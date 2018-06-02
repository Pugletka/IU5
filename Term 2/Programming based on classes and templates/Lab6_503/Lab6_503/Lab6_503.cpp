
#include "stdafx.h"
#include "Lab6_503.h"
#include <iostream>

using namespace std;

void main() {

	system("chcp 1251>0");

	cout << "LAB6_503" << endl << endl;

	///////////////////////////////////////////////////////////////

	cout << "����� 4.3. ��������� ������ ������ ������� ��� ������ ������������ ����������" << endl << endl;

	// ������ ������������� 

	Bas *pObj;
	Type1 t1(10);
	Type2 t2(20);

	// ������� �������� ��������� ��� �1  

	pObj = &t1;
	cout << "t1 = " << t1.Coord << " t2 = " << t2.Coord << endl;

	switch (pObj->ClassType) {
	case 1:

		((Type1 *)pObj)->Move(5); break; 

	case 2:

		((Type2 *)pObj)->Move(5); break;

	};

	cout << "t1 = " << t1.Coord << " t2 = " << t2.Coord << endl;

	// ������� �������� ��������� ��� �2  

	pObj = &t2;

	switch (pObj->ClassType) {
	case 1:

		((Type1 *)pObj)->Move(5); break;

	case 2:

		((Type2 *)pObj)->Move(5); break;

	};

	cout << "t1 = " << t1.Coord << " t2 = " << t2.Coord << endl << endl;

	/////////////////////////////////////////////////////////////

	cout << "����� 4.7. �������� ��������� ������� � �������� ��������" << endl << endl;

	cout << "\t�������� ��������" << endl << endl;

	Abstr *pAbs;

	Deriv1 d1(33);
	Deriv2 d2(44);
	Deriv3 d3(66);

	cout << "������� �������" << endl << endl;

	//////////////////////////////////////////////////////////////

	cout << "����� 4.8. �������� ������ ������� ����� �������" << endl << endl;

	cout << "\t������ ������� ����� ������" << endl << endl;

	d1.print();
	cout << endl;

	d2.print();
	cout << endl;

	d3.print();
	cout << endl << endl;

	///////////////////////////////////////////////////////////////

	cout << "����� 4.9. �������� ������ ������� ����� ��������� �� ������" << endl << endl;

	cout << "\t������ ������� ����� ��������� �� ������" << endl << endl;

	Deriv1 *pd1 = &d1;
	pd1->print();
	cout << endl;

	Deriv2 *pd2 = &d2;
	pd2->print();
	cout << endl;

	Deriv3 *pd3 = &d3;
	pd3->print();
	cout << endl << endl;

	///////////////////////////////////////////////////////////////

	cout << "����� 4.10. �������� ������������ ������ �������" << endl << endl;

	cout << "\t����������� �����" << endl << endl;

	pAbs = &d1;
	pAbs->print();
	cout << endl;

	pAbs = &d2;
	pAbs->print();
	cout << endl;

	pAbs = &d3;
	pAbs->print();
	cout << endl << endl;

	////////////////////////////////////////////////////////////////

	cout << "����� 4.11. �������� ������� ������ ���� CObList" << endl << endl;

	cout << "\t�������� ������� ������" << endl << endl;

	CObList listDer(6);

	cout << "������ listDer ������" << endl << endl;

	////////////////////////////////////////////////////////////////

	cout << "����� 4.12. ��������� �������� � ������ ���� �����" << endl << endl;

	cout << "\t������������ ������" << endl << endl;

	for (size_t i = 0; i < 2; i++) {

		Deriv1 *nowP = new Deriv1(i*100);
		listDer.AddHead(nowP);

	}

	for (size_t i = 0; i < 2; i++) {

		Deriv2 *nowP = new Deriv2(i * 100);
		listDer.AddHead(nowP);

	}

	for (size_t i = 0; i < 2; i++) {

		Deriv3 *nowP = new Deriv3(i * 100);
		listDer.AddHead(nowP);

	}

	cout << "�������� � ���������� �������� � listDer" << endl << endl;

	/////////////////////////////////////////////////////////////////

	cout << "����� 4.13. ���������� ������ �������� � ������� ������������ ������" << endl << endl;

	cout << "\t���������� ������" << endl << endl;

	POSITION pos = listDer.GetHeadPosition();

	while (pos != NULL) {

		((Abstr *)(listDer.GetNext(pos)))->print();
		cout << endl;

	}

	cout << endl;

	/////////////////////////////////////////////////////////////////

	cout << "����� 4.14. ����������� �����������" << endl << endl;

	cout << "\t����������� �����������" << endl << endl;

	pos = listDer.GetHeadPosition();

	while (pos != NULL) {

		delete ((Abstr *)(listDer.GetNext(pos)));
		
		cout << endl;

	}

	/////////////////////////////////////////////////////////////////

	cout << "����� 4.15. ����������� ������" << endl << endl;

	cout << "\t����������� ������" << endl << endl;

	X V101(1,2,3,4); // ������ � ������������ ��������
	cout << "V101.a = " << V101.a << endl;
	cout << "V101.A3::a = " << V101.Y::a << endl;  // ����� ����� Y ����� 
	cout << "V101.B3::a = " << V101.U::a << endl;  // ����� ����� U �����
	cout << "V101.C3::a = " << V101.Z::a << endl;  // ����� ����� Z �����
	cout << "V101.b = " << V101.b << endl;
	cout << "V101.c = " << V101.c << endl;
	cout << "V101.d = " << V101.d << endl << endl;

	/////////////////////////////////////////////////////////////////

	system("pause");

}
