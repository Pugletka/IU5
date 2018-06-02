// ������� ��5 ���� ����� �.�.�������
// �������� ������� (2 �������)
// ������� ����������� ����
// ������ ����� (��5-23)

#include "stdafx.h" 
#include <iostream>
#include <fstream>
#include <vector>
#include "HWLibrary.h"

using namespace std;

void printTasks();

void task1();
void task2();
void task3(Catalog *mainCatalog);
void task4();
void task5(Catalog *mainCatalog);
void task6();
void task7(Catalog *mainCatalog);
void task8();
void task9(Catalog *mainCatalog, vector<Catalog *> *catalogsArray);
void task10(Catalog *mainCatalog, vector<Catalog *> *catalogsArray);
void task11();
void task12(vector<Catalog *> *catalogsArray);
void task13(Catalog *mainCatalog, vector<Catalog *> *catalogsArray);
void task14(Catalog *mainCatalog, vector<Catalog *> *catalogsArray);
void task15(vector<Catalog *> *catalogsArray);
void task16(Catalog *mainCatalog, vector<Catalog *> *catalogsArray);
void task17();
void task18(Catalog *mainCatalog, vector<Catalog *> *catalogsArray);

void main() {

	system("chcp 1251>0");

	/*
	Article article1 = Article("����� �����", "� ��������� ����� ����� ������ �����", Sport, 1, 6);

	Catalog catalog1 = Catalog("C�����");
	catalog1.addArticle(&article1);
	catalog1.addArticle(&article1);

	Article article2 = Article("������", "� ��������� ����� ����� ������", Sport, 2, 5);

	Catalog catalog2 = Catalog("�����");
	catalog2.addArticle(&article2);
	catalog2.addArticle(&article2);
	
	Catalog catalog = Catalog();
		
	catalog = catalog1 + catalog2;

	catalog.print();

	cout << endl;

	catalog.writeToFile();

	Catalog newCatalog = Catalog();

	char *fileName = new char[strlen(catalog.name) + 5];
	strcpy_s(fileName, strlen(catalog.name) + 1, catalog.name);
	strcat_s(fileName, strlen(catalog.name) + 5, ".BIN");

	newCatalog.readFromFile(fileName);
	*/

	cout << "�������� �������. ������ ���� (��5-23)." << endl;

	Catalog *pMainCatalog = new Catalog();
	pMainCatalog->loadFormFile();

	vector<Catalog *> catalogsArray;

	while (true) {

		cin.clear();
		while (cin.get() != '\n');
		cout << endl;

		printTasks();

		cout << endl << "������� ����� ���������: ";
		
		int taskNumber;
		cin >> taskNumber;

		switch (taskNumber) {
		
		case 1:
			task1();
			break;

		case 2:
			task2();
			break;

		case 3:
			task3(pMainCatalog);
			break;

		case 4:
			task4();
			break;

		case 5:
			task5(pMainCatalog);
			break;

		case 6:
			task6();
			break;

		case 7:
			task7(pMainCatalog);
			break;

		case 8:
			task8();
			break;

		case 9:
			task9(pMainCatalog, &catalogsArray);
			break;

		case 10:
			task10(pMainCatalog, &catalogsArray);
			break;

		case 11:
			task11();
			break;

		case 12:
			task12(&catalogsArray);
			break;

		case 13:
			task13(pMainCatalog, &catalogsArray);
			break;

		case 14:
			task14(pMainCatalog, &catalogsArray);
			break;

		case 15:
			task15(&catalogsArray);
			break;

		case 16:
			task16(pMainCatalog, &catalogsArray);
			break;

		case 17:
			task17();
			break;

		case 18:
			task18(pMainCatalog, &catalogsArray);
			break;

		case 0:
			delete pMainCatalog;
			return;

		default:
			break;

		}

		system("Pause");

	}

}

void printTasks() {

	cout << "5.1. ���������� � �������������� ���������������" << endl << endl;

	cout << "5.1.1. �������� ������������ �������� ��� ��������� ����������, � ������� ����� ����������� ������ ����� ��������." << endl;
	cout << "5.1.2. �������� �������� ��� ������ ��������, � ����������� � ��� ����������." << endl;
	cout << "5.1.3. �������� �������� ��� ������ �������� �� ������ ������." << endl;
	cout << "5.1.4. ���� ��������� ������� ������: ���������� �����, ����� ����, ���������, ��������, ���������." << endl;
	cout << "5.1.5. ������� � ��������� ������������� ������." << endl;
	cout << "5.1.6. ����������� �������� ������������ ��� ������." << endl;
	cout << "5.1.7. ���������� ������������� ������." << endl;
	cout << "5.1.8. ���� ��������� ������� ��������: ��������, ���������� ������ � ��������, ������� ������� ��� ���." << endl;
	cout << "5.1.9. ���������� ���������� �������� � ��� �������." << endl;
	cout << "5.1.10. ������� ������������� ��������." << endl;
	cout << "5.1.11. ��������� ������������� ��������." << endl;
	cout << "5.1.12. �������� ���� ���������." << endl;
	cout << "5.1.13. ���������� ������ � �������." << endl;
	cout << "5.1.14. �������� ������ �� ��������." << endl;
	cout << "5.1.15. ��������� � ������ ������� '��������' � ��������." << endl;
	cout << "5.1.16. �������������� �������� �������� �� �������� ����������� ���������." << endl;
	cout << "5.1.17. ���������� ��������� ������������ ��� ��������." << endl;
	cout << "5.1.18. ���������� ������ �� ��������� ��� ���������� ����." << endl << endl;

	cout << "5.1.0. �����." << endl;

}

