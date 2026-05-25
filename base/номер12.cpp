#include <iostream> 
#include <cmath>
using namespace std; 

int main() {
	setlocale(LC_ALL, "RU"); 
	int x, y;
	cout << "Введите трехзначное число" << endl; 
	cin >> x;
	int a, b, c;
	a = x % 10; 
	x /= 10;
	b = x % 10;
	c = x / 10;
	int d, f, g;
	d = 25 % a; 
	f = 25 % b;
	g = 25 % c;
	y = g * 100 + f * 10 + d; 
	cout << y; 
}