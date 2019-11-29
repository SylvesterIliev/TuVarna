#include <iostream>
#include <time.h>
#include <string>
#include <iomanip>
using namespace std;

char char_rand();																				//����� �������� ��������� ������ (�/� "." � "#").
void cor_gen(int T);																			//�������� �������� � �� ���� �������� � �� �������.
void path(string a);																			//������ ���-������� ��� �� �����. (� ���-����� �����������).

int main()
{
	int a = 0;
	cout << "Type a number from 1 to 100. ";
	cin >> a;
	while (a < 1 || a > 100) {																	//�����, ����� ���������� �����������.
		cout << "Wrong input." << endl;
		cout << "Enter a valid input." << endl;
		cin >> a;
	}
	srand(time(NULL));																			//�������� seed ������ ������� �� ���������.
	cor_gen(a);
	return 0;
}
char char_rand()
{
	int a = rand() % 2;
	if (a == 0)
		return '.';
	return '#';
}
void cor_gen(int T)
{
	for (int i = 0; i < T; i++) {
			int length = (rand() % 50) + 1;															//������� �������� ������� �� ��������.
			int e = rand() % length;																//������ ��������� �� ��� � ��������.
			string cor_temp = "";																	//������� ��������.
			for (int j = 0; j < length; j++)														//������� ��������.
				cor_temp += char_rand();															//������� �������� ��� ��������� �� ������� char_rand().
			cor_temp.at(e) = 'E';																	//����� ��� � ��������.
			cout << cor_temp << setw(100 - cor_temp.length()) << "The shortest path is ";			//������� �������� �� ������.
			path(cor_temp);																			//������� ���������, ��������� ���-������� ���.
			cout << endl;
	}
}
void path(string a)
{
	bool right = false;																				//��������� ���� ������������� �� ��������� ������ �� ���.
	int count_L = 0;																				//����� �� ������ ����������.
	int count_R = 0;																				//����� �� ������� �����������.
	for (int i = 0; i < a.length(); i++) {															//������� ��������.
		if (a.at(i) == '#') {																		//��� ������� �� �����������, ��������� ���������� �����(���� �� ������ ����������).
			if (right == false)
				count_L++;
			else
				count_R++;
		}
		if (a.at(i) == 'E')																			//��� ����������� ������ �� ���, ���� ��������� �� ������� � ������.
			right = true;
	}
	if (count_L < count_R) {																		//�������� ���� �� ������������ � ������� ���-������� ���.
		cout << count_L << ", to the left.";
	}
	else
		cout << count_R << ", to the right.";
}