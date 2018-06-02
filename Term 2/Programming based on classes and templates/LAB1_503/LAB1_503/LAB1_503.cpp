
#include "stdafx.h"

#include "LAB1_503.h"
#include <iostream>
#include <string>

#define AVR(a, b, c) ((a) + (b) + (c)) / 3

typedef int* PInt;
typedef int& RInt;

using namespace std;

void main()
{
	system(" chcp 1251 > nul");

	cout << "LAB1_503" << endl << endl;

	// ����� 4.4

	cout << "4.4. ��������� �������� ���������� � ��������." << endl << endl;

	// ����������
	/*
		������� � ���������������� ���������� ��������� ����������� ����� � ������������������ ������������ ��
		�������� ��������������� �����. ����: int (iVar), long (lVar), char (cVar), float (fVar), double (dVar), bool (bVar).
		��������� ������ ����� ������������� � ������ ������������ (�� cout ). 
	*/

	cout << "\t����������" << endl << endl;

	int iVar = 5;
	long lVar = 5000; 
	char cVar = 'F';
	float fVar = 12.5;
	double dVar = 12.25;
	bool bVar = true;

	cout << "iVar = " <<  iVar << endl;
	cout << "lVar = " <<  lVar << endl;
	cout << "cVar = " <<  cVar << endl;
	cout << "fVar = " <<  fVar << endl;
	cout << "dVar = " <<  dVar << endl;
	cout << "bVar = " << boolalpha <<  bVar << endl << endl;

	iVar = 6;
	lVar = 5001; 
	cVar = 'U';
	fVar = 13.5;
	dVar = 13.25;
	bVar = false;

	cout << "iVar = " <<  iVar << endl;
	cout << "lVar = " <<  lVar << endl;
	cout << "cVar = " <<  cVar << endl;
	cout << "fVar = " <<  fVar << endl;
	cout << "dVar = " <<  dVar << endl;
	cout << "bVar = " << boolalpha <<  bVar << endl << endl;

	// �������
	/*
		������� ������� ��������� ����������� ����� � ������������������ ������������ �� �������� ��������������� �����
		(�������� ������� � ������� �������� �������� �� ������ ������). ����: int (iMas), long (lMas), char (cMas), 
		float (fMas), dounle (dMas), bool (bMas). �������  iMas � fMas ������������������� ��� ��������. ������ iMas ����� ���
		�����������. ��������������������� ������� ���������� ����������� � �����.
	*/

	cout << "\t�������" << endl << endl;

	int iMas[3][3] = {{1, 2, 3},
					  {4, 5, 6},
					  {7, 8, 9}};
	long lMas[3];
	char cMas[3];
	float fMas[3] = {1.2f, 3.4f, 5.6f};
	double dMas[3];
	bool bMas[3];

	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) {
			cout << "iMas[" << i << "]" << "[" << j << "] = " << iMas[i][j] << endl; // i � ������ �������� � �������
		}
	}

	cout << endl;

	for(int i = 0; i < 3; i++) {
		cout << "fMas[" << i << "] = " << fMas[i]  << endl; // i � ������ �������� � ������� 
	}

	cout << endl;

	fMas[1] = 0;

	for(int i = 0; i < 3; i++) {
		cout << "fMas[" << i << "] = " << fMas[i]  << endl; // i � ������ �������� � ������� 
	}

	cout << endl;

	// ����� 4.5

	cout << "4.5. ������������������ ������������� ���������� � ������." << endl << endl;

	// ��������� �� ����������
	/*
		��������� �������� ��������� (pInt). ��������� ��������� ����� ���������� ���� int (iVar) �
		������ � ������� ��������� �������� (��������, 5). ����������� ��������  �� ��������� � �������� ������ ���������
		(�����). �������� �������� � ������� ��������� (�� 10) � ����� �����������.  
	*/
	
	cout << "\t��������� �� ����������" << endl << endl;

	int *pInt = &iVar;
	*pInt = 5;

	cout << "*pInt = " << *pInt << endl;
	cout << "pInt = " << pInt << endl << endl;

	*pInt = 10;

	cout << "*pInt = " << *pInt << endl;
	cout << "pInt = " << pInt << endl << endl;

	// ������ �� ����������
	/*
		��������� �������� ������ (rInt). ��������� ������ �����  ���������� ���� int (iVar) � ������ �
		������� ������ ����� �������� (��������, 15). ����������� �������� ������ � ����� ������ (&rInt). �������� �������� ��
		������ (��������, 15) � ����������� � ������� ������ (rInt) � ���������(pInt).
	*/

	cout << "\t������ �� ����������" << endl << endl;

	int & rInt = iVar;
	rInt = 15;

	cout << "rInt = " << rInt << endl;
	cout << "&rInt = " << &rInt << endl << endl;

	rInt = 20;

	cout << "rInt = " << rInt << endl;
	cout << "*pInt = " << *pInt << endl << endl;

	// ��������� �� �������
	/*
		�������������� ������� ��� ������� ������� (fun1 � fun2), ������������ ������ ������������� 
		�������� (int) � ������� ���� ������������� �������� (int). ������� ��������� �� ������� (pFun) c �������� ����������.
		������������������ ������������� ����� ��������� ��� ������ �������, ���������� ��������� � ������� ������� �� ���������.
	*/

	cout << "\t��������� �� �������" << endl << endl;

	int (*pFun)(int param);

	pFun = &fun1;
	cout << "pFun = " << pFun(iVar) << endl;

	pFun = &fun2;
	cout << "pFun = " << pFun(iVar) << endl << endl;

	// ����� 4.6

	cout << "4.6. ������������������ ������������� �������� ������." << endl << endl;

	// ������������� ��������
	/*
		������� ��������� ������, ���������� �� ����� 4-� �����, � ������������ � ���������� ��� ������
		������ (Street). ������ ��������� ������ ���� ������ � ������������ ������������ ����� (LAB1_XDD.H). �����������������
		������������� ��������� ��� ������� ����������� ����������. ������� � ������������������ ������ ����������� ����������
		������� ����. 
	*/

	cout << "\t������������� ��������" << endl << endl;

	Street street1 = {"TestStreet", 20, 1234.567f, true};

	Street streetArray[2] = {{"TestStreet1", 20, 1234.567f, true},
							 {"TestStreet2", 20, 1234.567f, true}};

	cout << "street1 = {" << street1.title << ", " << street1.housesCount << ", " << street1.averagePayment << ", " << boolalpha << street1.danger << "}" << endl << endl;

	// ���������� ��������
	/*
		������� �������������������� ����������� ����������. ����������������� ���������� �������� ����
		����� ������� ����������� ����������, ������������ ����������� ���������� �� � ����� ���������. ���������� � cout.
	*/

	cout << "\t���������� ��������" << endl << endl;

	Street street2;
	
	strcpy_s(street2.title, "TestStreet");
	street2.averagePayment = 1234.567f;
	street2.danger = true;
	street2.housesCount = 20;

	cout << "street2 = {" << street2.title << ", " << street2.housesCount << ", " << street2.averagePayment << ", " << boolalpha << street2.danger << "}" << endl;

	strcpy_s(street2.title, "ChangedTestStreet");
	street2.averagePayment = 4321.567f;
	street2.danger = false;
	street2.housesCount = 50;

	cout << "street2 = {" << street2.title << ", " << street2.housesCount << ", " << street2.averagePayment << ", " << boolalpha << street2.danger << "}" << endl << endl;

	// ������ ��������
	/*
		������� � ��������� ��� ������������� ������ �������� �� ������ �������� (�� ����� 5-�� ���������
		�������). ������������ � ����� ���� ������ �������� (����������� �������� ����� - while � ������� sizeof() � ���
		����������� ������� ������� � ��������� �����������).
	*/

	cout << "\t������ ��������" << endl << endl;

	Street streets[5] = {{"TestStreet1", 10, 1234.567f, true},
						 {"TestStreet2", 20, 1234.567f, false},
						 {"TestStreet3", 30, 1234.567f, true},
						 {"TestStreet4", 40, 1234.567f, false},
						 {"TestStreet5", 50, 1234.567f, true}};

	int i = 0;
	while (i < sizeof(streets) / sizeof(Street))
	{
		cout << "street = {" << streets[i].title << ", " << streets[i].housesCount << ", " << streets[i].averagePayment << ", " << boolalpha << streets[i].danger << "}" << endl;
		i++;
	}

	cout << endl;

	// ����� 4.7

	cout << "4.7. ������������ ������ ��� ����������� ���������� � ������� ��������." << endl << endl;

	// ����������
	/*
		������� ��������� �� ������� ���������� ���� int (pdInt). �������� ������������ ������ ��� ���������� (new).
		��������� (������������� -*) ������������ ���������� �������� (25) � ������������ ������ � ������� ���������. ����������
		������������ ������ (delete). 
	*/
	
	cout << "\t����������" << endl << endl;

	int *pdInt = new int;
	*pdInt = 25;

	cout << "*pdInt = " << *pdInt << endl;
	cout << "pdInt = " << pdInt << endl << endl;

	delete pdInt;

	// ����������� ����������
	/*
		������� ��������� �� ����������� ���������� ������ ���� (pdStr) � �������� ��������. �������� ������������ ������ ���
		����������� ���������� (new). ��������� (->) ����� ������������ ����������� ���������� �������� � ������������ � �����
		���� � ������������ ������ � ������� ���������. ���������� ������������ ������ ��� ��������� (delete). 
	*/
	
	cout << "\t����������� ����������" << endl << endl;

	Street *pdStr = new Street;
	
	strcpy_s(pdStr->title, "WTF");
	pdStr->housesCount = 3;
	pdStr->danger = true;
	pdStr->averagePayment = 123.123f;

	cout << "*pdStr = {" << pdStr->title << ", " << pdStr->housesCount << ", " << pdStr->averagePayment << ", " << boolalpha << pdStr->danger << "}" << endl;
	cout << "pdStr = " << pdStr << endl << endl;

	delete pdStr;

	// ������ ����������� ����������
	/*
		�������� ������������ ������ ��� ������ ����������� ���������� ������ ���� (pdStr) � �������� ��������. ���������
		������ ���� �� ����� 3-� (����� �� ������������ �������, ���������� ����). ��������� ���� ��������� �����������
		���������� ������������� ���������� (������� ��� � �����). ����������� ������������ ������ ����������� ����������.
		���������� ������������ ������ ��� ����������� ������ (delete). 
	*/
	
	cout << "\t������ ����������� ����������" << endl << endl;

	Street *pdStrArray = new Street[3];

	for(int i = 0; i < 3; i++) {
		pdStrArray[i] = streets[i];
		cout << "*pdStr = {" << pdStrArray[i].title << ", " << pdStrArray[i].housesCount << ", " << pdStrArray[i].averagePayment << ", " << boolalpha << pdStrArray[i].danger << "}" << endl;
	}

	delete[] pdStrArray;

	cout << endl;

	// ����� 4.8

	cout << "4.8 ������������� ������ � ���������� ���������." << endl << endl;

	// ���������� ������������� ������� �����
	/*
		������� ������������ ������ ����� ���������� ���� int (��������� - pMas). ������ ������� �� ����� 5-�� ���������.
		��������� ������ ������������� (�������) ���  ���������� (������� - rand) ����������. ��������� ����������� ����������
		�� �������� (����������� ��� ��������). ������������ �������� ����� for. ��������� �� � ����� ���������� �����������.
		���������� ������������ ������ ��� ������ (delete).  
	*/
	
	cout << "\t���������� ������������� ������� �����" << endl << endl;

	int *pMas = new int[5];

	cout << "{"; 
	for (int i = 0; i < 5; i++)
	{
		pMas[i] = rand(); // & 10;
		cout << pMas[i] << ", ";
	}
	cout << "\b}" << endl; 

	for (int i = 0; i < 5; i++)
    {
        for (int j = 5 - 1; j > i; j--)
        {
            if (pMas[j] < pMas[j - 1])
            {
                swap(pMas[j], pMas[j - 1]);
            }
        }
    }

	cout << "{"; 
	for (int i = 0; i < 5; i++)
	{
		cout << pMas[i] << ", ";
	}
	cout << "\b}" << endl << endl; 

	delete[] pMas;

	// ����� 4.9

	cout << "4.9. ������������������ ������ ������� ������� � ������� �� �� ������� ������." << endl << endl;

	/*
		���������� ������ � ������. ��� ������������ ������ ��������� ������� � ������ ������ �������� � ������� ������
		�������� ���� (SECOND.CPP). ��� ����� � ������ �������, �� ������� �Source Files� �������� ����������� ����, � ���
		�������� ����� �Add� - > �New Item�. �������� ������ �C++ File�, � ���� �Name� ������ ��� ����� - SECOND. � ������ ����
		��������� �������� ������������ ������ � ���������� std:

		������� �������. � ����� ����� ������� ������� �� �������� (�����, ������������, ��������, �������, �������). ����������
		������� - ���������� �������� ��� ������������� ������� (��. ����� �������� fMas), ������������ � �������� ���������� 
		� �������. ������ ������� ����� ���������� � �������� ���������. �������� ������� ������� ��������������. �� ��������
		������� �������� ������� � �������� �����. ����������� ������ ����� ���������� � �������. ��� ���������� �����
		������������ �������� �����, ������������ � �������� ������ (for, do ��� while). ����� ������ ������� �����������
		���������� �� ������ � ����������� ����� cout.

		������� ����������. ������� � ������������������ ������������� ������� ��� ���������� ������� �������� (SortMas �
		������ SECOND.CPP). ��� ���������� �������� ���������� ������� (�������� ��� �����������). ����������� � ����� ��������
		������ � ������ ����� ����������. ��� ������� �������� ���������. 
	*/
	
	cout << "\t������� �������" << endl << endl;

	double ddMas[] = {22, 1, 34.5};
	double minVar = findMin(ddMas, 3);

	cout << endl;

	cout << "\t������� ����������" << endl << endl;

	i = 0;
	while (i < sizeof(streets) / sizeof(Street))
	{
		cout << "street = {" << streets[i].title << ", " << streets[i].housesCount << ", " << streets[i].averagePayment << ", " << boolalpha << streets[i].danger << "}" << endl;
		i++;
	}

	cout << endl;

	sortMas(streets, sizeof(streets) / sizeof(Street), false);

	i = 0;
	while (i < sizeof(streets) / sizeof(Street))
	{
		cout << "street = {" << streets[i].title << ", " << streets[i].housesCount << ", " << streets[i].averagePayment << ", " << boolalpha << streets[i].danger << "}" << endl;
		i++;
	}

	cout << endl;

	// ����� 4.10

	cout << "4.10. ������ � ������� �� ������ ������� ��������" << endl << endl;

	// �������� �����
	/*
		������� ���������� �����. ������� ��������� ���� � ������ �Var_GXX.bin�. ���: G � ����� ������, � XX � ������� ��
		������� ������. ������������ �������: fopen, fwrite � fclose. ������ � ���� ��������� �� ������ ������� �����������
		����������, ������������ ����� (�.4.6) ��� ���������� ������.  ������� ����.  
	*/
	
	cout << "\t�������� �����" << endl << endl;

	int streetArrSize = 2;

	Street *streetArr = new Street[streetArrSize]; 

	Street s1 = {"A", 1, 1.5, true};
	Street s2 = {"B", 2, 2.5, false};

	streetArr[0] = s1;
	streetArr[1] = s2;

	FILE *pFile;

	fopen_s(&pFile, "Var_303.bin", "w+");
	fwriteStreetsFromArray(streetArr, streetArrSize, pFile);
	fclose(pFile);

	cout << "���� Var_303.bin ������" << endl << endl;

	// ������ � ���������� �����
	/*
		������� �������������� ����� ���� ��� ������. ������������ �������: fopen, fread � fclose. ��������� � ����� ���������
		������ ����� (� ������������� �����) � �� �����������. ������� ����.  
	*/

	cout << "\t������ � ���������� �����" << endl << endl;
	
	fopen_s(&pFile, "Var_303.bin", "r+b");
	freadStreetsToArray(streetArr, streetArrSize, pFile);
	fclose(pFile);

	for (int i = 0; i < 2; i++) {

		cout << "street" << i << " = {" << streetArr[i].title << ", " << streetArr[i].housesCount << ", " << streetArr[i].averagePayment << ", " << boolalpha << streetArr[i].danger << "}" << endl;
	}

	delete[] streetArr;

	cout << endl;

	// ��������� �����
	/*
		������� ����� ��� ���� ��� ������ � �����������. ������� � ������������������� ����� ����������� ���������� ������
		����. �������� ��� ������ � ����� �����. ������������ �������: fopen, fwrite � fclose. ������� ����. ������� ����������
		���� ��� ������. ��������� ���� � �����������. ������� ����.
	*/

	cout << "\t��������� �����" << endl << endl;

	fopen_s(&pFile, "Var_303.bin", "a+b");
	
	fseek(pFile, 0, SEEK_END);

	Street addStreet = { "C", 3, 3.5, true };

	fwrite(&addStreet, sizeof(Street), 1, pFile);

	streetArrSize++;

	streetArr = new Street[streetArrSize];

	fclose(pFile);

	fopen_s(&pFile, "Var_303.bin", "r+b");
	freadStreetsToArray(streetArr, streetArrSize, pFile);
	fclose(pFile);

	for (int i = 0; i < streetArrSize; i++) {

		cout << "street" << i << " = {" << streetArr[i].title << ", " << streetArr[i].housesCount << ", " << streetArr[i].averagePayment << ", " << boolalpha << streetArr[i].danger << "}" << endl;
	}

	cout << endl;

	// ������ ������ �� ������
	/*
		������� ���� ���� ��� ������. ��������� ������ �� ������  �� ����� (����� � ��. �������). �������, ��� ������ � �����
		������������� � 1-��. ������������ �������: fopen, fseek,  fread � fclose. ����������� ���������� ������. �������
		���� ����. 
	*/
	
	cout << "\t������ ������ �� ������" << endl << endl;

	int numberOfStreet = 3;

	fopen_s(&pFile, "Var_303.bin", "r+b");

	Street street;
	freadStreetByNumber(&street, 2, pFile);

	fclose(pFile);

	cout << "street" << " = {" << street.title << ", " << street.housesCount << ", " << street.averagePayment << ", " << boolalpha << street.danger << "}" << endl << endl;

	// �������� ������ �����
	/*
		������� ����� ���� (LR1.BIN) �� ������ ������� � ������ ������� �������� (0, 2, �) �� �������. ������������ �������:
		fopen, fwrite, fread � fclose. ������� ��� �����. ������� ����� ���� (LR1.BIN) ��� ������ � ��� �����������.
		������� ����. ������������������ ������������� ���������� ������ � ������� ���� � ���������� (Far ��� Total Commander).. 
	*/
	
	cout << "\t�������� ������ �����" << endl << endl;

	FILE *pFile2;

	fopen_s(&pFile2, "LR1.bin", "w+");
	fopen_s(&pFile, "Var_303.bin", "r+b");

	freadStreetsToArray(streetArr, streetArrSize, pFile);

	int streetArr2Size = 0;

	for (int i = 0; i < streetArrSize; i++) {

		if (i % 2 == 0)
		{
			fseek(pFile2, 0, SEEK_END);
			fwrite(&streetArr[i], sizeof(Street), 1, pFile2);
		
			streetArr2Size++;
		}
	}

	fclose(pFile);
	fclose(pFile2);

	cout << "����� ���� LR1.bin ������" << endl << endl;

	Street *streetArr2 = new Street[streetArr2Size];

	fopen_s(&pFile2, "LR1.bin", "r+b");
	freadStreetsToArray(streetArr2, streetArr2Size, pFile2);
	fclose(pFile);

	for (int i = 0; i < streetArr2Size; i++) {

		cout << "street" << i << " = {" << streetArr2[i].title << ", " << streetArr2[i].housesCount << ", " << streetArr2[i].averagePayment << ", " << boolalpha << streetArr2[i].danger << "}" << endl;
	}

	cout << endl;

	delete[] streetArr;
	delete[] streetArr2;

	// �������������� ���������� ��� ������� ���������

	cout << "�������������� ���������� ��� ������� ���������" << endl << endl;

	// ������������� ��������� typedef
	/*
	������������������ ������������� ��������� typedef ��� ������ � ����������.
	*/

	cout << "\t������������� ��������� typedef" << endl << endl;

	int intVar = 13;
	PInt pointerToInt = &intVar;
	RInt referenceToInt = intVar;

	cout << "PInt pointerToInt = " << pointerToInt << endl;
	cout << "RInt referenceToInt = " << referenceToInt << endl << endl;

	// ������������� switch
	/*
	������������������ ������������� ��������� �������������� ��������� � �������������(switch).
	*/

	cout << "\t������������� switch" << endl << endl;

	switch (intVar)
	{
	case 13:
		cout << "switch (intVar) == 13" << endl << endl;
	default:
		break;
	}

	// ������������� ��������
	/*
	������������������ ������������� ��������(#define), �������� ��������.
	*/

	cout << "\t������������� ��������" << endl << endl;

	cout << "AVR(1, 2, 3) = " << AVR(1, 2, 3) << endl << endl;

	// ��������� ������ �� ������
	/*
	�������� ��������� ��������� ������ �� ������ � �������� �������.
	*/

	cout << "\t��������� ������ �� ������" << endl << endl;

	fopen_s(&pFile, "Var_303.bin", "r+b");
	fprintStreets(pFile, 3);
	fclose(pFile);

	Street street555 = {"555", 12, 12.5, true};
	
	fopen_s(&pFile, "Var_303.bin", "r+b");

	frewriteStreetByNumber(street555, 2, 3, pFile);
	fclose(pFile);

	fopen_s(&pFile, "Var_303.bin", "r+b");
	fprintStreets(pFile, 3);

	fclose(pFile);

	cout << "\t�������� ������ �� ������" << endl << endl;

	fopen_s(&pFile, "Var_303.bin", "r+b");
	fprintStreets(pFile, 3);
	fclose(pFile);

	fopen_s(&pFile, "Var_303.bin", "r+b");
	fremoveStreetByNumber(1, 3, pFile);
	fclose(pFile);

	fopen_s(&pFile, "Var_303.bin", "r+b");
	fprintStreets(pFile, 2);
	fclose(pFile);

	// ������ � ������� � ���� �������
	/*
	�������� ��������� ������ ��������� ������� � ������� � ���� �������(������ � ������, ���������� �����, ������ �� ������� � ����, ������ ������ �� ������).
	*/

	cout << "\t������ � ������� � ���� �������" << endl << endl;

	cout << "������� ������ ����� � ������ ������������ � ���������� �������" << endl << endl;

	fopen_s(&pFile, "Var_303.bin", "r+b");
	cout << "������ �����" << endl << endl;
	fprintStreets(pFile, 3);
	fclose(pFile);

	cout << "������� ������ �� ������� � ���� ������������ � ���������� �������" << endl << endl;

	fopen_s(&pFile, "Var_303.bin", "r+b");
	Street street666 = {};
	freadStreetByNumber(&street666, 2, pFile);
	fclose(pFile);
	cout << "������ ������ �� ������" << endl << endl;
	cout << "street1 = {" << street666.title << ", "
		<< street666.housesCount << ", " << street666.averagePayment << ", "
		<< boolalpha << street666.danger << "}" << endl << endl;

	// ������������� string
	/*
	������������������ ������������� ���� string �� ���������� STL.�� �������� ���������� ���������� ����� ������������ ���������� : #include <string>
	*/

	cout << "\t������������� string" << endl << endl;

	string str = "This is string object";

	cout << "string str = " << str << endl << endl;

	system(" PAUSE");
}

