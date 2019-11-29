#include <iostream>
#include <time.h>
#include <string>
#include <iomanip>
using namespace std;

char char_rand();																				//Връща случайно генериран символ (м/у "." и "#").
void cor_gen(int T);																			//Случайно генерира Т на брой коридори и ги извежда.
void path(string a);																			//Намира най-кратния път за изход. (С най-малко препядствия).

int main()
{
	int a = 0;
	cout << "Type a number from 1 to 100. ";
	cin >> a;
	while (a < 1 || a > 100) {																	//Цикъл, който ограничава въвеждането.
		cout << "Wrong input." << endl;
		cout << "Enter a valid input." << endl;
		cin >> a;
	}
	srand(time(NULL));																			//Генерира seed спрямо времето на системата.
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
			int length = (rand() % 50) + 1;															//Създава случайна дължина на коридора.
			int e = rand() % length;																//Намира позицията на Ели в коридора.
			string cor_temp = "";																	//Иницира коридора.
			for (int j = 0; j < length; j++)														//Обхожда коридора.
				cor_temp += char_rand();															//Запълва коридора със символите от функция char_rand().
			cor_temp.at(e) = 'E';																	//Слага Ели в коридора.
			cout << cor_temp << setw(100 - cor_temp.length()) << "The shortest path is ";			//Извежда коридора на екрана.
			path(cor_temp);																			//Извиква функцията, извеждаща най-краткия път.
			cout << endl;
	}
}
void path(string a)
{
	bool right = false;																				//Проверява дали препядствията са отдясната страна на Ели.
	int count_L = 0;																				//Брояч за левите препядстия.
	int count_R = 0;																				//Брояч за десните препядствия.
	for (int i = 0; i < a.length(); i++) {															//Обхожда коридора.
		if (a.at(i) == '#') {																		//Ако попадне на препядствие, увеличава съответния брояч(този за левите препядстия).
			if (right == false)
				count_L++;
			else
				count_R++;
		}
		if (a.at(i) == 'E')																			//Ако обхождането стигне до Ели, вече преминава от дясната й страна.
			right = true;
	}
	if (count_L < count_R) {																		//Сравнява броя на препядстията и извежда най-кратния път.
		cout << count_L << ", to the left.";
	}
	else
		cout << count_R << ", to the right.";
}