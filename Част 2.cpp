#include <iostream>	
using namespace std;

double CalcPrice(int NmbrPages, int NmbrCopies, bool BW) //Смята цената на принтираните книги плюс плаките.
{
	int temp;  //Декларира променлива.
	if (NmbrPages % 16 > 0)  //Проверява дали броя на страниците разделен на 16 има остатък.
	{
		temp = ceil(NmbrPages / 16) * 16;  //Намира най-близкото делимо число на 16.
	}
	else temp = NmbrPages;  //Ако няма остатък приравнява temp да е равен на бтоя на страниците.
	if (BW == true)  //Проверява дали принтира черно-бели книги.
	{
		return((double)NmbrPages * 7) + ((double)temp / 2) * NmbrCopies * 0.01 + ((double)temp * 2);  //Смята цената за черно-бяло принтиране.
	}
	else return ((double)NmbrPages * 28) + ((double)temp / 2) * NmbrCopies * 0.04 + ((double)temp * 2);  //Смята цената за цветно принтиране.
	return 0;  //Връща резултат.
}
double CalcPrice2(int X, int NmbrPages, int NmbrCopies, bool BW)  //Декларира функция с параметри
{
	int temp;  //Декларира променлива.
	if (NmbrPages % X > 0)        //Проверява дали има остатък на броя на страниците спрямо Fold Signature-а.
	{
		temp = ceil(NmbrPages / X) * X;  //Намира най-близко делимото число до X.
	}
	else temp = NmbrPages;  //Ако няма остатък приравнява temp да е равен на бтоя на страниците.
	if (BW == true)  //Проверява дали принтира черно-бели книги.
	{
		return((double)NmbrPages * 7) + ((double)temp / 2) * NmbrCopies * 0.01 + ((double)temp * 2);  //Смята цената за черно-бяло принтиране.

	}
	else return ((double)NmbrPages * 28) + ((double)temp / 2) * (double)NmbrCopies * 0.04 + ((double)temp * 2);  //Смята цената за цветно принтиране.
	return 0;
}
int main() //Задава главната функция.
{
	cout << CalcPrice2(8, 34, 35, true) << endl;   //Извежда цената на принтираните черно-бели книги с 34 страници всяка и 8 fold signatures.
	cout << CalcPrice2(6, 34, 100, true) << endl;  //Извежда цената на принтираните черно-бели книги с 34 страници всяка и 6 fold signatures
	cout << CalcPrice(30, 50, false) << endl;  //Извежда цената на принтираните цветни книги с 30 страници всяка.
	cout << CalcPrice(34, 35, true) << endl;   //Извежда цената на принтираните черно-бели книги с 34 страници всяка.
	return 0;
}