#include <iostream> 
#include <cmath>
using namespace std;

int main() {
	setlocale(LC_ALL, "RU");
	int x, y;
	cout << "¬ведите четырЄхзначное число" << endl;
	cin >> x;
	int a, b, r, s;
	a = x / 1000;
	b = (x / 100) % 10;
	r = (x / 10) % 10;
	s = x % 10;
	int c, d, f, g;
	c = a * b * r * s % 10;
	d = (b * r) % a;
	f = (a + b + r + s) % s;
	g = abs(b - r) % 10;
	y = c * 1000 + d * 100 + f * 10 + g;
	cout << y; 
}