void task1() {

	Article article = Article();
	cout << endl << "������ ������ ������ ������." << endl << endl;

}

void task2() {

	cout << endl;

	// ������ ����� �� ������

	cin.clear();
	while (cin.get() != '\n');

	// ������� ������

	Article article = Article();
	cin >> article;

	article.saveToFile();

	cout << endl << "������ ������� � ��������� � ��."<< endl << endl;

}

void task3(Catalog *mainCatalog) {

	cout << endl;

	cout << "�������� ������ �� ������ ������ ������:" << endl << endl;

	mainCatalog->print();

	cout << endl;
	cout << "������� ����� ������: ";

	int number;
	cin >> number;

	Article *pArticle = new Article();
	pArticle = mainCatalog->getArticle(number);

	cout << endl << "����� ������ \"" << pArticle->title << "\" ������� �� ������ ������ �� ��������� �������� �� ������� " << number << "." << endl;

}

void task4() {

	cout << endl << "� ��������� ������ ��������� �������� ������ : ���������� �����, ����� ����, ���������, ��������, ���������." << endl << endl;

}

void task5(Catalog *mainCatalog) {

	cout << endl << "�������� ������:" << endl << endl;

	mainCatalog->print();

	cout << endl;
	cout << "������� ����� ������: ";

	int number;
	cin >> number;
	cout << endl;

	Article *pArticle = new Article();
	pArticle = mainCatalog->getArticle(number);
	
	pArticle->print();
	cout << endl << endl;

	cin.clear();
	while (cin.get() != '\n');

	cin >> *pArticle;

	cout << endl << "������ ��������." << endl << endl;

}

void task6() {

	cout << endl << "�������� ������������ ��� ������ ����������. ��� ������������ �������������� ������� 3." << endl;

}

void task7(Catalog *mainCatalog) {

	cout << endl << "�������� ������:" << endl << endl;

	mainCatalog->print();

	cout << endl;
	cout << "������� ����� ������: ";

	int number;
	cin >> number;
	cout << endl;

	Article *pArticle = new Article();
	pArticle = mainCatalog->getArticle(number);

	pArticle->print();
	cout << endl << endl;

}

void task8() {

	cout << endl << "� ��������� ������ ��������� �������� ��������: ��������, ���������� ������ � ��������, ������� ������� ��� ���." << endl << endl;

}

void task9(Catalog *mainCatalog, vector<Catalog *> *catalogsArray) {

	cout << endl << "�������� �������: " << endl << endl;

	cout << "\t0) " << mainCatalog->name << endl;
	for (int i = 0; i < (int)catalogsArray->size(); i++) {

		cout << "\t" << i+1 << ") " << (*catalogsArray)[i]->name << endl;

	}

	cout << endl << "������� �����: ";

	int number;
	cin >> number;
	
	cout << endl;
	if (number == 0) {

		mainCatalog->print();

	} else {

		(*catalogsArray)[number-1]->print();

	}
	cout << endl;

}

void task10(Catalog *mainCatalog, vector<Catalog *> *catalogsArray) {

	cout << endl << "�������� ��������: " << endl << endl;
	cout << "1) ������� �������" << endl;
	cout << "2) �������� �������" << endl << endl;
	cout << "������� ����� ��������: ";

	int action;
	cin >> action;

	cout << endl;

	cin.clear();
	while (cin.get() != '\n');

	if (action == 1) {

		Catalog *newCatalog = new Catalog();
		cin >> *newCatalog;

		catalogsArray->insert(catalogsArray->end(), newCatalog);

		cout << endl << "������� ������" << endl << endl;

	} else {

		cout << "�������� �������: " << endl << endl;

		for (int i = 0; i < (int)catalogsArray->size(); i++) {

			cout << "\t" << i << ") " << (*catalogsArray)[i]->name << endl;

		}

		cout << endl << "������� �����: ";

		int number;
		cin >> number;

		cout << endl;

		cin.clear();
		while (cin.get() != '\n');

		cin >> *(*catalogsArray)[number];

		cout << endl << "������� ������" << endl << endl;

	}

}

void task11() {

	cout << endl << "��� ������������ �������������� ������� 9" << endl << endl;

}

void task12(vector<Catalog *> *catalogsArray) {

	cout << "�������� �������: " << endl << endl;

	for (int i = 0; i < (int)catalogsArray->size(); i++) {

		cout << "\t" << i << ") " << (*catalogsArray)[i]->name << endl;

	}

	cout << endl << "������� ����� 1 ��������: ";

	int number1;
	cin >> number1;

	cout << "������� ����� 2 ��������: ";

	int number2;
	cin >> number2;

	Catalog *newCatalog = new Catalog();

	*newCatalog = *(*catalogsArray)[number1] + *(*catalogsArray)[number2];
	catalogsArray->insert(catalogsArray->end(), newCatalog);

	cout << "����� ������� ������ �� ������ ����� ������" << endl << endl;

	newCatalog->print();
	cout << endl;

}

