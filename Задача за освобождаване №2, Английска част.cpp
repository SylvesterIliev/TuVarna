#include <iostream>
using namespace std;
struct BoundingBox { int x_BL; int y_BL; int x_UR; int y_UR; };
struct Line { int x; int y; }; //Declares data type {Line}
struct Circle { int x; int y; int r ;}; //Declares data type {Circle}
BoundingBox Funct2(Shape C);
union Shape  //Declares Union of {Circle} or {Line}
{
	Circle cir;
	Line vec;
	~Shape() {} 
};

int main()
{

}

BoundingBox Funct2(Shape C)  //Finds the BoundingBox for the chosen Shape.
{//To Do:
	BoundingBox A;
	return A;
}