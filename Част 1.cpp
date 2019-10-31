#include <iostream>
using namespace std;

double CalcPrice(int NmbrPages, int NmbrCopies, bool BW)  //Декларира функция с параметри
{
	if (BW == true)  //Проверява дали принтира черно-бели книги.
	{
		return((double)NmbrPages * 7) + ((double)NmbrPages / 2) * NmbrCopies * 0.01 + ((double)NmbrCopies * 2);  //Смята цената за черно-бяло принтиране.

	}
	else return((double)NmbrPages * 28) + ((double)NmbrPages / 2) * NmbrCopies * 0.04 + ((double)NmbrCopies * 2);  //Смята цената за цветно принтиране.
	return 0;  //Връща резултат
}
double CalcPriceBW(int NmbrPages, int NmbrCopies)  //Декларира функция с параметри
{
	return CalcPrice(NmbrPages, NmbrCopies, true);  //Връща фунцията от подточка 1 с параметри зададени за черно-бяло принтиране.
}
double CalcPriceColor(int NmbrPages, int NmbrCopies)  //Декларира функция с параметри
{
	return CalcPrice(NmbrPages, NmbrCopies, false);  //Връща фунцията от подточка 1 с параметри зададени за цветно принтиране.
}
int main()  //Задава главната функция.
{
	cout << CalcPriceColor(32, 1000) << endl;  //Извежда цената за цветно принтиране на 1000 книги с 32 страници.
	cout << CalcPriceBW(40, 2000) << endl;  //Извежда цената за черно и бяло принтиране за 2000 книги с 40 страници.
	cout << CalcPriceBW(160, 400) << endl;  //Извежда цената за черно и бяло принтиране за 400 книги с 160 страници.
}