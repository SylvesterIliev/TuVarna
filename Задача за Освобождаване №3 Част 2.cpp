#include <iostream>
#include <cstdlib>
#include <list>
#include <conio.h>
using namespace std;
void fnct1();

int main()
{
	fnct1();
	return 0;
}

void fnct1()
{
	string Str1 = " ";
	char c = 'a';
	list <string> list1;
	do  //����� {char(c)} � {getchar} � ��� �� � "." �� ������ � {string Str1}.
	{
		c = getchar();
		if (c != '.'){ 
		Str1 += c;
		if (c == '\n'){  //Ako {char(c)} � ��� ���, ������� {Str1} � ������� ���� �� ������� � ������ {Str1}.
			list1.push_back(Str1);
			Str1 = " ";
			}
				}
	} while (c != '.');  //��� {c} � ����� �� ".", ������� �����.
	while (list1.size() > 0)  //������ �������� �� ������� � ��-����� �� ����, ������� ���������� � ������� ��� �� ������.
	{
		cout << list1.back();  //������� �� ������ ���������� ������� �� �������.
		list1.pop_back();  //�������� ���������� �������.
	}
}