#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    setlocale(LC_ALL, "RUS");
    int n;
    cout << "n = "; cin >> n;
    int* a = new int[n];
    srand(time(NULL));
    cout << "Исходный массив:\n";
    for (int i = 0; i < n; i++) {
        a[i] = rand() % 21 - 10; // числа от -10 до 10
        cout << a[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < n; i++)
        if (a[i] < 0)
            a[i] = a[i] * a[i];
    cout << "После замены отрицательных элементов их квадратами:\n";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
    delete[] a;
    return 0;
}