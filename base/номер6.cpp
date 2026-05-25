#include <iostream>
#include <cmath>
using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    double x, y;
    cout << "x = ";
    cin >> x;
    cout << "y = ";
    cin >> y;
    double c = sqrt(exp(sqrt(cos((x + y) / (x - y)))) + sin(pow(log(x), 2) * pow(y, 2)));
    cout << "Результат: " << c << endl;
    return 0;
}