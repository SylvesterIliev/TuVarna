#include <iostream>
using namespace std;

string fnct1(string a);        //Функцията премахва двойни букви.
string fnct2(string a);        //Функцията премахва гласни букви.
string soundex(string a);      //Функция за SOUNDEX
bool isvowel(char a);          //Спомагателна функция за проверка на гласни букви, използвана от фунцкия №2.
char checkConsunant(char a);   //Спомагателна функция за заместване на буква с числова стойност, използвана от функция {soundex}.

int main()
{
	char s[99];
	scanf_s("%98s", s, (unsigned)_countof(s));      //Приема стойности, въведени от клавиатурата.
	int i = 0;
	char c;
	while (s[i])                                    //Обхожда char (s).
	{  //Превръща string-ът в малки букви, за да премахне CaseSensitivity-то, което е проблемно за нататък в програмата.
		c = s[i];
		s[i] = tolower(c);                          //Превръща буквите в малки.
		i++;
	}

	cout << soundex(fnct2(fnct1(s)));               //Извежда резултатът от 3-те функции, подредени в редът на действие, на екрана.
	return 0;
}

string fnct1(string a)
{
	string temp = "";                               //Иницира string temp.
	temp += a.at(0);                                //Добавя първият символ от а към temp.
	for (int i = 1; i < a.length(); i++) {          //Проверява дали 2 символа си съвпадат и ако да, премахва единият(не го слага в върнатият string).
		if (a.at(i - 1) != a.at(i))
			temp += a.at(i);
	}
	return temp;
} 
bool isvowel(char a)
{
	char array[] = { 'a', 'e', 'o', 'u', 'i', 'y' };  //Проверява дали (char a) отговаря на гласна буква от зададеният масив.
	for (int j = 0; j < 5; j++) {                     //Обхожда масива.
		if (a == array[j])
			return true;
	}
	return false;
}
string fnct2(string a)
{
	string temp = "";
	temp += a.at(0);
	for (int i = 1; i < a.length(); i++) {           //Обхожда string а.
		if (!isvowel(a.at(i))) {                     //Ако символът на позиция (i) не е гласна, добавя символът към string temp.
			temp += a.at(i);
		}
		else
			temp += '0';                             //Замества гласните букви с нули.
	}
	return temp;
}
char checkConsunant(char a)                          //Сравнява char(a) и връща съответната стойност.
{
	if (a == 'b' || a == 'p' || a == 'f' || a == 'v')
		return '1';
	if (a == 'c' || a == 's' || a == 'k' || a == 'g' || a == 'j' || a == 'q' || a == 'x' || a == 'z')
		return '2';
	if (a == 'd' || a == 't')
		return '3';
	if (a == 'l')
		return '4';
	if (a == 'm' || a == 'n')
		return '5';
	if (a == 'r')
		return '6';
	return '\0';                                      //Ако символът не отгаваря на никоя от зададените стойностти, връща '\0' (празен символ).
}
string soundex(string a)
{
	string temp = " ";
	temp += toupper(a.at(0));;                        //Превръща първата буква в главна.
	for (int i = 1; i < a.length(); i++) {            //Обхожда string a.
		if (checkConsunant(a.at(i)) != '\0')          //Ако резултатът от функция checkConsunant не е = '\0' (празен символ).
			temp += checkConsunant(a.at(i));          //Добавя съответният резултат към string temp.
	}
	if (temp.length() <= 4) {                         //Ако дължината на полученият string temp е <= от 4 символа, добавя допълнителни нули.
		for (int j = temp.length(); j <= 4; j++)      
			temp += '0';                             
	}
	else if (temp.length() > 4) {                     //Ако дължината на полученият string temp е повече от 4 символа, я органичава до 4 символа.
		for (int j = temp.length() - 1; j > 4; j--)   //Взима дължината на полученият string temp и намаля стойността на (j) с 1, докато е по-голяма от 4. 
			temp.at(j) = ' ';                         //Замества сиволът на позиция (j) с шпация(интервал).
	}
	return temp;
}