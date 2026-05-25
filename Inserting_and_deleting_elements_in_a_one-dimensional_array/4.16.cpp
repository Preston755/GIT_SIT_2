#include <iostream>
#include <climits>
using namespace std;

int main() {
    setlocale(LC_ALL, "RUS");
    int n;
    cout << "Введите размер массива: ";
    cin >> n;

    int* a = new int[2 * n]; 
    cout << "Введите элементы массива:\n";
    for (int i = 0; i < n; i++) {
        cout << "a[" << i << "] = ";
        cin >> a[i];
    }

    int X;
    cout << "Введите X: ";
    cin >> X;

    // Находим максимальный элемент
    int maxVal = INT_MIN;
    for (int i = 0; i < n; i++) {
        if (a[i] > maxVal) {
            maxVal = a[i];
        }
    }

    // Считаем, сколько раз встречается максимум
    int countMax = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == maxVal) {
            countMax++;
        }
    }

    // Вставляем X перед каждым максимумом (с конца)
    int newSize = n + countMax;
    int j = newSize - 1;
    for (int i = n - 1; i >= 0; i--) {
        a[j] = a[i];
        j--;
        if (a[i] == maxVal) {
            a[j] = X;
            j--;
        }
    }

    cout << "Массив после вставки X перед каждым максимумом:\n";
    for (int i = 0; i < newSize; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    delete[] a;
    return 0;
}