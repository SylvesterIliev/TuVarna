#include <iostream>
using namespace std;

string fnct1(string a);        //��������� �������� ������ �����.
string fnct2(string a);        //��������� �������� ������ �����.
string soundex(string a);      //������� �� SOUNDEX
bool isvowel(char a);          //������������ ������� �� �������� �� ������ �����, ���������� �� ������� �2.
char checkConsunant(char a);   //������������ ������� �� ���������� �� ����� � ������� ��������, ���������� �� ������� {soundex}.

int main()
{
	char s[99];
	scanf_s("%98s", s, (unsigned)_countof(s));      //������ ���������, �������� �� ������������.
	int i = 0;
	char c;
	while (s[i])                                    //������� char (s).
	{  //�������� string-�� � ����� �����, �� �� �������� CaseSensitivity-��, ����� � ��������� �� ������� � ����������.
		c = s[i];
		s[i] = tolower(c);                          //�������� ������� � �����.
		i++;
	}

	cout << soundex(fnct2(fnct1(s)));               //������� ���������� �� 3-�� �������, ��������� � ����� �� ��������, �� ������.
	return 0;
}

string fnct1(string a)
{
	string temp = "";                               //������� string temp.
	temp += a.at(0);                                //������ ������� ������ �� � ��� temp.
	for (int i = 1; i < a.length(); i++) {          //��������� ���� 2 ������� �� �������� � ��� ��, �������� �������(�� �� ����� � ��������� string).
		if (a.at(i - 1) != a.at(i))
			temp += a.at(i);
	}
	return temp;
} 
bool isvowel(char a)
{
	char array[] = { 'a', 'e', 'o', 'u', 'i', 'y' };  //��������� ���� (char a) �������� �� ������ ����� �� ���������� �����.
	for (int j = 0; j < 5; j++) {                     //������� ������.
		if (a == array[j])
			return true;
	}
	return false;
}
string fnct2(string a)
{
	string temp = "";
	temp += a.at(0);
	for (int i = 1; i < a.length(); i++) {           //������� string �.
		if (!isvowel(a.at(i))) {                     //��� �������� �� ������� (i) �� � ������, ������ �������� ��� string temp.
			temp += a.at(i);
		}
		else
			temp += '0';                             //�������� �������� ����� � ����.
	}
	return temp;
}
char checkConsunant(char a)                          //�������� char(a) � ����� ����������� ��������.
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
	return '\0';                                      //��� �������� �� �������� �� ����� �� ���������� ����������, ����� '\0' (������ ������).
}
string soundex(string a)
{
	string temp = " ";
	temp += toupper(a.at(0));;                        //�������� ������� ����� � ������.
	for (int i = 1; i < a.length(); i++) {            //������� string a.
		if (checkConsunant(a.at(i)) != '\0')          //��� ���������� �� ������� checkConsunant �� � = '\0' (������ ������).
			temp += checkConsunant(a.at(i));          //������ ����������� �������� ��� string temp.
	}
	if (temp.length() <= 4) {                         //��� ��������� �� ���������� string temp � <= �� 4 �������, ������ ������������ ����.
		for (int j = temp.length(); j <= 4; j++)      
			temp += '0';                             
	}
	else if (temp.length() > 4) {                     //��� ��������� �� ���������� string temp � ������ �� 4 �������, � ���������� �� 4 �������.
		for (int j = temp.length() - 1; j > 4; j--)   //����� ��������� �� ���������� string temp � ������ ���������� �� (j) � 1, ������ � ��-������ �� 4. 
			temp.at(j) = ' ';                         //�������� ������� �� ������� (j) � ������(��������).
	}
	return temp;
}