#include <iostream>
#include <time.h>
using namespace std;

int fnct1(int a[20][20], string direction);

int main()
{
	int a[20][20];
	srand(time(NULL));                                                 //�������� ����� �� �������� �����.
	for (int i = 0; i < 20; i++) {                                     //������� ������ �� ������.
		for (int j = 0; j < 20; j ++) {                            //������� ������ �� ������.
				a[i][j] = rand() % 100;                    //����� �������� ����� � ������.
				//cin >> a[i][j];                          //��� ������ �� �������� ����� ������ �� ������.
			//a[i][j] = 1;                                     //�� �������� �� ����.
			//a[i][j + 1] = 2;                                         
			//a[i][j + 2] = 3;
			//a[i][j + 3] = 4;

		}
	}
	cout << "Product up. " << fnct1(a, "up") << endl;                  //������� ��������� ���� �� ����.
	cout << "Product down. " << fnct1(a, "down") << endl;
	cout << "Product left. " << fnct1(a, "left") << endl;
	cout << "Product right. " << fnct1(a, "right") << endl;
	cout << "Product diagonal. " << fnct1(a, "diagonal") << endl;
	return 0;
}
int fnct1(int a[20][20], string direction)
{
	int product = 0;
	int current = 0;
	if (direction == "up") {                                                     //��� �������� � ������. ������� ������ ������ ������ � ������� ������.
		for (int i = 19; i >= 0; i--) {
			for (int j = 19; j >= 0; j -= 4) {
				current = a[i][j] * a[i][j - 1] * a[i][j - 2] * a[i][j - 3];     //����� ���������� �������� �� � ����� �������������� �� 4-�� �������������� ����� �� ���� ������
				if (current > product)
					product = current;                                           //��� ��������� ������������ � ��-������ �� �������� ���������� ���-������ ��������, � ���������� �� ��������� ������������.
			}
		}
	}
	else if (direction == "down") {                                              //��� �������� � ������. ������� ������ ������ ������ � ������ �������.
		for (int i = 0; i < 20; i++) {
			for (int j = 0; j < 20; j += 4) {
				current = a[i][j] * a[i][j + 1] * a[i][j + 2] * a[i][j + 3];
				if (current > product)
					product = current;
			}
		}
	}
	else if (direction == "left") {                                             //��� �������� � ������. ������� ������ ������ ������� � ������ ������.
		for (int i = 0; i < 20; i+=4) {
			for (int j = 0; j < 20; j ++) {
				current = a[i][j] * a[i + 1][j] * a[i + 2][j] * a[i + 3][j];
				if (current > product)
					product = current;
			}
		}
	}
	else if (direction == "right") {                                            //��� �������� � �������. ������� ������ ������� ������ � ������ ������.
		for (int i = 19; i >= 0; i -= 4) {
			for (int j = 19; j >= 0; j--) {
				current = a[i][j] * a[i - 1][j] * a[i - 2][j] * a[i - 3][j];
				if (current > product)
					product = current;
			}
		}
	}
	else if (direction == "diagonal") {                                        //��� �������� � ����������. ������� ������ � ����� 4 ���������� ���������.
		for (int i = 0; i <= 16; i ++) {
			for (int j = 0; j <= 16; j++) {
				current = a[i][j] * a[i + 1][j + 1] * a[i + 2][j + 2] * a[i + 3][j + 3];
				if (current > product)
					product = current;
			}
		}
	}
	return product;
}