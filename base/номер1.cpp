#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;
int main(){
	setlocale(LC_ALL, "RUS");
	double x, y, f;
	cout << "Введите значение элемента (x)" << endl;
	cin >> x;
	cout << "Введите значение элемента (y)" << endl;
	cin >> y;

	f = 1.0 / 2.0 * sqrt(pow(M_E, pow(x,2) + pow(y, 2))) - y * x / x * x + y * y  + log(sqrt(pow(x, 4)) / sqrt(pow(y, 4)));
	cout << "f =" << f << endl;
	system("pause");
	return 0;
