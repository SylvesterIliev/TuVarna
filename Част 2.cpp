#include <iostream>	
using namespace std;

double CalcPrice(int NmbrPages, int NmbrCopies, bool BW) //����� ������ �� ������������ ����� ���� �������.
{
	int temp;  //��������� ����������.
	if (NmbrPages % 16 > 0)  //��������� ���� ���� �� ���������� �������� �� 16 ��� �������.
	{
		temp = ceil(NmbrPages / 16) * 16;  //������ ���-�������� ������ ����� �� 16.
	}
	else temp = NmbrPages;  //��� ���� ������� ���������� temp �� � ����� �� ���� �� ����������.
	if (BW == true)  //��������� ���� �������� �����-���� �����.
	{
		return((double)NmbrPages * 7) + ((double)temp / 2) * NmbrCopies * 0.01 + ((double)temp * 2);  //����� ������ �� �����-���� ����������.
	}
	else return ((double)NmbrPages * 28) + ((double)temp / 2) * NmbrCopies * 0.04 + ((double)temp * 2);  //����� ������ �� ������ ����������.
	return 0;  //����� ��������.
}
double CalcPrice2(int X, int NmbrPages, int NmbrCopies, bool BW)  //��������� ������� � ���������
{
	int temp;  //��������� ����������.
	if (NmbrPages % X > 0)        //��������� ���� ��� ������� �� ���� �� ���������� ������ Fold Signature-�.
	{
		temp = ceil(NmbrPages / X) * X;  //������ ���-������ �������� ����� �� X.
	}
	else temp = NmbrPages;  //��� ���� ������� ���������� temp �� � ����� �� ���� �� ����������.
	if (BW == true)  //��������� ���� �������� �����-���� �����.
	{
		return((double)NmbrPages * 7) + ((double)temp / 2) * NmbrCopies * 0.01 + ((double)temp * 2);  //����� ������ �� �����-���� ����������.

	}
	else return ((double)NmbrPages * 28) + ((double)temp / 2) * (double)NmbrCopies * 0.04 + ((double)temp * 2);  //����� ������ �� ������ ����������.
	return 0;
}
int main() //������ �������� �������.
{
	cout << CalcPrice2(8, 34, 35, true) << endl;   //������� ������ �� ������������ �����-���� ����� � 34 �������� ����� � 8 fold signatures.
	cout << CalcPrice2(6, 34, 100, true) << endl;  //������� ������ �� ������������ �����-���� ����� � 34 �������� ����� � 6 fold signatures
	cout << CalcPrice(30, 50, false) << endl;  //������� ������ �� ������������ ������ ����� � 30 �������� �����.
	cout << CalcPrice(34, 35, true) << endl;   //������� ������ �� ������������ �����-���� ����� � 34 �������� �����.
	return 0;
}