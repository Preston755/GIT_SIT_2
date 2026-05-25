#include <iostream>
#include <climits>
using namespace std;

int main() {
    setlocale(LC_ALL, "RUS");
    int n;
    cout << "Введите размер массива: ";
    cin >> n;

    int* a = new int[n];
    cout << "Введите элементы массива:\n";
    for (int i = 0; i < n; i++) {
        cout << "a[" << i << "] = ";
        cin >> a[i];
    }

    int left, right;
    cout << "Введите границы интервала [a, b]: ";
    cin >> left >> right;
    if (left > right) swap(left, right);

    int sum = 0, count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 != 0 && (a[i] < left || a[i] > right)) {
            sum += a[i];
            count++;
        }
    }

    if (count == 0) {
        cout << "Таких элементов нет\n";
    }
    else {
        cout << "Среднее арифметическое: " << (double)sum / count << endl;
    }

    delete[] a;
    return 0;
}