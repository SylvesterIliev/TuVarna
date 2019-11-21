#include <iostream>
using namespace std;

bool leapYear(int Year);                                                                  //Прототипи на функциите.
void nextDate();

int main()
{
	nextDate();
	return 0;
}
bool leapYear(int Year)                                                                   //Проверява дали е високосна година.
{
	if (Year % 4 == 0)
		return false;
	else if (Year % 400 == 0)
		return true;
	else if (Year % 100 == 0)
		return false;
	return true;
}
void nextDate()                                                                            
{
	int count = 0;                                                                         //Брои неделите.
	int CurrentMonth = 1;                                                                  //Задава настоящ месец (в този случай Януари).
	int Date = 1;                                                                          //Задава първият ден от седмицата (понеделник).
	int CurrentDay = 2;                                                                    //Задава денят от седмицата.
	int Year = 1901;                                                                       //Задава годината.
	int DayNmbrs[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };              //Задава масив с броя на дните от дадения месец.
	for (Year; Year <= 2000; Year++) {                                                     //Обхожда годините от 1901г. до 2000г включително
		if (leapYear)                                                                      //Ако е високосна година, задава Февруари да има 29 дни, ако не е, си остават 28.
			DayNmbrs[2] = 29;
		else
			DayNmbrs[2] = 28;

		for (CurrentMonth; CurrentMonth <= 12; CurrentMonth++) {                           //Обхожда месеците.
			for (Date; Date <= DayNmbrs[CurrentMonth]; Date++) {                           //Обхожда дните от месеците.
				if (CurrentDay > 7)                                                        //Когато денят прехвърли 7(проверило е цяла седмица) денят се приравнява на 1 (Понеделник).
					CurrentDay = 1;
				if (Date == 1 && CurrentDay == 7)                                          //Ако денят е равен на 7(Неделя) и датата е 1-ви от дадения месец, увеличава броя на Неделите с 1.
				{
					count++;
				}
				CurrentDay++;                                                              //Увеличава денят от седмицата.
			}
			Date = 1;                                                                      //Рестартира денят от месеца, за да почне да проверява наново.
		}
		CurrentMonth = 1;                                                                  //Рестартира месеца.
	}
	cout << count << " Недели е имало на 1-вият ден от месеца през 20-ти век." << endl;    //Извежда резултатът.
}