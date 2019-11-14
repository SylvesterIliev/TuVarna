#include <iostream>
using namespace std;

string fnct1(string a);
string fnct2(string a);
string soundex(string a);
bool isvowel(char a);
char checkConsunant(char a);

int main()
{
	char s[99];
	scanf_s("%98[a-zA-Z -]", s, (unsigned)_countof(s));   //Единствената промяна от Част 1 е, че {scanf_s} приема шпации(интервали) и тирета.
	int i = 0;
	char c;
	while (s[i])
	{
		c = s[i];
		s[i] = tolower(c);
		i++;
	}

	cout << soundex(fnct2(fnct1(s)));
	return 0;
}

string fnct1(string a)
{
	string temp = "";
	temp += a.at(0);
	for (int i = 1; i < a.length(); i++) {
		if (a.at(i - 1) != a.at(i))
			temp += a.at(i);
	}
	return temp;
}
bool isvowel(char a)
{
	char array[] = { 'a', 'e', 'o', 'u', 'i', 'y' };
	for (int j = 0; j < 5; j++) {
		if (a == array[j])
			return true;
	}
	return false;
}
string fnct2(string a)
{
	string temp = "";
	temp += a.at(0);
	for (int i = 1; i < a.length(); i++) {
		if (!isvowel(a.at(i))) {
			temp += a.at(i);
		}
		else
			temp += '0';
	}
	return temp;
}
char checkConsunant(char a)
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
	return '\0';
}
string soundex(string a)
{
	string temp = " ";
	temp += toupper(a.at(0));;
	for (int i = 1; i < a.length(); i++) {
		if (checkConsunant(a.at(i)) != '\0')
			temp += checkConsunant(a.at(i));
	}
	if (temp.length() <= 4) {
		for (int j = temp.length(); j <= 4; j++)
			temp += '0';
	}
	else if (temp.length() > 4) {
		for (int j = temp.length() - 1; j > 4; j--)
			temp.at(j) = ' ';
	}
	return temp;
}