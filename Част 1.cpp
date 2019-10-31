#include <iostream>
using namespace std;

double CalcPrice(int NmbrPages, int NmbrCopies, bool BW)  //��������� ������� � ���������
{
	if (BW == true)  //��������� ���� �������� �����-���� �����.
	{
		return((double)NmbrPages * 7) + ((double)NmbrPages / 2) * NmbrCopies * 0.01 + ((double)NmbrCopies * 2);  //����� ������ �� �����-���� ����������.

	}
	else return((double)NmbrPages * 28) + ((double)NmbrPages / 2) * NmbrCopies * 0.04 + ((double)NmbrCopies * 2);  //����� ������ �� ������ ����������.
	return 0;  //����� ��������
}
double CalcPriceBW(int NmbrPages, int NmbrCopies)  //��������� ������� � ���������
{
	return CalcPrice(NmbrPages, NmbrCopies, true);  //����� �������� �� �������� 1 � ��������� �������� �� �����-���� ����������.
}
double CalcPriceColor(int NmbrPages, int NmbrCopies)  //��������� ������� � ���������
{
	return CalcPrice(NmbrPages, NmbrCopies, false);  //����� �������� �� �������� 1 � ��������� �������� �� ������ ����������.
}
int main()  //������ �������� �������.
{
	cout << CalcPriceColor(32, 1000) << endl;  //������� ������ �� ������ ���������� �� 1000 ����� � 32 ��������.
	cout << CalcPriceBW(40, 2000) << endl;  //������� ������ �� ����� � ���� ���������� �� 2000 ����� � 40 ��������.
	cout << CalcPriceBW(160, 400) << endl;  //������� ������ �� ����� � ���� ���������� �� 400 ����� � 160 ��������.
}