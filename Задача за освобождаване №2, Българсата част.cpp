#include <iostream>

using namespace std;

struct Circle { int x; int y; int r; };  //������ ��� ����� {Circle}
struct BoundingBox { int x_BL; int y_BL; int x_UR; int y_UR; };  //BL - BottomLeft (����� ��� ����)  //UR - UpperRight (����� ����� ����)
Circle Funct1 (int x, int y, int r);  // ������� ��� {Circle}
BoundingBox Funct2(Circle C); //������� ��� {BoundingBox} ���� ������ {Circle} �� �����.
void PrintBB(BoundingBox A); //�������� ����������� �� {BoundingBox}
BoundingBox Funct3(BoundingBox A, BoundingBox B); //������� ��� {BoundingBox} (���), ������� �� ����� 2.

int main()
{ //���� 1 �� ��������.
	Circle B = Funct1(1, 2, 3); //������� {Circle} ��� �������� ���������, ���� ������� 1
	BoundingBox C = Funct2(B); //������� {BoundingBox} ���� ������� 2, � �����. {Circle B}
	PrintBB(C); //������� ����������� �� {BoundingBox C}
	//���� 2.
	int x1, y1, r1, x2, y2, r2;
	cout << endl << "�������� �������� �� �-�� �� ������� ����";
	cin >> x1;
	cout << endl << "�������� �������� �� �-�� �� ������� ����";
	cin >> y1;
	cout << endl << "�������� �������� �� ������� �� ������� ����";
	cin >> r1;
	cout << endl << "�������� �������� �� �-�� �� ������� ����";
	cin >> x2;
	cout << endl << "�������� �������� �� �-�� �� ������� ����";
	cin >> y2;
	cout << endl << "�������� �������� �� ������� �� ������� ����";
	cin >> r2;
	Circle D = Funct1(x1, y1, r1);
	Circle E = Funct1(x2, y2, r2);
	BoundingBox F = Funct2(D);
	BoundingBox H = Funct2(E);
	BoundingBox G = Funct3(F, H); //������� {BoundingBox G} ���� ������� 2 {BoundingBox F} � {BoundingBox H}.
	PrintBB(G);
	return 0;
}
Circle Funct1(int x, int y, int r) //������� {Circle A} � ���������� �������� �� ����������� �� �����. �� ��������� � ����� {Circle A}.
{
	Circle A;
	A.x = x;
	A.y = y;
	A.r = r;
	return A;
}
BoundingBox Funct2(Circle C) //������� {BoundingBox A} � ���������� �������� �� ����������� � �������� �� �����. {Circle C} � ����� {BoundingBox A}.
{
	BoundingBox A;
	A.x_BL = C.x - C.r;
	A.y_BL = C.y - C.r;
	A.x_UR = C.x + C.r;
	A.y_UR = C.y + C.r;
    return A;
}
void PrintBB(BoundingBox A) //������� ������������ �� ����� ��� � ����� ����� ���� �� {BoundingBox A} (�����. �� ���������)
{
	cout << "���� � ����� ��� ����. (" << A.x_BL << "," << A.y_BL << ")" <<endl;
	cout << "���� � ����� ����� ����. (" << A.x_UR << "," << A.y_UR << ")" << endl;

}
BoundingBox Funct3(BoundingBox A, BoundingBox B) //������� ��� {BoundingBox}, ������� �� ����� 2 {BoundingBox A} � {BoundingBox B}
{
	int yBL;
	int xBL;
	if (A.y_BL < B.y_BL) //��� y-��� �� ����� ��� ���� �� � � ��-����� �� ���� �� �, ����� ���� � �-�� �� ������ {BoundingBox}
	{
		yBL = A.y_BL;
	}
	else
		yBL = B.y_BL;
	if (A.x_BL < B.x_BL) //��� �-��� �� ����� ��� ���� �� � � ��-����� �� ���� �� �, ����� ���� � �-�� �� ������ {BoundingBox}
	{
		xBL = A.x_BL;
	}
	else
		xBL = B.x_BL;

	int yUR;
	int xUR;
	if (A.y_UR > B.y_UR) //��� y-��� �� ����� ����� ���� �� � � ��-����� �� ���� �� �, ����� ���� � �-�� �� ������ {BoundingBox}
	{
		yUR = A.y_UR;
	}
	else
		yUR = B.y_UR;
	if (A.x_UR > B.x_UR) //��� �-��� �� ����� ����� ���� �� � � ��-����� �� ���� �� �, ����� ���� � �-�� �� ������ {BoundingBox}
	{
		xUR = A.x_UR;
	}
	else
		xUR = B.x_UR;
	BoundingBox New; //������� ��� {BoundingBox} � �����. �������� �� {if} ��������� � ��������� �� �����.
	New.x_BL = xBL;
	New.y_BL = yBL;
	New.x_UR = xUR;
	New.y_UR = yUR;
	return New;
}
