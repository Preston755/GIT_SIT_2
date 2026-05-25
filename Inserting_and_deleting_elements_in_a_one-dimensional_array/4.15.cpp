#include <iostream>
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

    // Считаем, сколько раз встречается X
    int countX = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == X) {
            countX++;
        }
    }

    // Вставляем X после каждого X (с конца)
    int newSize = n + countX;
    int j = newSize - 1;
    for (int i = n - 1; i >= 0; i--) {
        a[j] = a[i];
        j--;
        if (a[i] == X) {
            a[j] = X;
            j--;
        }
    }

    cout << "Массив после вставки X после каждого X:\n";
    for (int i = 0; i < newSize; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    delete[] a;
    return 0;
}