void task13(Catalog *mainCatalog, vector<Catalog *> *catalogsArray) {

	cout << "�������� �������: " << endl << endl;

	for (int i = 0; i < (int)catalogsArray->size(); i++) {

		cout << "\t" << i << ") " << (*catalogsArray)[i]->name << endl;

	}

	cout << endl << "������� �����: ";

	int catalogNumber;
	cin >> catalogNumber;

	cout << endl << "�������� ������ ��� ����������: " << endl << endl;
	mainCatalog->print();

	cout << endl << "������� �����: ";

	int number;
	cin >> number;

	cout << endl;

	(*catalogsArray)[catalogNumber]->addArticle(mainCatalog->getArticle(number));

	cout << "������ \"" << mainCatalog->getArticle(number)->title << "\" ��������� � ������� \"" << (*catalogsArray)[catalogNumber]->name << "\"" << endl << endl;

}

void task14(Catalog *mainCatalog, vector<Catalog *> *catalogsArray) {

	cout << "�������� �������: " << endl << endl;

	for (int i = 0; i < (int)catalogsArray->size(); i++) {

		cout << "\t" << i << ") " << (*catalogsArray)[i]->name << endl;

	}

	cout << endl << "������� �����: ";

	int catalogNumber;
	cin >> catalogNumber;

	cout << endl << "�������� ������ ��� ��������: " << endl << endl;
	(*catalogsArray)[catalogNumber]->print();

	cout << endl << "������� �����: ";

	int number;
	cin >> number;

	cout << endl;

	(*catalogsArray)[catalogNumber]->removeArticle(number);

	cout << "������ ������� �� �������� \"" << (*catalogsArray)[catalogNumber]->name << "\"" << endl << endl;

}

void task15(vector<Catalog *> *catalogsArray) {

	cout << "�������� �������: " << endl << endl;

	for (int i = 0; i < (int)catalogsArray->size(); i++) {

		cout << "\t" << i << ") " << (*catalogsArray)[i]->name << endl;

	}

	cout << endl << "������� �����: ";

	int catalogNumber;
	cin >> catalogNumber;

	if ((*catalogsArray)[catalogNumber]->vertified) {

		(*catalogsArray)[catalogNumber]->setVertified(false);
		cout << endl << "� �������� ���� ������ \"��������\"" << endl << endl;

	} else {

		(*catalogsArray)[catalogNumber]->setVertified(true);
		cout << endl << "� �������� ��������� ������ \"��������\"" << endl << endl;

	}

}

void task16(Catalog *mainCatalog, vector<Catalog *> *catalogsArray) {

	cout << endl << "�������� �������� �� �������� ����������� ���������:" << endl << endl;

	cout << "\t\t1. Science" << endl;
	cout << "\t\t2. Sport" << endl;
	cout << "\t\t3. Gaming" << endl;
	cout << "\t\t4. Movies" << endl;
	cout << "\t\t5. News" << endl;
	cout << "\t\t6. Technology" << endl;
	cout << "\t\t7. Art" << endl;
	cout << "\t\t0. Undefined" << endl;

	cout << "������� ����� ���������: ";
	int intType;
	cin >> intType;

	cout << endl;

	Catalog *newCatalog = mainCatalog->catalogWithType((ArticleType)intType);

	cin.clear();
	while (cin.get() != '\n');

	cin >> *newCatalog;
	
	catalogsArray->insert(catalogsArray->end(), newCatalog);

	cout << endl << "������� ������" << endl << endl;

	newCatalog->print();

	cout << endl;

}

void task17() {

	cout << endl << "�������� ������������ ��� �������� ����������." << endl;

}

void task18(Catalog *mainCatalog, vector<Catalog *> *catalogsArray) {

	cout << endl << "�������� ����������: " << endl << endl;

	cout << "1) ���������� �� ���������� ����" << endl;
	cout << "2) ���������� �� ����������" << endl << endl;

	cout << "������� �����: ";

	int number;
	cin >> number;

	cout << endl << "�������� �������: " << endl << endl;

	cout << "\t0) " << mainCatalog->name << endl;
	for (int i = 0; i < (int)catalogsArray->size(); i++) {

		cout << "\t" << i + 1 << ") " << (*catalogsArray)[i]->name << endl;

	}

	cout << endl << "������� �����: ";

	int catalogNumber;
	cin >> catalogNumber;

	if (number == 1) {

		if (catalogNumber == 0) {

			mainCatalog->sortByWordsCount();

		} else {

			(*catalogsArray)[number - 1]->sortByWordsCount();

		}

	} else if (number == 2) {

		if (catalogNumber == 0) {

			mainCatalog->sortByType();

		}
		else {

			(*catalogsArray)[number - 1]->sortByType();

		}

	}

	cout << endl << "���������� �����������" << endl << endl;

}