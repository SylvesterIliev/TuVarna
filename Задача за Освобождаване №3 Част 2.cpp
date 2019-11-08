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
	do  //Взима {char(c)} с {getchar} и ако не е "." го добавя в {string Str1}.
	{
		c = getchar();
		if (c != '.'){ 
		Str1 += c;
		if (c == '\n'){  //Ako {char(c)} е нов ред, избутва {Str1} в задната част на списъка и нулира {Str1}.
			list1.push_back(Str1);
			Str1 = " ";
			}
				}
	} while (c != '.');  //Ако {c} е равно на ".", цикълът спира.
	while (list1.size() > 0)  //Докато размерът на списъка е по-голям от нула, извежда елементите в обратен ред на екрана.
	{
		cout << list1.back();  //Извежда на екрана последният елемент от списъка.
		list1.pop_back();  //Премахва последният елемент.
	}
}