#include <iostream>

using namespace std;

struct Circle { int x; int y; int r; };  //Задава тип данни {Circle}
struct BoundingBox { int x_BL; int y_BL; int x_UR; int y_UR; };  //BL - BottomLeft (долен ляв ъгъл)  //UR - UpperRight (горен десен ъгъл)
Circle Funct1 (int x, int y, int r);  // Създава нов {Circle}
BoundingBox Funct2(Circle C); //Създава нов {BoundingBox} като приема {Circle} за парам.
void PrintBB(BoundingBox A); //Принтира стойностите за {BoundingBox}
BoundingBox Funct3(BoundingBox A, BoundingBox B); //Създава нов {BoundingBox} (общ), базиран на други 2.

int main()
{ //Част 1 от задачата.
	Circle B = Funct1(1, 2, 3); //Създава {Circle} със следните параметри, чрез функция 1
	BoundingBox C = Funct2(B); //Създава {BoundingBox} чрез функция 2, с парам. {Circle B}
	PrintBB(C); //Извежда стойностите за {BoundingBox C}
	//Част 2.
	int x1, y1, r1, x2, y2, r2;
	cout << endl << "Въведете стойност за Х-са на първият кръг";
	cin >> x1;
	cout << endl << "Въведете стойност за У-ка на първият кръг";
	cin >> y1;
	cout << endl << "Въведете стойност за радиуса на първият кръг";
	cin >> r1;
	cout << endl << "Въведете стойност за Х-са на вторият кръг";
	cin >> x2;
	cout << endl << "Въведете стойност за У-ка на вторият кръг";
	cin >> y2;
	cout << endl << "Въведете стойност за радиуса на вторият кръг";
	cin >> r2;
	Circle D = Funct1(x1, y1, r1);
	Circle E = Funct1(x2, y2, r2);
	BoundingBox F = Funct2(D);
	BoundingBox H = Funct2(E);
	BoundingBox G = Funct3(F, H); //Създава {BoundingBox G} чрез другите 2 {BoundingBox F} и {BoundingBox H}.
	PrintBB(G);
	return 0;
}
Circle Funct1(int x, int y, int r) //Създава {Circle A} и приравнява полетата на структурата на парам. на функцията и връща {Circle A}.
{
	Circle A;
	A.x = x;
	A.y = y;
	A.r = r;
	return A;
}
BoundingBox Funct2(Circle C) //Създава {BoundingBox A} и приравнява полетата на структурата с полетата на парам. {Circle C} и връща {BoundingBox A}.
{
	BoundingBox A;
	A.x_BL = C.x - C.r;
	A.y_BL = C.y - C.r;
	A.x_UR = C.x + C.r;
	A.y_UR = C.y + C.r;
    return A;
}
void PrintBB(BoundingBox A) //Извежда координатите за долен ляв и горен десен ъгъл на {BoundingBox A} (парам. на функцията)
{
	cout << "Това е долен ляв ъгъл. (" << A.x_BL << "," << A.y_BL << ")" <<endl;
	cout << "Това е горен десен ъгъл. (" << A.x_UR << "," << A.y_UR << ")" << endl;

}
BoundingBox Funct3(BoundingBox A, BoundingBox B) //Създава общ {BoundingBox}, базиран на други 2 {BoundingBox A} и {BoundingBox B}
{
	int yBL;
	int xBL;
	if (A.y_BL < B.y_BL) //Ако y-кът на долен ляв ъгъл на А е по-малък от този на В, значи това е у-ка на общият {BoundingBox}
	{
		yBL = A.y_BL;
	}
	else
		yBL = B.y_BL;
	if (A.x_BL < B.x_BL) //Ако х-кът на долен ляв ъгъл на А е по-малък от този на В, значи това е х-са на общият {BoundingBox}
	{
		xBL = A.x_BL;
	}
	else
		xBL = B.x_BL;

	int yUR;
	int xUR;
	if (A.y_UR > B.y_UR) //Ако y-кът на горен десен ъгъл на А е по-голям от този на В, значи това е у-ка на общият {BoundingBox}
	{
		yUR = A.y_UR;
	}
	else
		yUR = B.y_UR;
	if (A.x_UR > B.x_UR) //Ако х-кът на горен десен ъгъл на А е по-голям от този на В, значи това е х-са на общият {BoundingBox}
	{
		xUR = A.x_UR;
	}
	else
		xUR = B.x_UR;
	BoundingBox New; //Създава нов {BoundingBox} с парам. получени от {if} блоковете и съответно го връща.
	New.x_BL = xBL;
	New.y_BL = yBL;
	New.x_UR = xUR;
	New.y_UR = yUR;
	return New;
}
