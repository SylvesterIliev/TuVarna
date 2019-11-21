#include <iostream>
using namespace std;

bool leapYear(int Year);                                                                  //��������� �� ���������.
void nextDate();

int main()
{
	nextDate();
	return 0;
}
bool leapYear(int Year)                                                                   //��������� ���� � ��������� ������.
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
	int count = 0;                                                                         //���� ��������.
	int CurrentMonth = 1;                                                                  //������ ������� ����� (� ���� ������ ������).
	int Date = 1;                                                                          //������ ������� ��� �� ��������� (����������).
	int CurrentDay = 2;                                                                    //������ ����� �� ���������.
	int Year = 1901;                                                                       //������ ��������.
	int DayNmbrs[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };              //������ ����� � ���� �� ����� �� ������� �����.
	for (Year; Year <= 2000; Year++) {                                                     //������� �������� �� 1901�. �� 2000� �����������
		if (leapYear)                                                                      //��� � ��������� ������, ������ �������� �� ��� 29 ���, ��� �� �, �� ������� 28.
			DayNmbrs[2] = 29;
		else
			DayNmbrs[2] = 28;

		for (CurrentMonth; CurrentMonth <= 12; CurrentMonth++) {                           //������� ��������.
			for (Date; Date <= DayNmbrs[CurrentMonth]; Date++) {                           //������� ����� �� ��������.
				if (CurrentDay > 7)                                                        //������ ����� ��������� 7(��������� � ���� �������) ����� �� ���������� �� 1 (����������).
					CurrentDay = 1;
				if (Date == 1 && CurrentDay == 7)                                          //��� ����� � ����� �� 7(������) � ������ � 1-�� �� ������� �����, ��������� ���� �� �������� � 1.
				{
					count++;
				}
				CurrentDay++;                                                              //��������� ����� �� ���������.
			}
			Date = 1;                                                                      //���������� ����� �� ������, �� �� ����� �� ��������� ������.
		}
		CurrentMonth = 1;                                                                  //���������� ������.
	}
	cout << count << " ������ � ����� �� 1-���� ��� �� ������ ���� 20-�� ���." << endl;    //������� ����������.
}