int fun1(int param) {

	return param * 2;
}

int fun2(int param) {

	return param / 2;
}

int freadStreetsToArray(Street *streetsArray, int streetsArraySize, FILE *file) {

	fseek(file, 0, SEEK_SET);

	int error = fread((char *)streetsArray, sizeof(Street), streetsArraySize, file);

	return error;
}

int freadStreetByNumber(Street *street, int number, FILE *file) {

	fseek(file, (number -1) * sizeof(Street), SEEK_SET);

	int error = fread((char *)street, sizeof(Street), 1, file);

	return error;
}

int fwriteStreetsFromArray(Street *streetsArray, int streetsArraySize, FILE *file) {

	fseek(file, 0, SEEK_SET);

	int error = fwrite((char *)streetsArray, sizeof(Street), streetsArraySize, file);

	return error;
}

int frewriteStreetByNumber(Street street, int number, int streetsCount, FILE *file) {

	Street *streets = new Street[streetsCount];

	int error = freadStreetsToArray(streets, streetsCount, file);

	streets[number - 1] = street;

	error = fwriteStreetsFromArray(streets, streetsCount, file);

	delete[] streets;

	return error;
}

int fprintStreets(FILE *file, int numberOfStreets) {

	Street *streets = new Street[numberOfStreets];

	int error = freadStreetsToArray(streets, numberOfStreets, file);

	for (int i = 0; i < numberOfStreets; i++) {

		cout << "street" << i << " = {" << streets[i].title << ", "
			 << streets[i].housesCount << ", " << streets[i].averagePayment << ", "
			 << boolalpha << streets[i].danger << "}" << endl;
	}

	cout << endl;

	delete[] streets;

	return error;
}

int fremoveStreetByNumber(int number, int numberOfStreets, FILE *file) {

	Street *streets = new Street[numberOfStreets];

	int error = freadStreetsToArray(streets, numberOfStreets, file);

	Street *newStreets = new Street[numberOfStreets-1];

	int j = 0;

	for (int i = 0; i < numberOfStreets; i++) {
		if (i != (number - 1)) {

			newStreets[j] = streets[i];

			j++;
		}
	}

	error = fwriteStreetsFromArray(newStreets, numberOfStreets-1, file);

	delete[] streets;
	delete[] newStreets;

	return error;
}