
#include "stdafx.h"
#include "LAB3_503.h"

using namespace std;

int Triangle::counter = 0;

void Triangle::move(int dx, int dy) {

	Point *points[3] = { &point1, &point2, &point3 };

	for (int i = 0; i < 3; i++) {

		points[i]->x += dx;
		points[i]->y += dy;
	}
}

void main() {
	
	system(" chcp 1251 > nul");

	cout << "LAB3_503 ��5-23 ���� ������" << endl << endl;

	// ����� 4.7. ������������������ ������ � ��������� ������
	cout << "����� 4.7. ������������������ ������ � ��������� ������" << endl << endl;

	Triangle triangle;

	// ����������� 1
	triangle = Triangle();
	// ����������� 2
	triangle = Triangle(Point(1, 2), Point(3, 4), Point(5, 6));
	// ����������� 3
	Point points[3] = { Point(9, 8), Point(7, 6), Point(5, 4) };
	triangle = Triangle(points);

	cout << "counter = " << Triangle::counter << endl << endl;

	// ������
	triangle.print();

	// �����������
	Triangle triangleCopy = triangle;
	
	cout << "copy";
	triangle.print();
	cout << endl;

	// ����� �������
	triangle.move(11, 0);

	triangle.print();
	cout << endl;

	triangle.enter();

	triangle.print();
	cout << endl;

	// ��������������
	triangle.point1 = Point(66, 66);
	triangle.print();

	// ������������
	Triangle *dynamicTriangle = new Triangle(Point(1, 2), Point(3, 4), Point(5, 6));
	dynamicTriangle->print();
	delete dynamicTriangle;

	// ������
	Triangle triangles[30];
	for (int i = 0; i < 30; i++) {
		triangles[i] = Triangle(Point(rand() % 100, rand() % 100),
								Point(rand() % 100, rand() % 100),
								Point(rand() % 100, rand() % 100));
		
		if (i == 3) {
			triangles[i].print();
		}
	}
	cout << endl;

	// ������ � ������
	// ...............

	// ����� 4.8. ��������� ������������� ������ ������ protected � private

	//cout << triangle.privateVar;
	//cout << triangle.protectedVar;

	// ����� 4.9. ��������� ������������� ����������� ���������� � ������ 
	cout << "����� 4.9. ��������� ������������� ����������� ���������� � ������" << endl << endl;

	cout << "counter = " << Triangle::counter << endl << endl;

	// ����� 4.11. ������������������ ������ � ���� ������� �����������
	cout << "����� 4.11. ������������������ ������ � ���� ������� �����������" << endl << endl;

	// �����������
	RightTriangle rightTriangle = RightTriangle(Point(1, 2), Point(3, 4), Point(5, 6));
	
	// ����� �������
	rightTriangle.print();
	cout << endl;

	// ����� ������� �������
	rightTriangle.enter();
	rightTriangle.print();
	cout << endl;

	// ������
	RightTriangle rightTriangles[10];
	for (int i = 0; i < 10; i++) {
		rightTriangles[i] = RightTriangle(Point(rand() % 100, rand() % 100),
						       			  Point(rand() % 100, rand() % 100),
									      Point(rand() % 100, rand() % 100));
		if (i == 3) {
			rightTriangles[i].print();
		}
	}

	// Friend-�������
	cout << endl;
	printArray(rightTriangles, 10);
	cout << endl;

	system("Pause");
}
