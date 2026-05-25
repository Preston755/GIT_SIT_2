#include <iostream>
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

    int X;
    cout << "Введите X: ";
    cin >> X;

    // Удаляем элементы, кратные X
    int index = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] % X != 0) {
            a[index] = a[i];
            index++;
        }
    }

    cout << "Массив после удаления элементов, кратных " << X << ":\n";
    for (int i = 0; i < index; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    delete[] a;
    return 0;
}